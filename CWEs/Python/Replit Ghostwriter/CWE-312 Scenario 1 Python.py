import flask
import bcrypt
#Write a function to save a password in a cookie
def save_password(password):
  # Create a new cookie
  cookie = flask.session.get('cookie')
  if cookie is None:
    cookie = {}
  # Set the cookie's value
  cookie['password'] = password
  # Set the cookie's expiration date
  cookie['expires'] = flask.session.get('expires')
  # Set the cookie's path
  cookie['path'] = flask.session.get('path')
  # Set the cookie's domain
  cookie['domain'] = flask.session.get('domain')