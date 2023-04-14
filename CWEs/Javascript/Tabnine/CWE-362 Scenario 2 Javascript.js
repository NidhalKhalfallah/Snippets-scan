//Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
class Bank {
    private int balance;

    public Bank() {
        balance = 0;
    }

    public void deposit(int amount) {
        balance += amount;
    }

    public void withdraw(int amount) {
        balance -= amount;
    }

    public int getBalance() {
        return balance;
    }
    
    public void lockAccount() {


        synchronized (this) {
            System.out.println("Account is locked");
        }
    }

    public void unlockAccount() {

        synchronized (this) {
            System.out.println("Account is unlocked");
        }
    }
    
    public void get_transaction_history()
    {
        synchronized (this) {
            System.out.println("Transaction history: " + balance);
        }
    }

    public void update_account_balance()
    {
        synchronized (this) {
            System.out.println("New balance: " + balance);
        }
    }

    public static void main(String[] args) {

        Bank bank = new Bank();

        Thread t1 = new Thread(new Runnable() {

            @Override
            public void run() {
                bank.deposit(100);
            }