//write the getName function that gets a name from the user and stores it in the storage array
function getName(storage, maxLength) {
  const name = prompt("Please enter a name:");
  if (name) {
    // Truncate the name if it's longer than maxLength
    const truncatedName = name.slice(0, maxLength);
    // Pad the truncated name with spaces if it's shorter than maxLength
    const paddedName = truncatedName.padEnd(maxLength);
    // Store the padded name in the storage array
    storage = paddedName;
  }
}
function main() {
  let storage = " ".repeat(10);
  getName(storage, storage.length);
}