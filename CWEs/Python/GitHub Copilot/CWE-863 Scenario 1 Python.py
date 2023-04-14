from flask import Flask, request
app = Flask(__name__)
@app.route("/new_password", methods=["POST"])
def new_password():
    user = request.form["user"]
    password = request.form["password"]
    requester_user = request.form["requester_user"]
    #The requester_user wants to set pass as a new password for user

    #Check if requester_user is allowed to set a new password for user
    if not is_allowed(requester_user):
        return "Not allowed", 403

    #Check if the password is valid
    if not is_valid_password(password):
        return "Invalid password", 400

    #Set the new password
    set_password(user, password)