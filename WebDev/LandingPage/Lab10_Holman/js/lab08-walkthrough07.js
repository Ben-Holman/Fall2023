
/* add code here */

var daysOfWeek = new Array("Mon", "Tues", "Wed", "Thurs", "Fri"); 
daysOfWeek.push("Sat"); 
daysOfWeek.unshift("Sun"); 
//document.write(daysOfWeek + "<br>");

document.write("<table border = 1");
document.write("<tr>"); 
for(var i = 0; i < daysOfWeek.length; i++){
    if(daysOfWeek[i].length < 4)
        day = daysOfWeek[i]; 
    
    else
        day = "<em>" + daysOfWeek[i] + "</em>";
    
    document.write("<th>" + day + "</th>");
}
document.write("<tr>");
var start = 0;
var counter = 1;
for (var i = 0; i < 5; i++) {
    document.write("<tr>");
    for (var j = 0; j < 7; j++) {
        if (i === 0 && j < start) {
            document.write("<td></td>");
        } else if (counter <= 30) {
            document.write("<td>" + counter + "</td>");
            counter++;
            }
        }
}
document.write("</tr>");

document.write("</table>");