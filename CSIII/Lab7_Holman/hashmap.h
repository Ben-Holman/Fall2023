// implementation basic hashmap (unordered container)
// Wayne Cheng: adapted from Proc C++
// 4/10/2018

#include <cstddef>
#include <utility>
#include <functional>
#include <vector>
#include <list>

using std::vector;
using std::list;
using std::pair;
using std::make_pair;

//////////////////////////////////////////
// hash function implemented as a class
//////////////////////////////////////////


// any Hash Class must provide 
// two methods: hash() and numBuckets().
template <typename T>
class DefaultHash {
public:
   DefaultHash(size_t numBuckets = defaultNumBuckets);
   size_t hash(const T& key) const;
   size_t numBuckets() const { return numBuckets_; }

private:
   static const size_t defaultNumBuckets = 101; // default number of buckets in the hash
   size_t numBuckets_;
};


template <typename T>
DefaultHash<T>::DefaultHash(size_t numBuckets):
   // if incorrect num of buckets, make default
   numBuckets_(numBuckets > 0? numBuckets : defaultNumBuckets)
   {}


// uses the division method for hashing.
// treats the key as a sequence of bytes, sums the ASCII
// values of the bytes, and mods the total by the number
// of buckets.
template <typename T>
size_t DefaultHash<T>::hash(const T& key) const {
   size_t res = 0;
   for (size_t i = 0; i < sizeof(key); ++i) {
      const unsigned char b = *(reinterpret_cast<const unsigned char *>(&key) + i);
      res += b;
   }
   return res % numBuckets_;
}

////////////////////////////////////////////////
// container class
////////////////////////////////////////////////

template <typename Key, typename Value, 
          typename Compare = std::equal_to<Key>,
          typename Hash = DefaultHash<Key>>
class hashmap{

public:
   typedef pair<const Key, Value> Element;

   // constructor
   // invokes constructors for comparison and hash objects
   hashmap(const Compare& comp = Compare(), 
	   const Hash& hash = Hash());

   // destructor, copy constructor, move constructor,
   // copy assignment operator and move assignment operator
   ~hashmap();
   hashmap(const hashmap<Key, Value, Compare, Hash>& src);
   hashmap(hashmap<Key, Value, Compare, Hash>&& src);        // C++11

   hashmap<Key, Value, Compare, Hash>& operator=(const hashmap<
					   Key, Value, Compare, Hash> rhs);
   hashmap<Key, Value, Compare, Hash>& operator=(hashmap<
					   Key, Value, Compare, Hash>&& rhs); 
                                           // C++11
   // swap with usual semantics
   void swap(hashmap<Key, Value, Compare, Hash> &rhs);

   // inserts the key/value pair x
   void insert(const Element& x);

   // removes the Element with key x, if it exists
   void erase(const Key& x);

   // returns a pointer to the element with key x
   // returns nullptr if no element with this key
   Element* find(const Key& x);

   // finds the element with key x, inserts an
   // element with that key if none exists yet. Returns a reference to
   // the value corresponding to that key.
   Value& operator[] (const Key& x);

private:

   // helper function for various searches
   typename list<Element>::iterator
        findElement(const Key& x, 
		    const size_t bucket);
   size_t size_;
   Compare comp_;
   Hash hash_;

   // hash contents: vector buckets
   // each bucket is a list containing key->value pairs
   vector<list<Element>> elems_;

};


//
// constructors/destructors
//

// Construct elems_ with the number of buckets.
template <typename Key, typename Value, typename Compare, typename Hash>
   hashmap<Key, Value, Compare, Hash>::hashmap(
   const Compare& comp, const Hash& hash):
   size_(0), comp_(comp), hash_(hash) {
      elems_ = vector<list<Element>>(hash_.numBuckets());
}

template <typename Key, typename Value, typename Compare, typename Hash>
      hashmap<Key, Value, Compare, Hash>::~hashmap() {}

template <typename Key, typename Value, typename Compare, typename Hash>
   hashmap<Key, Value, Compare, Hash>::
   hashmap(const hashmap< Key, Value, Compare, Hash>& src) :
   size_(src.size_), comp_(src.comp_), hash_(src.hash_), elems_(src.elems_){}

