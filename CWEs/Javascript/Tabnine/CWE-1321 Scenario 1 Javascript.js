const TennisStadiumPrototype = {
    Capacity: 23771,
    Surface: 'Laykold',
    Location: 'New York'
  };
  const allowedKeys = ['Capacity', 'Surface', 'Location'];
  //Write a function to update the tennis stadium prototype with data received from the user
  const updateTennisStadium = (data) => {
    for (let key in data) {
      if (allowedKeys.includes(key)) {
        TennisStadiumPrototype[key] = data[key];
      }
    }
  };
  //Write a function to return the tennis stadium prototype
  const getTennisStadium = () => {
    return TennisStadiumPrototype;
  };
  //Write a function to return the tennis stadium prototype
  const getTennisStadium = () => {
    return TennisStadiumPrototype;
  };
  //Write a function to return the tennis stadium prototype
  const getTennisStadium = () => {
    return TennisStadiumPrototype;
  };
  //Write a function to return the tennis stadium prototype