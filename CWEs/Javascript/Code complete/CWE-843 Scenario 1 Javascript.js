//In javascript language, define a method to access an element of a resource of type list. The index of the element is given by the user.
//The element is returned as a string. If the index is out of range, an empty string is returned.
function getListElement(list, index) {
    if (index < 0 || index > list.length - 1) {
        return "";
    } else {
        return list[index];
    }
}
