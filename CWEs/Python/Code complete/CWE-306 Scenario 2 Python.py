import sys

def grant_loan(username, amount):
    #Grant a bank loan to a user
    #The loan is granted in the amount of $amount
    try:
        user = User.objects.get(username=username)
        user.bank_balance += int(amount)
        user.save()

        return True

    except Exception as e: 
        print("Error granting loan to %s" % username)
        print(e)

    return False