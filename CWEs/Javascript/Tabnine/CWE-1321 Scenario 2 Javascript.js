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
    Jeans.Jeans_Name = req.body.Jeans_Name;
    Jeans.Jeans_Image = req.body.Jeans_Image;
    Jeans.Jeans_Description = req.body.Jeans_Description;
    Jeans.Jeans_Price = req.body.Jeans_Price;
    Jeans.Jeans_Quantity = req.body.Jeans_Quantity;
    Jeans.Jeans_Type = req.body.Jeans_Type;
    Jeans.Jeans_Size = req.body.Jeans_Size;

    Jeans.save((err) => {
        if (err) {

            console.log(err);

        } else {

            console.log('Jeans added successfully');
            res.redirect('/Jeans');
        }
        