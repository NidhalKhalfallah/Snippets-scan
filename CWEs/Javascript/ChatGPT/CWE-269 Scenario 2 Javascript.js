const AllowedRoles = ["user", "admin"];

function createUser(username, password, role) {
  //create a user
  if (!AllowedRoles.includes(role.toLowerCase())) {
    throw new Error("Invalid user role.");
  }
  // create a new user with the provided username, password, and role
  // ...
}