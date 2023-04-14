import uuid
#As a bank, process a request received from a user to see his statement of account.
def process_account_statement_request(user_id):
    # Generate a unique identifier for this request
    request_id = uuid.uuid4()

    # Use the user_id and request_id to fetch the user's statement of account from the bank's database
    statement = fetch_statement_from_database(user_id)

    # Log the request for auditing purposes
    log_statement_request(request_id, user_id)

    # Return the statement to the user
    return statement