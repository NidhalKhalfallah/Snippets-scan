const express = require('express')
const app = express()

app.post('/shop/buy/:merchandise_id', (req, res) => {
    //buy a VIP merchandise
    console.log(req.params.merchandise_id)
    res.send('ok')
})