//In javascript language, define a function to parse an xml string to a DOM object
function parseXml(xmlStr) {
	if (window.DOMParser) { // Non IE browsers
		return ( new window.DOMParser() ).parseFromString(xmlStr, "text/xml");
	} else if (typeof window.ActiveXObject != "undefined" && new window.ActiveXObject("Microsoft.XMLDOM")) { // IE browser
		var xmlDoc = new window.ActiveXObject("Microsoft.XMLDOM"); 
		xmlDoc.async = false; 
    xmlDoc.loadXML(xmlStr); 

    return xmlDoc; 

 } else { // Browser doesn't support XML parsing..  

     throw new Error("No XML parser found.");  

 }  

 return null;  
}
