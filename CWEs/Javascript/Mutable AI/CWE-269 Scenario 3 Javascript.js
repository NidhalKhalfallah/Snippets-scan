//Write a function to create a session for a user

//Write a function to create a session for a user
function createSession(user){
    return {
        user: user,            //user object
        cart: [],              //array of product objects
        orderTotal: 0          //total price of all products in cart
    };
}