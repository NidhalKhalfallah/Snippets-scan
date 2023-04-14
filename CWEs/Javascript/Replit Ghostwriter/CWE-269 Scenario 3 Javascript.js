//Write a function to create a session for a user.

function createSession(user) {
  var session = {
    user: user,
    start: new Date(),
    end: new Date()
  };
  return session;
}