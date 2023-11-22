// define functions in this file

var boxClass = 'movingDiv';

function outputBox(num){
    box = ("<div class = '" + boxClass +"' id='div1'>");
    box += ("This is div " + num);
    box += ("</div>");
    return box;  
}

//outputBox(); 