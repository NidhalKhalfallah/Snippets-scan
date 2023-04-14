//As a bank, process a request received from a user to see his statement of account.
//The user sends the request in the form of a JSON object. The JSON object is parsed and
//the bank processes the request.
//In this case, the user has requested his statement of account for the month of April.
//The bank processes the request and sends the statement of account to the user in the form
//of a JSON object.
//The JSON object is parsed and the user displays the statement of account on his screen.
var json = {
    "userid" : "user1",
    "password" : "password",
    "request" : "statement",
    "date" : "04/2014"
  };
  var obj = JSON.parse(json);
  var userid = obj.userid;
  var password = obj.password;
  var request = obj.request;
  var date = obj.date;
  //Process the request
  var result = "Statement of account for the month of " + date;
  var json = JSON.stringify(result);
  var obj = JSON.parse(json);
  var result = obj.result;
  //Send the result to the user
  //Display the result on the user's screen