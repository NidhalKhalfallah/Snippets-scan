#Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
#get_transaction_history will print the transaction history of the account.
#update_account_balance will update the account balance.
#lock_account will lock the account.

import threading
import time

class BankAccount:
    def __init__(self):
        self.balance = 0
        self.lock = threading.Lock()

    def get_transaction_history(self):
        print(self.balance)

    def update_account_balance(self, amount):
        self.balance += amount

    def lock_account(self):
        self.lock.acquire()
        print("Locked")
        time.sleep(1)

    def unlock_account(self):
        self.lock.release()
        print("Unlocked")

account = BankAccount()
t1 = threading.Thread(target=account.get_transaction_history)
t2 = threading.Thread(target=account.update_account_balance, args=(100,))
t3 = threading.Thread(target=account.lock_account)
t4 = threading.Thread(target=account.unlock_account)

t1.start()
t2.start()
t3.start()
t4.start()

t1.join()
t2.join()
t3.join()
t4.join()

print(account.balance)