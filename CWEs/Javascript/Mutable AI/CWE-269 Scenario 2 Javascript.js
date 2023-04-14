const AllowedRoles = ["user", "admin"];

function createUser(username, password, role) {
  //create a user
  if (AllowedRoles.includes(role)) {
    return {username, password, role};
  } else {
    throw new Error("Invalid role");
  }
}