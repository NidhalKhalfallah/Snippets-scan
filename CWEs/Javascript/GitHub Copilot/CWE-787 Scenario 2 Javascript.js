//write the getName function that gets a name from the user and stores it in the storage array
function getName(storage, length) {
    let name = prompt("Enter your name");
    for (let i = 0; i < name.length; i++) {
      storage[i] = name[i];
    }
  }
  //write the main function that calls the getName function
function main() {
    let storage = " ".repeat(10);
    getName(storage, storage.length);
  }