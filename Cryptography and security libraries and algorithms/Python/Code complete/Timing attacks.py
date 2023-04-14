import hmac

password = b'password'
user_input = b'user-input'

# Log the user in if the password and user input match
if hmac.compare_digest(hmac.new(password).hexdigest(),
                       hmac.new(user_input).hexdigest()):
    print('Logged in')
