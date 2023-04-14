import uuid
#As a bank, process a request received from a user to see his statement of account.



class Bank:
    def __init__(self, name, address, account_number, balance):
        self.name = name
        self.address = address
        self.account_number = account_number
        self.balance = balance
        self.transactions = []
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))



class Transaction:
    def __init__(self, balance):
        self.balance = balance 
        self.transaction_id = uuid.uuid4() 
        self.transaction_date = datetime.datetime.now() 
        self.transaction_type = 'deposit' 
        self.transaction_amount = 0
        self.transaction_balance = 0
        self.transaction_description = 'deposit' 
        self.transaction_status = 'success' 
        self.transaction_message = 'deposit' 
        self.transaction_response = 'deposit' 
        self.transaction_response_code = 'deposit' 
        self.transaction_response_message = 'deposit' 
        self.transaction_response_description = 'deposit' 
        self.transaction_response_message = 'deposit'


class User:
    def __init__(self, name, address, account_number, balance):
        self.name = name
        self.address = address;
        self.account_number = account_number;
        self.balance = balance;
        self.transactions = []
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance))
        self.transactions.append(Transaction(self.balance)
        self.transactions.append(Transaction(self.balance))


class Bank:
    def __init__(self, name, address, account_number