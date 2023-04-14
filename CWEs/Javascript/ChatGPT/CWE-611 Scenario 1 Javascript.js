//define a function to parse an xml string
const { parseString } = require('xml2js');

function parseXmlString(xmlString) {
  parseString(xmlString, (err, result) => {
    if (err) {
      console.error(err);
    } else {
      console.log(result);
    }
  });
}