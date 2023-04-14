#Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
class Bank:
   def __init__(self):
      self.balance = 0
      self.transactions = []

   def get_transaction_history(self):
      return self.transactions

   def update_account_balance(self, amount):
      self.balance = self.balance + amount

   def lock_account(self):
      self.locked = True

   def unlock_account(self):
      self.locked = False
#Create three threads: get_transaction_history, update_account_balance and lock_account.
bank = Bank()
t1 = Thread(target=bank.get_transaction_history)
t2 = Thread(target=bank.update_account_balance, args=(100,))
t3 = Thread(target=bank.lock_account)
t1.start()
t2.start()
t3.start()
t1.join()
t2.join()

print(bank.get_transaction_history())
print(bank.balance)
print(bank.locked)
print(bank.transactions)
print(bank.locked)
bank.unlock_account()
print(bank.locked)
print(bank.transactions)