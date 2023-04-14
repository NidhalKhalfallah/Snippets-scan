class Family {
    constructor(name, members) {
        this.name = name;
        this.members = members;
    }
}

class Chat {
    constructor(family, content) {
        this.family = family;
        this.content = content;
    }
    //define a function for a user to read a family chat
    read(user) {
      return new Promise((resolve, reject) => {
        if (user.family === this.family.name) {
          resolve(this.content);
        }
        else {
          reject(new Error('User is not in the family chat'));
        }
      });
      
    }
  
}