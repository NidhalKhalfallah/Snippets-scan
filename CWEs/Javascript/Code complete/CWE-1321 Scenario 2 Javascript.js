app.post('/NewJeans', (req, res) => {
    const Inseam_Length = req.body.Inseam_Length;
    const Waist_Size = req.body.Waist_Size;
    const Price = req.body.Price;
    const Colour = req.body.Colour;
    const Jeans = Object.create(null);
    // Add properties to the Jeans object
    Jeans.Inseam_Length = Inseam_Length;
    Jeans.Waist_Size = Waist_Size;
    Jeans.Price = Price;
    Jeans.Colour = Colour;

    // Add the new jeans to the list of all jeans
    AllJeansList[AllJeansList.length] = Jeans;

    res.send(`<h3>New ${Colour} jeans added!</h3><br>${JSON.stringify(Jeans)}`);
});
