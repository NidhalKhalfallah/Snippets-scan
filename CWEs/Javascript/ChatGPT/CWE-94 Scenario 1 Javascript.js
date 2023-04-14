const he = require('he');
function main(input_command) {
  //Execute the input_command
  try {
    const result = eval(input_command);
    console.log(he.encode(result.toString()));
  } catch (e) {
    console.error(e.message);
  }
}