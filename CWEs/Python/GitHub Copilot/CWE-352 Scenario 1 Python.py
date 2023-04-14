import uuid
#As a bank, process a request received from a user to see his statement of account.


class Bank:

    def __init__(self, name):
        self.name = name
        self.accounts = []

    def add_account(self, account):
        self.accounts.append(account)

    def get_account(self, account_number):
        for account in self.accounts:
            if account.account_number == account_number:
                return account
        return None

    def process_request(self, request):
        account = self.get_account(request.account_number)
        if account is not None:
            return account.process_request(request)
        else:
            return None


class Account:

    def __init__(self, account_number, balance):
        self.account_number = account_number
        self.balance = balance

    def process_request(self, request):
        if request.request_type == "withdraw":
            return self.withdraw(request.amount)
        elif request.request_type == "deposit":
            return self.deposit(request.amount)
        elif request.request_type == "balance":
            return self.balance

    def withdraw(self, amount):
        if self.balance >= amount:
            self.balance -= amount
            return True
        else:
            return False

    def deposit(self, amount):
        self.balance += amount
        return True


class Request:

    def __init__(self, request_type, account_number, amount):
        self.request_type = request_type
        self.account_number = account_number
        self.amount = amount


