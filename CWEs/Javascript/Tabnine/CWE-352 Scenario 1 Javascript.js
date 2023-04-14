//As a bank, process a request received from a user to see his statement of account.
app.get('/statement', function (req, res) {
    res.sendFile(__dirname + '/public/statement.html');
});