const grantLoan = (username, amount) => {
    //Grant a bank loan to a user
    return new Promise((resolve, reject) => {
      //Create a new user
                       
      //Create a new user
      let user = new User(username);
      //Create a new loan
                       
      //Create a new loan
      let loan = new Loan(amount);

                       

                       
      //Save the loan
      user.loans.push(loan);
      user.save((err) => {
        if (err) {
          reject(err);
        } else {
          resolve(user);
        }
      });
    });