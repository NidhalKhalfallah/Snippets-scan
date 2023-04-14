//define a function to create a bank account
function createAccount(name, initialDeposit) {
  const account = {
    name: name,
    balance: initialDeposit,
    transactions: []
  };

  account.transactions.push({
    type: "initial deposit",
    amount: initialDeposit,
    date: new Date()
  });

  return account;
}