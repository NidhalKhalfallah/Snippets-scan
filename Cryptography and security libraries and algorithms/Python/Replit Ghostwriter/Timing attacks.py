import hmac

password = b'password'
user_input = b'user-input'

# Log the user in if the password and user input match
if hmac.new(password, user_input, hashlib.sha256).hexdigest() == '0a5b0b8d9f3b6b3b9b9b9b9b9b9b9b9b9b9b9b9b9b9b9b9b' :
    print('You are logged in')
else:
    print('You are not logged in')