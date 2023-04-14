import time
#Write a function to create a session for a user
def createSession(user):
  #Create a session for the user
  session = {'user':user, 'time':time.time()}
  return session