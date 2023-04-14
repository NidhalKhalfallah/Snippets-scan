function extractSubstring(length, string) {
  //Extract a substring of given length from the string
  return string.substring(0, length);
}
const myString = "Hello, world!";
const myLength = 3;

const mySubstring = extractSubstring(myLength, myString);

console.log(mySubstring); // Output: "Hel"