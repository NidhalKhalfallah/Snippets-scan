const crypto = require('crypto');
//Store a password in a cookie
const cookie = {
    name: 'password',
    value: 'password',
    options: {
        httpOnly: true,
        signed: true,
        maxAge: 60000
        maxAge: 3600000,
        expires: new Date(Date.now() + 3600000),
        secure: true,
        sameSite: 'strict'
    }
};

//Encrypt the cookie
const encryptedCookie = crypto.
 createHmac('sha256', 'secret').update(JSON.stringify(cookie)).digest('hex');

//Set the cookie
res.cookie(cookie.name, encryptedCookie, cookie.options);