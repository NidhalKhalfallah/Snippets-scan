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