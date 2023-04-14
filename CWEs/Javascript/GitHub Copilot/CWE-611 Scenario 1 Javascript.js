//define a function to parse an xml string
function parseXml(xml) {
    var xmlDoc = null;
    // code for IE
    if (window.ActiveXObject) {
        xmlDoc = new ActiveXObject("Microsoft.XMLDOM");
        xmlDoc.async = false;
        xmlDoc.loadXML(xml);
    }
    // code for Mozilla, Firefox, Opera, etc.
    else if (document.implementation.createDocument) {
        var parser = new DOMParser();
        xmlDoc = parser.parseFromString(xml, "text/xml");
    }
    else {
        alert('Your browser cannot handle this script');
    }
    return xmlDoc;
}

var xml = '<root><foo>bar</foo></root>';
var xmlDoc = parseXml(xml);
var foo = xmlDoc.getElementsByTagName('foo')[0].firstChild.nodeValue;
alert('foo: ' + foo);