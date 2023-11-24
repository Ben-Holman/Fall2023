// making sure that duplicate and sick animals are removed from all enclosures in a zoo 
// demonstrates the usage of STL algorithms adapted from Pro C++ 
// Wayne Cheng
// 10/2/2015 

#include <iostream> 
#include <map>
#include <list> 
using namespace std; 

// this is similar to typedef 
using EnclosurePair = pair; 
using ZooMap = map; 

// removes duplicate and sick animals form ZooMap 
void auditEnclosures(ZooMap& animalsByEnclosure, const list& sickAnimals); 

// returns a set of duplicate animals 
set getDuplicates(const ZooMap& animalsByEnclosure); 

int main() 
{ 
	// initialize map ZooMap 
	animals = { { "Orange", { "aardvark", "lion", "buffalo", "wildcat", "lion", "eagle" } }, 
				{ "Green", { "elephant", "zebra", "aardvark", "bear", "alligator"} }, 
				{ "Yellow", { "goose", "alligator", "flamingo", "goose", } }, { "Blue", 
				{ "shark", "dolphin", "alligator", "turtle", "eagle", "penguin"} }, { "Red", 
				{ "deer", "duck", "wildcat", "lion" } } }; 
	
	list sickAnimals = { "buffalo", "wildcat", "eagle"}; 
	
	// local lambda expression to print a enclosure 
	auto printEnclosure = [](const EnclosurePair& enclosure) 
	{ 
		cout << enclosure.first << ":"; 
		for (auto& str : enclosure.second) 
		{ 
			cout << ' ' << str; 
		} 
		cout << endl; 
	}; 
	cout << "Before audit:" << endl; 
	for_each(animals.cbegin(), animals.cend(), printEnclosure); 
	cout << endl; 
	auditEnclosures(animals, sickAnimals); 
	cout << "After audit:" << endl; for_each(animals.cbegin(), animals.cend(), printEnclosure); 
	cout << endl; 
} 

// expects a map of string/list pairs keyed on enclosure names 
// and containing lists of all the animals in those enclosures 
// 
// removes from each list any name on the sickAnimals list and 
// any name that is found in any other enclosure 
void auditEnclosures(ZooMap& animalsByEnclosure, const list& sickAnimals) 
{ 
	// get all the duplicate names 
	set toRemove = getDuplicates(animalsByEnclosure); 
	
	// combine the duplicates and sick animals -- we want to remove names on both lists from 
	//all enclosures 
	toRemove.insert(sickAnimals.cbegin(), sickAnimals.cend()); 
	
	// Now remove all the names we need to remove using nested lambda expressions and the remove-erase-idiom 
	for_each(animalsByEnclosure.begin(), animalsByEnclosure.end(), [&toRemove](EnclosurePair& enclosure) 
	{ 
		auto it = remove_if(enclosure.second.begin(), enclosure.second.end(), [&toRemove](const string& name) 
		{ 
			return (toRemove.find(name) != toRemove.end()); 
		}); 
		enclosure.second.erase(it, enclosure.second.end()); 
	}
); 
} 

// returns a set of all animal names that appear in more than one list in the map 
// the implementation generates one large list of all the animal names from all the 
// lists in the map, sorts it, then finds all duplicates in the sorted list with adjacent_find() 
set getDuplicates(const ZooMap& animalsByEnclosure) 
{ 
	// Collect all the names from all the lists into one big list 
	list allNames; for (auto& enclosure : animalsByEnclosure) 
	{ 
		allNames.insert(allNames.end(), enclosure.second.begin(), enclosure.second.end()); 
	} 
	// sort the list -- use the list version, not the general algorithm, because the list version is faster 
	allNames.sort(); 
	
	// now it's sorted, all duplicate names will be next to each other. 
	// use adjacent_find() to find instances of two or more identical names 
	// next to each other. 
	// loop until adjacent_find() returns the end iterator. 
	set duplicates; 
	for(auto adj = allNames.cbegin(); adj != allNames.cend(); adj = adjacent_find(++adj, allNames.cend())) duplicates.insert(*adj);	 
	
	// note this is a set so multiple insertions 
	// of same element result in single element 
	return duplicates; 
	} 
