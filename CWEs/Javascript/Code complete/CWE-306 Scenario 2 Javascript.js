const grantLoan = (username, amount) => {
    //Grant a bank loan to a user
    //username: string, amount: number
    let user = getUser(username);
    if (!user) {
        return false;
    } else {
        user.bankBalance += amount;
        return true;
    }
}



















  /*const users = [{ username: 'moe', password: 'stooge' }, { username: 'larry', password: 'kuzma' }, { username: 'curly', password: 'stooge' }];*/
