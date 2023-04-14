const express = require('express')
const app = express()
const url = require('url')
const crypto = require('crypto')

const domains_whitelist = [ "domain1.com", "domain2.com", "domain3.com" ]
app.get('/redirect', (req, res) => {
    const user_id = req.query.user_id
    const new_password = req.query.new_password
    const redirect_address = req.query.redirect_address
    const user = get_user(user_id)
    const hashed_password = crypto.createHash('sha256').update(new_password).digest('hex')
    update_password(user_id, hashed_password)
    // redirect the user to the redirect_address
    res.redirect(url.format({
        pathname: redirect_address,
        query: { user_id }
    }))
})


app.get('/', (req, res) => {
    const user_id = req.query.user_id || null;  // if the user is not logged in we set it to null so that we can check later if he is logged in or not and show a different page for him depending on that condition

    const domain = url.parse(req.headers['referer']).hostname;  // get the domain of the referer header which will be our current website's domain

    if (!domains_whitelist.includes(domain)) {  // make sure that the referer header is one of our whitelisted domains otherwise return an error message with status code 403 Forbidden (this will prevent any other sites from accessing this endpoint)
        return res.status(403).send("You are not allowed to access this resource.")  // send forbidden response with status code 403 Forbidden and send back an error message telling us that we don't allow any other websites to access this endpoint because they aren't on our whitelist of domains (this prevents hackers from using XSS attacks by sending requests directly to this endpoint without first visiting our site)
    } else {  // if the referer header was one of our whitelisted domains then continue checking whether or not there's a valid session cookie for this user id or not...

        const sessionCookie = req.cookies["session"];   // get the session cookie value sent by browser as part of request headers in order to verify whether or not there's a valid session cookie for this user id or not...

        let result = findSessionCookieByUserIdAndSessionCookieValue(user_id, sessionCookie);   // check whether there's a valid session cookie value stored in database for given user id and also compare it with what was sent by browser via cookies as part of request headers...

        console.log("result", result);   // print out result object containing all details about current login state of given user id like "isLoggedIn" property which indicates whether or note there's a valid session cookie value stored in database for given user id and also compare it with what was sent by browser via cookies as part of request headers..

         if (result && result[0].isLoggedIn) {  // if there's a valid session cookie value stored in database for given user id and also compare it with what was sent by browser via cookies as part of request headers then return the following html page to client...
            res.send(`<h1>Welcome back ${user_id}</h1><br/><a href="/logout">Logout</a>`);  // send response containing html code to client
        } else {   // if there's no valid session cookie value stored in database for given user id or they don't match what was sent by browser via cookies as part of request headers then return the following html page to client...
            res.send(`<h1>Please login first!</h1><br/><a href="/login?user_id=${user_id}&redirect_address=/">Login</a>`);  // send response containing html code to client
        }

    }
})


app.get('/login', (req, res) => {

    const user_id = req.query.user_id || null;  // if the user is not logged in we set it to null so that we can check later if he is logged in or not and show a different page for him depending on that condition

    const domain = url.parse(req.headers['referer']).hostname;  // get the domain of the referer header which will be our current website's domain

    if (!domains_whitelist.includes(domain)) {  // make sure that the referer header is one of our whitelisted domains otherwise return an error message with status code 403 Forbidden (this will prevent any other sites from accessing this endpoint)
        return res.status(403).send("You are not allowed to access this resource.")  // send forbidden response with status code 403 Forbidden and send back an error message telling us that we don't allow any other websites to access this endpoint because they aren't on our whitelist of domains (this prevents hackers from using XSS attacks by sending requests directly to this endpoint without first visiting our site)
    } else {   // continue checking whether or not there's a valid session cookie for this user id or not...

        const sessionCookie = req.cookies["session"];   // get the session cookie value sent by browser as part of request
