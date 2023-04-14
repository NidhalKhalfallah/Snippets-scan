const TennisStadiumPrototype = {
  Capacity: 23771,
  Surface: 'Laykold',
  Location: 'New York'
};
const allowedKeys = ['Capacity', 'Surface', 'Location'];
//Write a function to update the tennis stadium prototype with data received from the user.

function updateTennisStadium(data) {
  let newProto = {};
  for (let key in data) {
    if (allowedKeys.includes(key)) {
      newProto[key] = data[key];
    }
  }
  return newProto;
}