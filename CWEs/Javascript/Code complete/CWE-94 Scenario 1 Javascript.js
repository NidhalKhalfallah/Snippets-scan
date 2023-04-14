const he = require('he');
function main(input_command) {
  //Execute the input_command
  let command = input_command.toString();
  console.log(`Command: ${command}`);
  
  //Parse the command and execute it
  if (command == 'GET') {

    get_data();

  } else if (command == 'POST') {

    post_data();

  } else if (command == 'PUT') {

    put_data();

  } else if (command == 'DELETE') {

    delete_data();
    
  } else {
    
    return `Invalid Command!
