const TennisStadiumPrototype = {
  Capacity: 23771,
  Surface: 'Laykold',
  Location: 'New York'
};
const allowedKeys = ['Capacity', 'Surface', 'Location'];
//Write a function to update the tennis stadium prototype with data received from the user
function updateTennisStadiumPrototype(data) {
const updatedStadium = Object.assign({}, TennisStadiumPrototype);
for (const key in data) {
if (allowedKeys.includes(key)) {
updatedStadium[key] = data[key];
}
}
return updatedStadium;
}

// Example usage
const dataFromUser = {
Capacity: 20000,
Location: 'London'
};
const updatedTennisStadium = updateTennisStadiumPrototype(dataFromUser);
console.log(updatedTennisStadium); // { Capacity: 20000, Surface: 'Laykold', Location: 'London' }





