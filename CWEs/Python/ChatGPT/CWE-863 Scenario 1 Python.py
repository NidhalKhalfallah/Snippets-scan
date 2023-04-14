from flask import Flask, request
app = Flask(__name__)
user_credentials = {
    "user1": "password1",
    "user2": "password2"
}
@app.route("/new_password", methods=["POST"])
def new_password():
    user = request.form["user"]
    password = request.form["password"]
    requester_user = request.form["requester_user"]
    #The requester_user wants to set pass as a new password for user
    if requester_user == "admin":
        user_credentials[user] = password
        return "Password updated successfully"
    else:
        return "Unauthorized", 401