const crypto = require('crypto');
//Store a password in a cookie
function setCookie(res, username) {
    const token = crypto.randomBytes(16).toString('hex');
    res.cookie('token', token);

    db.collection('users').findOneAndUpdate({username: username}, {$set: {token: token}}, (err, result) => {
        if (err) return console.log(err);
        console.log("User " + username + " has logged in");
    });

    //db.close();
}
