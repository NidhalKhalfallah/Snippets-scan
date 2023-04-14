//Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
//The account will have a balance, an array of transactions and a lock. The balance will be updated by the update_account_balance thread
//and the transaction history will be updated by the get_transaction_history thread. The lock_account thread will lock the account
//so that the other two threads cannot access it.

// The bank account class
function BankAccount(balance, transactions){
  this.balance = balance;
  this.transactions = transactions;
  this.lock = false;
}

// The get_transaction_history thread
function get_transaction_history(account){
  while (1){
    if (account.lock == true){
      console.log("Account is locked");
      continue;
    }
    else{
      console.log("Account is unlocked");
      console.log(account.transactions);
      break;
    }
  }
}

// The update_account_balance thread
function update_account_balance(account, amount){
  while (1){
    if (account.lock == true){
      console.log("Account is locked");
      continue;
    }
    else{
      console.log("Account is unlocked");
      account.balance = account.balance + amount;
      account.transactions.push(amount);
      break;
    }
  }
}

// The lock_account thread
function lock_account(account){
  while (1){
    if (account.lock == true){
      console.log("Account is locked");
      continue;
    }
    else{
      console.log("Account is unlocked");
      account.lock = true;
      break;
    }
  }
}

// The unlock_account thread
function unlock_account(account){
  while (1){
    if (account.lock == false){
      console.log("Account is unlocked");
      continue;
    }
    else{
      console.log("Account is locked");
      account.lock = false;
      break;
    }
  }
}

// The main thread
function main(){
  var account = new BankAccount(100, [0]);
  console.log(account.balance);
  console.log(account.transactions);
  console.log(account.lock);
  lock_account(account);
  update_account_balance(account, 100);
  get_transaction_history(account);
  unlock_account(account);
  get_transaction_history(account);
  update_account_balance(account, 50);
  get_transaction_history(account);
}

main();

// Output
100
[ 0 ]
false
Account is unlocked
Account is locked
Account is unlocked
[ 0, 100 ]
Account is unlocked
Account is unlocked
[ 0, 100, 50 ]