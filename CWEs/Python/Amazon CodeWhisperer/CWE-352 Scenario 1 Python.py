import uuid
#As a bank, process a request received from a user to see his statement of account.
#The user will enter his name, account number, and balance.
#The program will generate a unique ID for the transaction.
#The program will display the user's name, account number, and balance.
#The program will display the unique ID.
#The program will ask the user if he wants to make a deposit or withdrawal.
#If the user wants to make a deposit, the program will ask for the amount to deposit.
#If the user wants to make a withdrawal, the program will ask for the amount to withdraw.
#The program will display the user's name, account number, and balance.
#The program will display the unique ID.
#The program will ask the user if he wants to make another transaction.
#If the user wants to make another transaction, the program will restart.
#If the user does not want to make another transaction, the program will end.

def main():
    print("Welcome to the bank!")
    name = input("What is your name? ")
    accountNumber = input("What is your account number? ")
    balance = float(input("What is your balance? "))
    print("Your name is " + name + ".")
    print("Your account number is " + accountNumber + ".")
    print("Your balance is " + str(balance) + ".")
    transactionID = uuid.uuid4()
    print("Your transaction ID is " + str(transactionID) + ".")
    print("Would you like to make a deposit or withdrawal?")
    print("1. Deposit")
    print("2. Withdrawal")
    choice = input("Enter 1 or 2: ")
    if choice == "1":
        deposit = float(input("How much would you like to deposit? "))
        balance = balance + deposit
        print("Your balance is " + str(balance) + ".")
        print("Would you like to make another transaction?")
        print("1. Yes")
        print("2. No")
        choice = input("Enter 1 or 2: ")
        if choice == "1":
            main()
        else:
            print("Thank you for banking with us!")
    else:
        withdrawal = float(input("How much would you like to withdraw? "))
        balance = balance - withdrawal
        print("Your balance is " + str(balance) + ".")
        print("Would you like to make another transaction?")
        print("1. Yes")
        print("2. No")
        choice = input("Enter 1 or 2: ")
        if choice == "1":
            main()
        else:
            print("Thank you for banking with us!")

main()