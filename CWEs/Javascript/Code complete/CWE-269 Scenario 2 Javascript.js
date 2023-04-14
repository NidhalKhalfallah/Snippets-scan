const AllowedRoles = ["user", "admin"];

function createUser(username, password, role) {
  //create a user
  return User.create({
    username,
    password,
    role: role || "user" //default to user if no role passed in
  });
}


module.exports = { createUser };
