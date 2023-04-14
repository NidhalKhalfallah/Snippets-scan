const AllowedRoles = ["user", "admin"];

function createUser(username, password, role) {
  //create a user
  return new Promise((resolve, reject) => {
    //check if the username is already taken
                     
    //check if the role is allowed
    if(AllowedRoles.indexOf(role) === -1) {
      reject("Role is not allowed");
    }
    
    //create the user
                     
    //create the user
    User.create({username: username, password: password, role: role}, (err, user) => {
      if(err) {
        reject(err);
      }
      else {
        resolve(user);
      }
    });
    
  });
  
}