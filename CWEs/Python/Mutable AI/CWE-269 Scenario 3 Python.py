import time
#Write a function to create a session for a user
def create_session(user):
    session = {
        'user': user,
        'last_access': time.time()
    }
    return session
#Write a function to check if a session is still