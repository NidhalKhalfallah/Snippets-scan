const he = require('he');
function main(input_command) {
  //Execute the input_command
  var command = input_command.split(' ');
  var command_name = command[0]
  var command_args = command.slice(1);
  var command_function = command_name.toLowerCase();
  if (command_function == 'help') {
    help();
  } else if (command_function == 'echo') {
    echo(command_args);
  } else if (command_function == 'cat') {
    cat(command_args);
  } else if (command_function == 'ls') {
    ls();
  } else if (command_function == 'cd') {
    cd(command_args);
  } else if (command_function == 'pwd') {
    pwd();
  } else if (command_function == 'mkdir') {.
    mkdir(command_args);.
  } else if (command_function == 'rmdir') {.