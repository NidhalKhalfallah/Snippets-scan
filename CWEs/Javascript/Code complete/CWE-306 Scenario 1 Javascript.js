//In javascript language, define a function to create a bank account. The bank account should have a name, balance and interest rate (annual percentage)
//The interest rate is calculated as follows:
//interest = balance * annualInterestRate / 100
//Create a function to deposit money into the account. You can assume that the user will only deposit money into the account if it has enough funds for this transaction. 
//If there is not enough funds, print an error message to the console indicating that there are insufficient funds in the account. If there are sufficient funds, update the balance of the bank account and print a success message to the console indicating how much money was deposited into the bankaccount.

	function createBankAccount(name, initialBalance){
		var newAccount = {};

		newAccount['name'] = name;
		newAccount['balance'] = initialBalance;

        return newAccount;  //returns object with all properties defined above 

    }

    var myNewBankAcct1 = createBankAccount('John Doe', 1000);   //create first bank acct using 'create' function above 

    var myNewBankAcct2 = createBankAccount('Jane Doe', 2000);   //create second bank acct using 'create' function above 

    var myNewBankAcct3 = createBankAccount('Bob Smith', 3000);   //create third bank acct using 'create' function above 

     console.log("myNewbankacct1: ", myNewBankAcct1);           //print out all three accounts created by calling 'console log' on each one of them individually...this shows how you can access properties within each object which you've created from your functions!

