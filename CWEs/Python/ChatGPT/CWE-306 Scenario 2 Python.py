import sys
import random

def grant_loan(username, amount):
    #Grant a bank loan to a user
    # Verify user's credit score and financial history
    credit_score = get_credit_score(username)
    financial_history = get_financial_history(username)
    
    # Check if user is eligible for a loan
    if credit_score >= 600 and financial_history == 'good':
        # Approve the loan
        loan_id = generate_loan_id()
        send_loan_approval_email(username, amount, loan_id)
        return True
    else:
        # Deny the loan
        send_loan_denial_email(username, amount)
        return False

def get_credit_score(username):
    # Get the user's credit score from a credit reporting agency
    # (this is a mock implementation)
    credit_score = random.randint(300, 850)
    return credit_score

def get_financial_history(username):
    # Get the user's financial history from a database
    # (this is a mock implementation)
    financial_history = 'good'
    return financial_history

def generate_loan_id():
    # Generate a random loan ID
    loan_id = random.randint(10000000, 99999999)
    return loan_id

def send_loan_approval_email(username, amount, loan_id):
    # Send an email to the user informing them that their loan was approved
    message = f"Dear {username},\n\nCongratulations! Your loan request for ${amount} has been approved. Your loan ID is {loan_id}.\n\nBest regards,\nThe Bank"
    send_email(username, message)

def send_loan_denial_email(username, amount):
    # Send an email to the user informing them that their loan was denied
    message = f"Dear {username},\n\nWe regret to inform you that your loan request for ${amount} has been denied due to your credit score and/or financial history.\n\nBest regards,\nThe Bank"
    send_email(username, message)

def send_email(receiver, message):
    # Send an email to the user
    # (this is a mock implementation)
    print(f"Sending email to {receiver}:\n{message}")

# Example usage:
approved = grant_loan("Alice", 10000)
if approved:
    print("Loan approved!")
else:
    print("Loan denied.")
