#Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
import threading

class BankAccount:
    def __init__(self, balance):
        self.balance = balance
        self.lock = threading.Lock()
        self.transaction_history = []

    def get_transaction_history(self):
        with self.lock:
            return self.transaction_history

    def update_account_balance(self, amount):
        with self.lock:
            self.balance += amount
            self.transaction_history.append(amount)

    def lock_account(self):
        self.lock.acquire()

    def unlock_account(self):
        self.lock.release()