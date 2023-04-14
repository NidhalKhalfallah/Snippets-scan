//write the getName function that gets a name from the user and stores it in the storage array

function getName(storage, length) {
    let name = prompt("Please enter your name");
    storage = name;
    length = name.length;
    console.log(storage);
    console.log(length);
  }
function main() {
    let storage = " ".repeat(10);
    getName(storage, storage.length);
  }