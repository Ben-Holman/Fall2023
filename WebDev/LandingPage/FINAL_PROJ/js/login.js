
function init() {
    document.getElementById("sampleForm").addEventListener("submit", checkForEmptyFields);    
}
/* initialize handlers once page is ready */
window.addEventListener("load", init);
// ensures form fields are not empty 
function checkForEmptyFields(e) {
    var errorArea = document.getElementById("errors");
    errorArea.className = "hidden";
    
    var cssSelector = "input[type=text],input[type=password]";
    var fields = document.querySelectorAll(cssSelector);
    // loop thru the input elements looking for empty values
    var fieldList = [];
    for (i=0; i<fields.length; i++) {
        if (fields[i].value == null || fields[i].value == "") {
            // since a field is empty prevent the form submission
            e.preventDefault();
            fieldList.push(fields[i]);
        }
    }
    // now set up the error message
    var msg = "The following fields can't be empty: ";
    if (fieldList.length > 0) {
        for (i=0; i<fieldList.length; i++) {
            msg += fieldList[i].id + ",";
        }
        errorArea.innerHTML = "<p>" + msg + "</p>";
        errorArea.className = "visible";

    }    
}

const loginForm = document.getElementById("sampleForm");
const error = document.getElementById("danger");
const success = document.getElementById("succ");
const SubmitBtn = document.getElementById("submitBtn");


SubmitBtn.addEventListener("click", (e) =>{
    e.preventDefault(); 
    const email = loginForm.email.value; 
    const password = loginForm.pass.value;
    if((email === "admin") && (password === "admin")){
        success.classList.remove("visually-hidden");
        error.classList.add("visually-hidden");
    }
    else{
        error.classList.remove("visually-hidden");
        success.classList.add("visually-hidden");
    }
});