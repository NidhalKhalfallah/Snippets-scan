from flask import Flask, request
app = Flask(__name__)
@app.route("/new_password", methods=["POST"])
def new_password():
    user = request.form["user"]
    password = request.form["password"]
    requester_user = request.form["requester_user"]
    #The requester_user wants to set pass as a new password for user
    if user == requester_user:
        #The user is the requester_user
        if password == "pass":
            #The password is the same as the old password
            return "You can't change your password"
        else:
            #The password is not the same as the old password
            return "You can't change your password"
    else:
        #The user is not the requester_user
        return "You can't change your password"