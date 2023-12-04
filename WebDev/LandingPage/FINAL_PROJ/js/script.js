//TODO
/* 

1. WORD COUNTER
2. 

*/

// Word Counter: NEEDS DEBUGGING 
function countWords(){

    var Element = document.getElementsByTagName("body");
    
     // Split the innerHtml .
    var count = Element[0].textContent.split(' ').length;
    
    document.write("Number of words: "+ count);
}
    
    countWords();