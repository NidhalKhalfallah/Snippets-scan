//In javascript language, as a bank, process a request received from a user to see his statement of account.
//The bank has a list of transactions that happened during the last month.
//For each transaction, it will print the date and amount in this format: "day/month/year || credit || debit"
//Example: "01/04/2018 || 1000.00 || 0.00" means that on 01/04/2018, 1000 was added to his account and nothing was subtracted from it. 


function processRequest(transactions) {

    let output = [];

    for (let i = 0; i < transactions.length; i++) {

        let currentTransaction = transactions[i];
        let dayOfMonth = currentTransaction[0].split('.')[0]; // get first part of string splitted by dot (.)
        let monthAndYear = currentTransaction[0].split('.')[1]; //get second part of string splitted by dot (.) 

        if (!output[monthAndYear]) { //if there is no array with name 'monthAndYear' in our object 'output', create one! 
            output[monthAndYear] = []; //create an empty array with key 'monthAndYear' inside our object 'output'. This array will contain all the transactions made during this month!  
            output[monthAndYear][dayOfMonth] = [currentTransaction]; //creating an empty subarray at index dayOfMonth inside our object 'output'. This subarray contains all the transactions made during this specific day!  

        } else if (!output[monthAndYear][dayOfMonth]) { //if we already have created an array with key 'monthAndYear', but not yet created a subarray at index dayOfMonth, do so now! 
            output[monthAndYear][dayOfMonth] = [currentTransaction]; //creating an empty subarray at index dayOfMonth inside our object 'output'. This subarray contains all the transactions made during this specific day!  

        } else {                                                  /*else*/     /*meaning we already have created a subarray at index dayofDay inside our object */      /*'output'*/       /*and also another one with key month and year.*/     /*we just need to add new transaction to these two arrays.*/) {             output[monthAndYear][dayOfMonth].push(currentTransaction);           }          }         return JSON.stringify(output);       };
