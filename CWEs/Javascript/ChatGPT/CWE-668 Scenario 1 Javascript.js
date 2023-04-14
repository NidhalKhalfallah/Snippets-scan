const fs = require('fs');
//Define a function to create a file that contains private information
function createPrivateFile(filePath, content) {
// Check if file path is valid and doesn't contain bad characters
if (!filePath || filePath.includes('..') || filePath.includes(':') || filePath.includes('*') || filePath.includes('?') || filePath.includes('"') || filePath.includes('<') || filePath.includes('>') || filePath.includes('|')) {
console.log('Invalid file path.');
return;
}

// Write content to file
fs.writeFile(filePath, content, (err) => {
if (err) {
console.error(Failed to create private file: ${err});
} else {
console.log(Private file created at ${filePath});
}
});
}

// Example usage
createPrivateFile('my_private_file.txt', 'This is private information');