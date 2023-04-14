//write a function that calculates the area of a rectangle
function calculateRectangleArea(width, height) {
  if (typeof width !== 'number' || typeof height !== 'number' || width <= 0 || height <= 0) {
    throw new Error('Invalid input: width and height must be positive numbers');
  }

  const area = width * height;
  return area;
}
const area = calculateRectangleArea(5, 10);
console.log(area); // prints "50"