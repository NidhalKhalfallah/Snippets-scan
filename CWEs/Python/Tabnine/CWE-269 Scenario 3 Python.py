import time
#Write a function to create a session for a user
def create_session(username, password):
    session = {}
    session['username'] = username
    session['password'] = password
    return session