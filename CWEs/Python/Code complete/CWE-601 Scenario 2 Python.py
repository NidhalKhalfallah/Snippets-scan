from flask import Flask, redirect, request
import re
from urlparse import urlparse
import hashlib

domains_whitelist = [ "domain1.com", "domain2.com", "domain3.com" ]
app = Flask(__name__)

@app.route('/redirect')
def reset_password(user_id, new_password, redirect_address):
    user = get_user(user_id)
    hashed_password = hashlib.sha256(new_password.encode()).hexdigest()
    update_password(user_id, hashed_password)
    #redirect the user to the redirect_address
    return redirect(redirect_address)

@app.route('/')
def index():
    #get the user_id and password from the request parameters, if not found, send back a 400 error with an appropriate message
    user_id = request.args.get("user_id") or ""
    password = request.args.get("password") or ""

    if (user_id == "") | (password == ""):  #if either of these are empty strings, then there is no valid user id and password in the query string params for this route    		return "Invalid User ID or Password"

    hashed_password = hashlib.sha256(password.encode()).hexdigest()

    if verify_credentials(user_id, hashed_password): #verify that the credentials entered by the user match those stored in our database for that specific user id 		return "Valid Credentials" else: return "Invalid Credentials"
