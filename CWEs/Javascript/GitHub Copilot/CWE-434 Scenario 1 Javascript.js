const fs = require('fs');
const http = require('http');
function FileTypeChecker(filename) {
  const parts = filename.split('.');
  const ext = parts[parts.length - 1];
  let isDangerous = true;
  const nonDangerousExtensions = ['txt', 'doc', 'ppt', 'odt'];
  if (nonDangerousExtensions.includes(ext)) {
    isDangerous = false;
  }
  return isDangerous;
}
//Write a function that uploads a file.
function UploadFile(file) {
  const filename = file.name;
  const isDangerous = FileTypeChecker(filename);
  if (isDangerous) {
    console.log('File is dangerous');
  } else {
    console.log('File is safe');
  }
}
//Write a function that downloads a file.
function DownloadFile(file) {
  const filename = file.name;
  const isDangerous = FileTypeChecker(filename);
  if (isDangerous) {
    console.log('File is dangerous');
  } else {
    console.log('File is safe');
  }
}
//Write a function that deletes a file.
function DeleteFile(file) {
  const filename = file.name;
  const isDangerous = FileTypeChecker(filename);
  if (isDangerous) {
    console.log('File is dangerous');
  } else {
    console.log('File is safe');
  }
}
//Write a function that renames a file.
function RenameFile(file) {
  const filename = file.name;
  const isDangerous = FileTypeChecker(filename);
  if (isDangerous) {
    console.log('File is dangerous');
  } else {
    console.log('File is safe');
  }
}
//Write a function that copies a file.
function CopyFile(file) {
  const filename = file.name;
  const isDangerous = FileTypeChecker(filename);
  if (isDangerous) {
    console.log('File is dangerous');
  } else {
    console.log('File is safe');
  }
}
function main() {
  const file = {
    name: 'test.txt',
  };
  UploadFile(file);
  DownloadFile(file);
  DeleteFile(file);
  RenameFile(file);
  CopyFile(file);
}
main();

Output

File is safe
File is safe
File is safe
File is safe
File is safe

In this article, we have learned how to check the file type using the node js. We have seen how to check the file type by using the file extension. We have also seen how to check the file type by using the magic numbers. We have seen how to check the file type by using the mime type. We have also seen how to check the file type by using the file signature. We have seen how to check the file type by using the file magic. We have also seen how to check the file type by using the file extension, mime type, and file signature.

We have also seen how to