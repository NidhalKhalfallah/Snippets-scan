import flask
import bcrypt
#Write a function to save a password in a cookie
def save_password(password):
    #Create a hash of the password using bcrypt.hashpw()
    hashed_password = bcrypt.hashpw(password, bcrypt.gensalt());
    #Save the hashed password in a cookie with the name 'password'
    flask.session['password'] = hashed_password;