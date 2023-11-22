/* code goes here */

var order = {} 
/*
order.product = "Self Portrait in a Straw Hat"; 
order.price = 15.0; 
order.quantity = 2; 
order.total = function(){
    return this.price + this.quantity; 
};


order["product"] = "Self Portrait in a Straw Hat"; 
order["price"] = 15.0; 
order["quantity"] = 2; 
order["total"] = function(){
    return this.price + this.quantity; 
};


var order = {
    product: "Self Portrait in a Straw Hat",
    price: 15.0, 
    quantity: 2, 
    total: function(){
    return this.price + this.quantity; 
}
}


function order(product, price, quantity) {
    this.product = product;
    this.price = price;
    this.quantity = quantity;
    this.total = function() { 
        return this.price * this.quantity; 
    },
    
    this.output = function() {
        document.write("<p>Product=" + this.product);
        document.write("<br>Price=" + this.price);
        document.write("<br>Quantity=" + this.quantity);
        document.write("<br>Total=" + this.total());
    }
}



document.write("Product = " + order.product);
document.write("<br>Price = " + order.price);
document.write("<br>Quantity = " + order.quantity);
document.write("<br>Total = " + order.total());


var example1  = new order("Self Portrait in a Straw Hat", 15, 2);
var example2  = new order("Untitled #23", 10, 4);

example1.output(); 
example2.output();

document.write("<p>Product = " + example1.product); 
document.write("<br>Price = " + example1.price); 
document.write("<br>Quantity = " + example1.quantity); 
document.write("<br>Total = " + example1.total()); 

document.write("<p>Product = " + example2.product); 
document.write("<br>Price = " + example2.price); 
document.write("<br>Quantity = " + example2.quantity); 
document.write("<br>Total = " + example2.total());
*/

function order(product, price, quantity) {
    this.product = product;
    this.price = price;
    this.quantity = quantity;
    this.total = function() { return this.price * this.quantity; },
    
    this.output = function() {
        document.write("<p>Product=" + this.product);
        document.write("<br>Price=" + this.price);
        document.write("<br>Quantity=" + this.quantity);
        document.write("<br>Total=" + this.total());
    }  
}

var example1  = new order("Self Portrait in a Straw Hat", 15, 2);
var example2  = new order("Untitled #23", 10, 4);

example1.output();
example2.output();