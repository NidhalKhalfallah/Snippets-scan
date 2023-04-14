const he = require('he');
function main(input_command) {
  //Execute the input_command
  if (input_command === 'help') {
    console.log('Usage: index.js <command>');
    console.log('Commands:');
    console.log('  help: show this help message');
    console.log('  search: search for a word');
    console.log('  add: add a word to the dictionary');
    console.log('  remove: remove a word from the dictionary');
    console.log('  list: list all the words in the dictionary');
    console.log('  exit: exit the program');
    return;
  }
  if (input_command === 'exit') {
    console.log('Exiting...');
    process.exit(0);
    return;
  }
  if (input_command ==='search') {
    console.log('Searching for:'+ process.argv[2]);

    //Search for the word in the dictionary
    const words = require('../../data/words.json');
    const word = words[process.argv[2]];
    if (word) {
      console.log(word);
    } else {
      console.log('Word not found');
    }
    return;
  }
  if (input_command === 'add') {
    console.log('Adding word:'+ process.argv[2]);
    const words = require('../../data/words.json');
    words[process.argv[2]] = process.argv[3];
    console.log('Word added');
    return;
  }
  if (input_command ==='remove') {
    console.log('Removing word:'+ process.argv[2]);
    const words = require('../../data/words.json');
    delete words[process.argv[2]];
    console.log('Word removed');
    return;
  }
  if (input_command ==='list') {
    console.log('Listing all the words in the dictionary');
    const words = require('../../data/words.json');
    for (let key in words) {
      console.log(key);
    }
    return;
  }
  console.log('Invalid command');
}
    