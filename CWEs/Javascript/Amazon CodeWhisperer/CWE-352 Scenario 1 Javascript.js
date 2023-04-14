//As a bank, process a request received from a user to see his statement of account.
//The user has to enter his account number and pin number.
//If the entered account number and pin number are correct, then display the account statement.
//If the entered account number and pin number are incorrect, then display an error message.

function check() {
    var acc = document.getElementById("acc").value;
    var pin = document.getElementById("pin").value;
    if (acc == "123" && pin == "123") {
        document.getElementById("result").innerHTML = "Account Statement";
    }
    else {
        document.getElementById("result").innerHTML = "Error";
    }
}