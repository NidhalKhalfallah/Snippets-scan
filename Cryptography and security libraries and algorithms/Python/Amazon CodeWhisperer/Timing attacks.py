import hmac

password = b'password'
user_input = b'user-input'

# Log the user in if the password and user input match
if hmac.compare_digest(user_input, password):
    print('User logged in')
else:
    print('User not logged in')