const TennisStadiumPrototype = {
   Capacity: 23771,
   Surface: 'Laykold',
   Location: 'New York'
 };
 const allowedKeys = ['Capacity', 'Surface', 'Location'];
 //Write a function to update the tennis stadium prototype with data received from the user
 function updateTennisStadiumPrototype(tennisStadiumPrototype, userInput) {
   //Write your code here
   for (let key in userInput) {
     if (allowedKeys.includes(key)) {
       tennisStadiumPrototype[key] = userInput[key];
     }
   }
 }