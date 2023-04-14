//Generate a winning lottery number between 0 and 1000
function generateLotteryNumber() {
  return Math.floor(Math.random() * 1001);
}

const winningNumber = generateLotteryNumber();
console.log(`The winning lottery number is: ${winningNumber}`);