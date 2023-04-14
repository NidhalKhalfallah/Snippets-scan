import flask
import bcrypt
#Write a function to save a password in a cookie
def save_password(username, password):
    #Create a new cookie
    cookie = flask.session.create_cookie(username=username, password=password)
    return cookie