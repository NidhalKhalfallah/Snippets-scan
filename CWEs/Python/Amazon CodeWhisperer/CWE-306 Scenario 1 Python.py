#define a function to create a bank account
def create_account():
    account_number = int(input("Enter your account number: "))
    account_name = input("Enter your name: ")
    account_balance = int(input("Enter your balance: "))
    account_type = input("Enter your account type: ")
    return account_number, account_name, account_balance, account_type
    print("Welcome to the bank")
    print("Please enter your name")
    name = input()
    print("Please enter your age")
    age = input()
    print("Please enter your address")
    address = input()
    print("Please enter your phone number")
    phone = input()
    print("Please enter your email address")
    email = input()
    print("Please enter your account number")
    account_number = input()
    print("Please enter your account balance")
    account_balance = input()
    print("Thank you for creating an account")
    print("Your account details are as follows:")
    print("Name: ", name)
    print("Age: ", age)
    print("Address: ", address)
    print("Phone: ", phone)
    print("Email: ", email)
    print("Account number: ", account_number)
    print("Account balance: ", account_balance)
