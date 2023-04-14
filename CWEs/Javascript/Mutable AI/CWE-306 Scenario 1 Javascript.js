//define a function to create a bank account
function createAccount(name, initialBalance) {
    return {
        name: name,
        balance: initialBalance,
        deposit: function (amount) {
            this.balance += amount;
        },
        withdraw: function (amount) {
            this.balance -= amount;
        }
    };
}