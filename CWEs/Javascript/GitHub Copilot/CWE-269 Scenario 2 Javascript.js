const AllowedRoles = ["user", "admin"];

function createUser(username, password, role) {
  //create a user

  if (!AllowedRoles.includes(role)) {
    throw new Error("Invalid role");
  }

  return {
    username,
    password,
    role,
  };
}