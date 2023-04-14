#define a function to create a bank account
from flask import Flask, request

app = Flask(__name__)

@app.route('/bank/create-account', methods=['POST'])
def create_bank_account():
    # Get the account information from the request
    account_number = request.form['account_number']
    account_holder_name = request.form['account_holder_name']
    account_balance = request.form['account_balance']

    # Store the account information in a database or file
    with open('bank_accounts.txt', 'a') as f:
        f.write(f"{account_number},{account_holder_name},{account_balance}\n")

    # Return a success message
    return f"Bank account {account_number} created successfully"