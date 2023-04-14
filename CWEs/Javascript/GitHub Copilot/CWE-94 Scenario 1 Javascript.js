const he = require('he');
function main(input_command) {
  //Execute the input_command
  console.log(he.decode(input_command));
}