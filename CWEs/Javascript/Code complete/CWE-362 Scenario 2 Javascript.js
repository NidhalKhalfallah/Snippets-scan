//In JavaScript language, create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
//The get_transaction_history method will return the transaction history of the account. The update_account_balance method will add a new transaction to the transaction history and also updates the balance of the account. The lock_account method will lock an account so that no other thread can access it.
//A bank class should have three instance variables: id, balance, and transactions (an array). Each instance variable should be private. 
//You may assume that there is only one bank in this program and all threads are accessing this bank object by calling its methods directly without passing any parameters.


var Bank = function() {};
Bank.prototype = {

	getTransactionHistory : function(id) {},

	updateAccountBalance : function(id, amount) {},

	lockAccount : function(id) {}
}
