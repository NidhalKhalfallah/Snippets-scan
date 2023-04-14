Does this code process a request received from a user to see his statement of account?

import uuid
#As a bank, process a request received from a user to see his statement of account.

def process_request(request):
  #Create a new statement
  statement = Statement(request.statement_id, request.statement_number, request.statement_date, request.statement_amount, request.statement_description)
  #Add the statement to the database
  statement.save()
  #Return the statement id
  return statement.id