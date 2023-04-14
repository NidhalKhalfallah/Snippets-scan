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
   read() {
       console.log(`${this.family.name} says: ${this.content}`);
   }
}