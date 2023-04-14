#Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
#The bank class account will have the following methods:
#1. get_transaction_history: This method will return the transaction history of the account.
#2. update_account_balance: This method will update the account balance.
#3. lock_account: This method will lock the account.
#The bank class account will have the following attributes:
#1. account_number: This attribute will store the account number.
#2. account_balance: This attribute will store the account balance.
#3. transaction_history: This attribute will store the transaction history.
#4. account_lock: This attribute will store the account lock.
#The bank class account will have the following properties:
#1. account_number: This property will return the account number.
#2. account_balance: This property will return the account balance.
#3. transaction_history: This property will return the transaction history.
#4. account_lock: This property will return the account lock.
#The bank class account will have the following constructor:
#1. __init__: This constructor will initialize the account number, account balance, transaction history and account lock.
#The bank class account will have the following destructor:
#1. __del__: This destructor will delete the account number, account balance, transaction history and account lock.
#The bank class account will have the following static methods:
#1. get_account_number: This static method will return the account number.
#2. get_account_balance: This static method will return the account balance.
#3. get_transaction_history: This static method will return the transaction history.
#4. get_account_lock: This static method will return the account lock.

#Import the threading module.
import threading
#Import the time module.
import time

#Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
class BankAccount:
    #The bank class account will have the following attributes:
    #1. account_number: This attribute will store the account number.
    #2. account_balance: This attribute will store the account balance.
    #3. transaction_history: This attribute will store the transaction history.
    #4. account_lock: This attribute will store the account lock.
    #The bank class account will have the following properties:
    #1. account_number: This property will return the account number.
    #2. account_balance: This property will return the account balance.
    #3. transaction_history: This property will return the transaction history.
    #4. account_lock: This property will return the account lock.
    #The bank class account will have the following constructor:
    #1. __init__: This constructor will initialize the account number, account balance, transaction history and account lock.
    #The bank class account will have the following destructor:
    #1. __del__: This destructor will delete the account number, account balance, transaction history and account lock.
    #The bank class account will have the following static methods:
    #1. get_account_number: This static method will return the account number.
    #2. get_account_balance: This static method will return the account balance.
    #3. get_transaction_history: This static method will return the transaction history.
    #4. get_account_lock: This static method will return the account lock.
    #Define the __init__ method.
    def __init__(self, account_number, account_balance, transaction_history, account_lock):
        #Initialize the account number.
        self.account_number = account_number
        #Initialize the account balance.
        self.account_balance = account_balance
        #Initialize the transaction history.
        self.transaction_history = transaction_history
        #Initialize the account lock.
        self.account_lock = account_lock
    #Define the __del__ method.
    def __del__(self):
        #Delete the account number.
        del self.account_number
        #Delete the account balance.
        del self.account_balance
        #Delete the transaction history.
        del self.transaction_history
        #Delete the account lock.
        del self.account_lock
    #Define the get_account_number method.
    @staticmethod
    def get_account_number(self):
        #Return the account number.
        return self.account_number
    #Define the get_account_balance method.
    @staticmethod
    def get_account_balance(self):
        #Return the account balance.
        return self.account_balance
    #Define the get_transaction_history method.
    @staticmethod
    def get_transaction_history(self):
        #Return the transaction history.
        return self.transaction_history
    #Define the get_account_lock method.
    @staticmethod
    def get_account_lock(self):
        #Return the account lock.
        return self.account_lock
    #Define the get_transaction_history method.
    def get_transaction_history(self):
        #Return the transaction history.
        return self.transaction_history
    #Define the update_account_balance method.
    def update_account_balance(self, amount):
        #Update the account balance.
        self.account_balance += amount
        #Update the transaction history.
        self.transaction_history.append(amount)
            #Define the lock_account method.
    def lock_account(self):
        #Lock the account.
        self.account_lock.acquire()
        #Sleep for 5 seconds.
        time.sleep(5)
        #Unlock the account.
        self.account_lock.release()
        