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