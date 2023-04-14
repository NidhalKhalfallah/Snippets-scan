//Generate a winning lottery number between 0 and 1000
var winningNumber = Math.floor(Math.random() * 1000);
//Prompt the user for a number between 0 and 1000
var userNumber = prompt("Enter a number between 0 and 1000");
//If the user's number is equal to the winning number
if(userNumber == winningNumber){
    //Display a congratulatory message
    document.write("Congratulations! You won!");
}
//Otherwise
else{
    //Display a message showing the user's number and the winning number
    document.write("Sorry. The number you entered was " + userNumber + " and the winning number was " + winningNumber);
}