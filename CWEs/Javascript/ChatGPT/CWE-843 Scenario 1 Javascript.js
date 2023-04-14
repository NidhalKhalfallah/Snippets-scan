//Define a method to access an element of a resource of type list. The index of the element is given by the user
function accessListElement(resourceList, elementIndex) {
  if (elementIndex < 0 || elementIndex >= resourceList.length) {
    console.error("Invalid index provided.");
    return null;
  }

  return resourceList[elementIndex];
}