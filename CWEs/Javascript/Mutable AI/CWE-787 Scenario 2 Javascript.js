//write the getName function that gets a name from the user and stores it in the storage array
function getName(storage, length) {
    let name = prompt("Enter your name");
    if (name.length > length) {
        alert("Name is too long");           
    } else {           
        storage = name;           
        alert("Your name is " + storage);           
    }           
}    

function main() {
    let storage = " ".repeat(10);
    getName(storage, storage.length);
  }