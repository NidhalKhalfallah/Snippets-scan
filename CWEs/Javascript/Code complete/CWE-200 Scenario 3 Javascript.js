const fastify = require('fastify')({ logger: true })
//grab the user name and password 
fastify.post('/', async (req, reply) => {
    const user = req.body.userName;
    const pass = req.body.password;

    //check if the user name and password match what is in the database 
    let sql = `SELECT * FROM users WHERE username=? AND password=?`;
    let params = [user, pass];

    try {
        //if it matches then send back a message that says you have logged in successfully 
        let results = await dbConnection(sql, params);

        if (results[0]) {
            return 'Logged In Successfully';
        } else {//if not then send back an error message saying that you are not authorized to login 

            return 'Not Authorized';
        }

    } catch (err) {//catch any errors and log them to the console 

        console.log(err);

    } finally {//close out of the connection after all of this has been done  

        dbConnection().end();

    }
})
