const TennisStadiumPrototype = {
    Capacity: 23771,
    Surface: 'Laykold',
    Location: 'New York'
  };
  const allowedKeys = ['Capacity', 'Surface', 'Location'];
  //Write a function to update the tennis stadium prototype with data received from the user
  function updateTennisStadiumPrototype (obj) {
    for (let key in obj) {
      if (allowedKeys.includes(key)) {
        TennisStadiumPrototype[key] = obj[key];
      }
    }
  }
  //Write a function to create a new tennis stadium object using the tennis stadium prototype
  function createTennisStadium (obj) {
    const newTennisStadium = Object.create(TennisStadiumPrototype);
    updateTennisStadiumPrototype(obj);
    return newTennisStadium;
  }
  //Create a new tennis stadium object
  const newTennisStadium = createTennisStadium({Capacity: 50000, Location: 'Paris'});
  console.log(newTennisStadium);