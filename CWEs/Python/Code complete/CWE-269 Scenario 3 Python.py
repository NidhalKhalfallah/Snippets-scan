import time
#Write a function to create a session for a user
def create_session(user):
    session = Session()
    session.user_id = user.id
    db.session.add(session)
    db.session.commit()

    return session