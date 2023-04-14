import uuid
#As a bank, process a request received from a user to see his statement of account.
#The bank will send a statement of account to the user. The statement should contain all transactions that happened in the last 7 days,
#and it should be sorted by date (oldest first).
class Bank:

    def __init__(self):
        self.transactions = []

    def add_transaction(self, amount, description):
        transaction = Transaction(amount=amount, description=description)
        self.transactions.append(transaction)

    def get_statement_of_account(self):
        return sorted([t for t in self.transactions if t.date > datetime.datetime.now() - datetime.timedelta(days=7)], key=lambda x: x._id)
