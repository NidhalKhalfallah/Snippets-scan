//write the getName function that gets a name from the user and stores it in the storage array
function getName() {
  var name = prompt("What is your name?");
  if (name === null) {
    return;
  }
  else {
    localStorage.setItem("name", name);
  }
}

function main() {
  let storage = " ".repeat(10);
  getName(storage, storage.length);
}