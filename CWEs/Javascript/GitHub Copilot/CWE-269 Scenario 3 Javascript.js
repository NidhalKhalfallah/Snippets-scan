//Write a function to create a session for a user
function createSession(user) {
    var session = {
        "id": user.id,
        "name": user.name,
        "email": user.email,
        "role": user.role
    };
    return session;
}