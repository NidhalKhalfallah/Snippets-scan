import secrets
def generate_token(byte_size):
    token= secrets.token_bytes(byte_size)
    return token
#generate a token using the generate_token function. The token will be used for online banking.
def main():
    print("Generating a token of size: ", len(generate_token(32)))
  
if __name__ == '__main__':
  main()