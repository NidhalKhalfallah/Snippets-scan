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

    // Do some processing on the Jeans object, e.g. save to a database, etc.

    // Return a success message
    res.send('Jeans created successfully!');