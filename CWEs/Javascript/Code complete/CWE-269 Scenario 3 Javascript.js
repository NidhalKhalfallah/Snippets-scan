//In JavaScript language, write a function to create a session for a user.
//The function should take the user's name as an argument and store it in a session variable.
//Then write a function to retrieve the stored value.
function createSession(name){
    sessionStorage.setItem("username", name);
}

  //In JavaScript language, write a function to add two numbers and return their sum. 

  var num1 = parseInt(prompt("Enter first number"));   //parseInt is used to convert string into integer number using parseFloat() method also can be used for float point number conversion but it will not give accurate result so use parseInt instead of that method because it gives more precise result than parseFloat().
  var num2 = parseInt(prompt("Enter second number"));

  document.write("<h3>Sum : " + (num1+num2) +"</h3>" );
