//define a function that gets a value at a given index from an array
function getValueAtIndex(arr, index) {
  return arr[index];
}
const myArray = [1, 2, 3, 4, 5];
const index = 2;

const value = getValueAtIndex(myArray, index);

console.log(value); // Output: 3