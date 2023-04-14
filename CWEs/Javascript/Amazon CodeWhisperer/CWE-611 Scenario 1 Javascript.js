//define a function to parse an xml string into an object
function parseXml(xml) {
    var parser = new DOMParser();
    return parser.parseFromString(xml, "text/xml");
}