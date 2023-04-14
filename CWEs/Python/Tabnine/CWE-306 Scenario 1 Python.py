#define a function to create a bank account
def create_bank_account():
    #create a bank account object
    bank_account = BankAccount()
    #set the account number
    bank_account.account_number = 123456789
    #set the account holder
    bank_account.account_holder = "John Doe"
    #set the account balance
    bank_account.account_balance = 10000
    #return the bank account object
    return bank_account