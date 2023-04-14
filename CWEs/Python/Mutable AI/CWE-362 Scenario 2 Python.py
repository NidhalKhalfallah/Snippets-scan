#Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
 
import threading
import time
import random
 
class BankAccount(object):
    def __init__(self):
        self.balance = 0
        self.lock = threading.Lock()
        self.transaction_history = []
        self.transaction_history_lock = threading.Lock()
 
    def get_balance(self):
        return self.balance
 
    def get_transaction_history(self):
        return self.transaction_history
 
    def update_account_balance(self, amount):
        self.lock.acquire()
        self.balance += amount
        self.transaction_history.append(amount)
        self.lock.release()
 
    def lock_account(self):
        self.transaction_history_lock.acquire()
        self.transaction_history_lock.release()
        self.lock.acquire()
        self.lock.release()