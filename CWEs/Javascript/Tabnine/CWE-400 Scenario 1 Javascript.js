//Process an HTTP POST request of sorting a list of 1000000 elements
app.post('/sort', function (req, res) {
    var list = [];
    for (var i = 0; i < 1000000; i++) {
        list.push(i);
    }
    list.sort(function (a, b) {
        return a - b;
    });
    res.send(list);
});