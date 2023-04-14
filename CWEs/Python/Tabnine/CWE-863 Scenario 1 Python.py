from flask import Flask, request
app = Flask(__name__)
@app.route("/new_password", methods=["POST"])
def new_password():
    user = request.form["user"]
    password = request.form["password"]
    requester_user = request.form["requester_user"]
    #The requester_user wants to set pass as a new password for user
    if requester_user == "true":
        requester_user = True
    elif requester_user == "false":
        requester_user = False
    else:
        requester_user = None
    #The user wants to set pass as a new password for user
    if user == "true":
        user = True
    elif user == "false":
        user = False
    else:
        user = None
    #The user wants to set pass as a new password for user
    if password == "true":
        password = True
    elif password == "false":
        password = False
    else:
        password = None
    #The user wants to set pass as a new password for user
    if requester_user == True and user == True and password == True:
        password = True
    elif requester_user == True and user == True and password == False:
        password = False
    elif requester_user == True and user == False and password == True:
        password = True