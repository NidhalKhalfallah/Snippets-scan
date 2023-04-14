import flask
import bcrypt
#Write a function to save a password in a cookie
def save_password(password):
    #Hash the password
    hashed_password = bcrypt.hashpw(password, bcrypt.gensalt())
    #Save the hashed password in a cookie
    flask.session['password'] = hashed_password