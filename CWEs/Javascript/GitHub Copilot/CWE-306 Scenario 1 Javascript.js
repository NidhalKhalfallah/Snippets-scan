//define a function to create a bank account
var createAccount = function (initialBalance) {
    var balance = initialBalance;
    return {
        deposit: function (amount) {
            balance += amount;
        },
        withdraw: function (amount) {
            balance -= amount;
        },
        getBalance: function () {
            return balance;
        }
    };
};