// swap function
template <typename Key, typename Value, typename Compare, typename Hash>
   void hashmap<Key, Value, Compare, Hash>::swap(hashmap<Key, Value, Compare, Hash> &rhs){
   std::swap(elems_, rhs.elems_);
   std::swap(size_, rhs.size_);
   std::swap(comp_, rhs.comp_);
   std::swap(hash_, rhs.hash_);
}


// C++11 move constructor
template <typename Key, typename Value, typename Compare, typename Hash>
    hashmap<Key, Value, Compare, Hash>::hashmap(hashmap<Key, Value, Compare, Hash>&& src) {
   elems_ = std::move(src.elems_);
   size_ = src.size_; src.size_ =0;
   comp_ = src.comp_; 
   hash_ = src.hash_;
}

// overloaded assingment, copy-and-swap implementation
template <typename Key, typename Value, typename Compare, typename Hash>
   hashmap<Key, Value, Compare, Hash>& hashmap<Key, Value, Compare, Hash>::operator=(
   hashmap<Key, Value, Compare, Hash> rhs) {
   swap(rhs);
   return *this;
}

// C++11 move assignment operator
template <typename Key, typename Value, typename Compare, typename Hash>
   hashmap<Key, Value, Compare, Hash>& hashmap<Key, Value, Compare, Hash>::operator=(
	  hashmap<Key, Value, Compare, Hash>&& rhs) {
      // check for self-assignment
      if (this != &rhs) {
	 // move ownership
	 elems_ = std::move(rhs.elems_);
	 size_ = rhs.size_;
	 rhs.size_ = 0;
	 comp_ = rhs.comp_;
	 hash_ = rhs.hash_;
      }
      return *this;
   }


//
// rest of container member functions
// 

// helper function
template <typename Key, typename Value, 
          typename Compare, typename Hash>

   typename list<pair<const Key, Value>>::iterator
   hashmap<Key, Value, Compare, Hash>::findElement(const Key& x, size_t bucket){

   // look for the key in the bucket
   for (auto it =  elems_[bucket].begin();
  	     it != elems_[bucket].end(); ++it)
      if (comp_(it->first, x))
	 return it;

   return elems_[bucket].end(); // element not found
}


template <typename Key, typename Value, typename Compare, typename Hash>
   typename hashmap<Key, Value, Compare, Hash>::Element* // return value type
hashmap<Key, Value, Compare, Hash>::find(const Key& x) {

   size_t bucket = hash_.hash(x);
   auto it=findElement(x, bucket);    // use the findElement() helper   

   if (it == elems_[bucket].end())
      // we didn't find the element -- return nullptr
      return nullptr;

   // we found the element. Return a pointer to it.
   return &(*it); // dereference the iterator to list 
                  // then take the address of list element
}


template <typename Key, typename Value, typename Compare, typename Hash>
void hashmap<Key, Value, Compare, Hash>::insert(const Element& x) {

   size_t bucket = hash_.hash(x.first);   
   auto it = findElement(x.first, bucket);    // try to find the element

   if (it != elems_[bucket].end()) {
      return;    // the element already exists
   } else {
      // didn't find the element, insert a new one.
      ++size_;
      elems_[bucket].push_back(x);
   }
}


template <typename Key, typename Value, typename Compare, typename Hash>
Value& hashmap<Key, Value, Compare, Hash>::operator[] (const Key& x) {

   // try to find the element. If it doesn't exist, add a new element.

   Element* found = find(x);
   if (found == nullptr) { // if key not found, create new element with empty value
      insert(make_pair(x, 
		       Value())); // calling default constructor on Value
      found = find(x); // inefficient but avoids code duplication
   }
   return found->second;
}

template <typename Key, typename Value, typename Compare, typename Hash>
void hashmap<Key, Value, Compare, Hash>::erase(const Key& x) {

   size_t bucket = hash_.hash(x);
   auto it = findElement(x, bucket);     // first, try to find the element

   if (it != elems_[bucket].end()) {    // the element exists, erase it
      elems_[bucket].erase(it);
      --size_;
   }
}
