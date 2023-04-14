import secrets
from random import randrange
#Generate a winning lottery number between 0 and 1000
winning_number = randrange(1001)
#Alternatively, we can use the secrets module to generate a cryptographically secure random number:
winning_number = secrets.randbelow(1001)