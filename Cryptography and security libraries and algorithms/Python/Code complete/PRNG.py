import secrets
from random import randrange
#Generate a winning lottery number between 0 and 10000
winning_number = randrange(0, 10000)
#Ask the user to guess a number between 0 and 100
guess_count = 1
while True:
    try:  #check if the input is an integer or not. If it's not, raise an exception. Otherwise continue with code below.
        guess = int(input('Guess a number between 0 and 10000
