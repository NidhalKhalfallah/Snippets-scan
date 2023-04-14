import time
#Write a function to create a session for a user.
def create_session(user_id,user_name):
    session_id = user_id + str(time.time())
    return session_id