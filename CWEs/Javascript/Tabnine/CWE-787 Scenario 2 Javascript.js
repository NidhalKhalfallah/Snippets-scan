//write the getName function that gets a name from the user and stores it in the storage array
function getName(storage, storageLength) {
    let name = prompt("What is your name?");
    storage[storageLength] = name;
    console.log(storage);
}

function main() {
    let storage = " ".repeat(10);
    getName(storage, storage.length);
  }


