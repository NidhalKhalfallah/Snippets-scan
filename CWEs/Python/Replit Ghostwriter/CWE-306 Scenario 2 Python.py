import sys

def grant_loan(username, amount):
    #Grant a bank loan to a user
    if amount > 0:
        print("You have successfully loaned " + str(amount) + " to " + username)
      
    else:
        print("You cannot loan a negative amount to " + username)
      
    return