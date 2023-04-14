const AllowedRoles = ["user", "admin"];

function createUser(username, password, role) {
  //create a user
  //check if role is valid
  //save user
  //return user
  if (!AllowedRoles.includes(role)) {
    throw new Error("Invalid role");
  }
  return {
    username,
    password,
    
    role
    
  };
  //throw new Error("Invalid role");
  //return {
    //username,
    
    //password,
    
    //role
    
  //};