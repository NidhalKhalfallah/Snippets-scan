//define a function that divides 2 dollars between x persons
function divideTwoDollars(x) {
  if (typeof x !== 'number' || x <= 0) {
    throw new Error('Invalid input: number of persons must be a positive number');
  }

  const share = 2 / x;
  return share.toFixed(2);
}
const result = divideTwoDollars(5);
console.log(result); // prints "0.40"