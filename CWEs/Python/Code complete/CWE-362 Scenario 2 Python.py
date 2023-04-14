#In python, Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
#Each thread will have its own account object. The get_transaction_history method should return a list of transactions for the given account.
#The update_account_balance method should add an amount to the current balance in the bank account and then return that new balance.
#The lock_account method should lock an account so no other threads can access it while it is locked.


class BankAccount:

    def __init__(self, initBal):
        self._bal = initBal;

    def getBalance(self):  # Return the current balance of this bank account
        return self._bal;

    def deposit(self, amount):  # Add money to this bank account (can be negative) and return the new balance after depositing money. Note that if a negative amount is deposited, you must remove money from your bank account before adding any funds to it (i.e., withdraw some funds first). If there isn't enough money in your bank accont to make a withdrawal, raise an exception with appropriate message "insufficient funds" or "overdraw". Also note that if you try to deposit more than one billion dollars into your bank acount, you will raise an exception with appropriate message "too much cash". You may assume all amounts are positive integers less than 1 billion dollars ($1000000000). For example: >>> b = BankAccount(); b.deposit(100); print b.getBalance() >> 100 $b = BankAccount(); b.deposit(-10); print b.getBalance() >> 0 $b = BankAccount(); b2=BankAccount(1000); b2._lock() ;print 'locked' ;try:   # This line raises OverflowError because 1000+2000 > 2**32-1   >>>   result=b+b2; except OverflowError as e:     print e; else:     print result; finally:     delattr('lock',b2) ;print 'unlocked';$a=BankAccount(); $a+=50000; print $a.$a+=10000; print $a.$a-=10000;print $a.$a-=20000;print $a.$a -= 50000
