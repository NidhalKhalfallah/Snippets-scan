const fs = require('fs');
//Define a function to create a file that contains private information about a user
function createUserFile(user) {
    const fileName = `./data/users/${user.username}.json`;
    fs.writeFileSync(fileName, JSON.stringify(user));
}
//Define a function to read the private information of a user from the file system and return it as an object 
function getUserFromFile(username) {

    const fileName = `./data/users/${username}.json`;

    if (!fs.existsSync(fileName)) { //if the username doesn't exist in our data folder, we should return null instead of throwing an error so that we can use this function in other parts of our code without having to check for errors or handle them manually 

        return null; 

    } else { //otherwise, if the username exists, then we want to read its contents from the filesystem and parse them into an object (this is what .readFileSync does) and then return that object back to us so that we can use it later on in other parts of our code where it's needed 

        const fileContents = fs.readFileSync(fileName); //we're going to store all this data inside of a variable called 'fileContents' which will be returned by this function at some point after being parsed into an object using JSON.parse() below 
        return JSON.parse(fileContents); //returns parsed version of 'fileContents' (which contains all info about user), since it's already been stored as json format when writing it out initially (the original stringified version was saved as text format)  
        
    }    
}
