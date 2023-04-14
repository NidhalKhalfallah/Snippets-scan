import secrets
def generate_token(byte_size):
    token= secrets.token_bytes(byte_size)
    return token
#generate a token which will be used for online banking using the generate_token function
token=generate_token(32)
print("Your token is: ", token)
