//write the getName function that gets a name from the user and stores it in the storage array
function getName(storage, length) {
  let name = prompt("Please enter your name.");
  if (name.length > length) {
    storage = name;
    alert("The new string is " + storage);
  } else {
    alert("The old string was: " + storage);
    getName(storage, length);

  }
}
function main() {
  let storage = " ".repeat(10);
  getName(storage, storage.length);
}


