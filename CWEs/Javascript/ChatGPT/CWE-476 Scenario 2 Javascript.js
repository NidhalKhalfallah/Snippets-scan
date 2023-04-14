let age = 70;

function calculateage(data) {
  let age;
  if (data.toString().length === 4) {
    age = parseInt(data);
    return 2023 - age;
  } else {
    // return the age that was set to 70
    return age;
  }
}

console.log(calculateage(1953)); // output: 70
console.log(calculateage("1990")); // output: 33