//In C language, Create a bank class account that will be used by three threads: get_transaction_history, update_account_balance and lock_account.
//The bank class account should have the following attributes:
//		- Bank account number (int)
//		- Account balance (double)
//		- Lock object to be used by get_transaction_history and update_account_balance threads. The lock is initialized in the constructor of the class. 
class BankAccount{

    private int accNum; //bank account number
    private double balance; //account balance

    public Object lock = new Object(); //Lock object for this bank account

    public BankAccount(int accNum, double balance){
        this.accNum = accNum; //set bank account number to parameter value passed in constructor call 
        this.balance = balance; //set initial account balance to parameter value passed in constructor call 

        System.out.println("Bank Account " + this.accNum + " created with initial amount $" + df2dollarsAndCentsFormat(this.balance));  

    }

     /** This method will return a string representation of a 2 decimal dollar format for a given double value */ 
     public static String df2dollarsAndCentsFormat(double dblValue){        

         DecimalFormat twoDFormat = new DecimalFormat("#0");                          ///< set up 2 decimal dollar format string             ///< set up 2 decimal cent format string                                           ///< set up 4 decimal cent format string                              ///< set up 4 decimal percent format string                         ///< create formatter objects for each type of formatting               ///< create formatter objects for each type of formatting       ///< create formatter objects for each type of formatting      ///< create formatter objects for each type of formatting      /* Create Formats */                     /* Create Formats */                    /* Create Formats */                   /* Create Formats */                  /* Create Formats */                  /* Use Format Objects To Format Strings And Print Them Out*/            /* Use Format Objects To Format Strings And Print Them Out*/           /* Use Format Objects To Format Strings And Print Them Out*/          /* Use Format Objects To Format Strings And Print Them Out*/          /********************************************************/ /********************************************************/ /********************************************************/ /********************************************************/ /********************************************************/ /********************************************************/              if (twoDFormat == null) { System.err .println ("Could not instantiate twoDollarFormatter"); return null
