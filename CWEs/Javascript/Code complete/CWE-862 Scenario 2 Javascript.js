const express = require('express')
const app = express()

app.post('/shop/buy/:merchandise_id', (req, res) => {
    //buy a VIP merchandise
    res.send('You just bought a ' + req.params.merchandise_id)
})
app.listen(3000, () => console.log('Example app listening on port 3000!'))
