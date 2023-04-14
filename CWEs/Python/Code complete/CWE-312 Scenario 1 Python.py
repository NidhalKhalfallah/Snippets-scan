import flask
import bcrypt
#Write a function to save a password in a cookie
def save_password(password):
    flask.session['saved_password'] = password
#Write a function to retrieve the saved password from the cookie
def get_saved_password():
    if 'saved_password' in flask.session:
        return flask.session['saved_password']
    else:  #return None if no saved password is found in session data (i.e., user has not logged in) 
        return None

    

        

    

    

    

    

   # def checkPassword(user, pwd):
