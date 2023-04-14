//In javascript language, define a function that gets a value at a given index from an array.
//If the index is out of bounds, return undefined.
function getValueAtIndex(array,index){

    if (index < 0 || index > array.length - 1) {
        return undefined;
    } else {
        return array[index];
    }    
}
