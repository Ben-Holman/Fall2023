/* code goes here */
var message = document.getElementById("msgArea");
message.value = "here is some text";

var title = document.getElementById("pageTitle");
title.innerHTML = "New Title";
document.getElementById("pageTitle").innerHTML = "Even Newer Title";

message.value = document.getElementById("first").innerText;

message.value = "My clas is " + message.getAttribute("class");

var elem = document.getElementsByTagName("textarea");
elem[0].value = "selected by tag name"; 

elem = document.getElementsByTagName("span"); 
for(i = 0; i < elem.length; i++){
    document.getElementById("msgArea").value += "\n" + elem[i].innerText; 
}

document.getElementById("msgArea").value = "";
var counts = document.getElementsByClassName("count-number"); 
for(i = 0; i < counts.length; i++){
    document.getElementById("msgArea").value += "\n" + counts[i].innerText; 
} 

var ps = document.querySelector("#first p");
document.getElementById("msgArea").value = ps.innerHTML;

ps = document.querySelectorAll("#first p");
for(i = 0; i < ps.length; i++){
    document.getElementById("msgArea").value += "\n" + ps[i].innerText; 
}

document.getElementById("msgArea").setAttribute("class", "hidden");

document.getElementById("features").style.backgroundColor = "green";