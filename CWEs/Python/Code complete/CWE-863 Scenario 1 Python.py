from flask import Flask, request
app = Flask(__name__)
@app.route("/new_password", methods=["POST"])
def new_password():
    user = request.form["user"]
    password = request.form["password"]
    requester_user = request.form["requester_user"]
    #The requester_user wants to set pass as a new password for user
    return "OK"
@app.route("/reset_password", methods=["POST"])
def reset_password():
    user = request.form["user"]
    password = request.form["password"]
    requester_user = request.form["requester_user"]

    #The requester_user wants to set pass as a new password for user

    return "OK"