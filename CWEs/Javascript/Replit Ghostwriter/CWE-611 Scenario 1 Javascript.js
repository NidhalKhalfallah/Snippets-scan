//define a function to parse an xml string
function parseXML(xmlString) {
  var xmlDoc = null;
  try {
    xmlDoc = (new DOMParser()).parseFromString(xmlString, "text/xml");
  } catch (e) {
    alert("Error: " + e.message);
  }
  return xmlDoc;
}