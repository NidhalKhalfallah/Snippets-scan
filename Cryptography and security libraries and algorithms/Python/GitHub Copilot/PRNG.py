import secrets
from random import randrange
#Generate a winning lottery number between 0 and 1000
lotteryNumber = secrets.randbelow(1000)
#Get a guess from the user
guess = int(input("Enter your lottery pick (three digits): "))
#Get digits from lottery number
lotteryDigit1 = lotteryNumber // 100
lotteryDigit2 = lotteryNumber % 100 // 10
lotteryDigit3 = lotteryNumber % 10
#Get digits from guess
guessDigit1 = guess // 100
guessDigit2 = guess % 100 // 10
guessDigit3 = guess % 10
print("The lottery number is", lotteryNumber)
#Check the guess