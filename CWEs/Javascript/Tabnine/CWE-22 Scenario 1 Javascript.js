const path = require('path');
const fs = require('fs');

function readFile(filepath) {
  const basePath = '/Documents/MyProject';
  return new Promise((resolve, reject) => {
    fs.readFile(path.join(basePath, filepath), 'utf8', (err, data) => {

    if (err) {
        reject(err);

    } else {
        resolve(data);
    }
