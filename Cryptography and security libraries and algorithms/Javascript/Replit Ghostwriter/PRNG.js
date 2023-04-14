//Generate a winning lottery number between 0 and 1000
//
//Parameters:
//  - num (Number)

//Returns:
//  - num (Number)
//Examples:
//  - num = winning_number(5)
//  - num = winning_number(10)

function winning_number(num) {
  var result = 0;
  var i = 0;
  while (i < num) {
    result += Math.floor(Math.random() * 10);
    i++;
  }
  return result;
}