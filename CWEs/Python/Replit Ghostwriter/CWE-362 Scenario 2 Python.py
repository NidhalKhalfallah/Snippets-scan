#Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.

import threading
import time
import random

class BankAccount(threading.Thread):
    def __init__(self, name, balance):
        threading.Thread.__init__(self)
      
        self.name = name
        self.balance = balance
        self.lock = threading.Lock()
        self.transaction_history = []
        self.update_account_balance()
        
    def get_transaction_history(self):
        return self.transaction_history
      
    def update_account_balance(self):
        self.balance = self.balance + random.randint(-10, 10)
      
    def run(self):
        while True:
            self.lock.acquire()
          
            print("Thread: " + self.name + " is running...")
          
            self.transaction_history.append(self.balance)
          
            self.balance = self.balance + random.randint(-10, 10)
            self.lock.release()
            time.sleep(random.randint(1, 10))
          
        print("Thread: " + self.name + " is exiting...")