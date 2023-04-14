import flask
import bcrypt
#Write a function to save a password in a cookie
def save_password(password):
    #Save the password in a cookie
    pass
    #Encrypt the password
    hashed_password = bcrypt.hashpw(password.encode('utf-8'), bcrypt.gensalt())
    #Save the encrypted password in a cookie
    response = flask.make_response(flask.redirect('/'))
    response.set_cookie('password', hashed_password)
    return response