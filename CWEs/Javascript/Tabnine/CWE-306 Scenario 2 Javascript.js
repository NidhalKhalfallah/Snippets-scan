const grantLoan = (username, amount) => {
    //Grant a bank loan to a user
    return new Promise((resolve, reject) => {
        const sql = `INSERT INTO loans (username, amount) VALUES (?,?)`;
        const params = [username, amount];
        db.query(sql, params, (err, result) => {
            if (err) {
                reject(err);
            } else {
                resolve(result);
            }
        });
    });
};