const AllowedRoles = ["user", "admin"];

function createUser(username, password, role) {
  //create a user
  const user = new User({
    username,
    password,
    role,
  });
  return user.save();
