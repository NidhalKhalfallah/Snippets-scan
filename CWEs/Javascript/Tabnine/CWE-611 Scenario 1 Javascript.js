//define a function to parse an xml string
function parseXML(xmlString) {
    var xmlDoc = null;
    if (window.DOMParser) {
        var parser = new DOMParser();
        xmlDoc = parser.parseFromString(xmlString, "text/xml");
    } else {
        xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
        xmlDoc.async = "false";
        xmlDoc.loadXML(xmlString);
    }
    return xmlDoc;
}