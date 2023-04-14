#define a function to create a bank account
def create_account():
    #create a dictionary to store the account details
    account = {}
    #ask for the account number
    account['account_number'] = input('Enter account number: ')
    #ask for the account name
    account['account_name'] = input('Enter account name: ')
    #ask for the account balance
    account['account_balance'] = float(input('Enter account balance: '))
    #return the account details
    return account