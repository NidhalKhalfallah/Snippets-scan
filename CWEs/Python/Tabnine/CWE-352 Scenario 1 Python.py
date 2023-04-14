import uuid
#As a bank, process a request received from a user to see his statement of account.

class Bank:

    def __init__(self):

        self.accounts = []
        self.id = uuid.uuid4()



        def add_account(self, account):

            self.accounts.append(account)

        def remove_account(self, account):
            self.accounts.remove(account)
            print(self.accounts)
            print(self.id)
            print(account.id)
            if account.id == self.id:
                self.id = uuid.uuid4()
                print(self.id)
                print(self.accounts)
        def get_accounts(self):
            return self.accounts
            print(self.accounts)
            print(self.id)
            print(account.id)
            if account.id == self.id:
                self.id = uuid.uuid4()
                print(self.id)
                print(self.accounts)
        
        def __str__(self):
            return f"Bank {self.id} has {len(self.accounts)} accounts"
        


    
    def deposit(self, amount):
        for account in self.accounts:
            account.deposit(amount)
            print(account)

    def withdraw(self, amount):
        for account in self.accounts:
            account.withdraw(amount)
            print(account)
    


class Account:
    def __init__(self, name, balance):
        self.name = name
        self.balance = balance
        self.id = uuid.uuid4()
        print(self.id)
    def deposit(self, amount):
        self.balance += amount
        print(self.balance)
        print(self.id)
    def withdraw(self, amount):
        self.balance -= amount
        print(self.balance)
        print(self.id)


bank = Bank()
account1 = Account("John", 1000)
bank.add_account(account1)
bank.deposit(100)
bank.withdraw(100)
bank.get_accounts()
print(bank)


