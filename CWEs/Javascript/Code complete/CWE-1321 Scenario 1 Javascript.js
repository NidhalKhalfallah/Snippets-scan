const TennisStadiumPrototype = {
  Capacity: 23771,
  Surface: 'Laykold',
  Location: 'New York'
};
const allowedKeys = ['Capacity', 'Surface', 'Location'];
//Write a function to update the tennis stadium prototype with data received from the user.
function updateTennisStadiumPrototype(prototype, data) {
  for (let key in data) {
    prototype[key] = data[key];
  }

  return prototype;
}
