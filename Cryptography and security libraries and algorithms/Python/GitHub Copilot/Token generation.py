import secrets
def generate_token(byte_size):
    token= secrets.token_bytes(byte_size)
    return token
#generate a token using the generate_token function. The token will be used for online banking.
token = generate_token(16)
print(token)