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
    res.redirect(redirect_address)
}