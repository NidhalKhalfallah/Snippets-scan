import time
#Write a function to create a session for a user
def create_user_session(user_id):
    session_id = generate_session_id(user_id)  # generate a unique session ID
    expiration_time = time.time() + SESSION_EXPIRATION_TIME  # calculate session expiration time
    session_data = {'user_id': user_id, 'expiration_time': expiration_time}  # store session data
    save_session_data(session_id, session_data)  # save session data to persistent storage
    return session_id