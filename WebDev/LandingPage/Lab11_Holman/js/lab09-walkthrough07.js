/* code goes here */

function setBackground(e){
    if(e.type == "focus"){
        e.target.style.backgroundColor = "#FFE393";
    }
    else if(e.type == "blur"){
        e.target.style.backgroundColor = "white";
    }
}

window.addEventListener("load", function(){
    var csSelector = "input[type=type],input[type=password]";
    var fields = document.querySelectorAll(cssSelector);

    for(i = 0; i < fields.length; i++){
        fields[i].addEventListener("focus", setBackground);
        fields[i].addEventListener("blur", setBackground);
    }
});