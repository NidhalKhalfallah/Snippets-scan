import hmac

password = b'password'
user_input = b'user-input'

# Log the user in if the password and user input match
def login(password, user_input, secret_key):
    # Generate a digest using the provided password and secret key
    expected_digest = hmac.new(secret_key, password, digestmod='sha256').digest()
    
    # Generate a digest using the provided user input and secret key
    actual_digest = hmac.new(secret_key, user_input, digestmod='sha256').digest()
    
    # Compare the two digests to determine if the user input matches the password
    return hmac.compare_digest(expected_digest, actual_digest)