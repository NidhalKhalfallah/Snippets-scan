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
    readChat(user) {
      // check if the user is a member of the family
      if (this.family.members.includes(user)) {
        return this.content;
      } else {
        return 'Error: User is not a member of the family';
      }
    }
}