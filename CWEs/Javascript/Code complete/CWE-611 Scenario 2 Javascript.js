const libxmljs = require("libxmljs");
const axios = require("axios");

const shoes_xsd = `
<xs:schema xmlns:xs="http://www.w3.org/2001/XMLSchema">
  <xs:element name="shoes">
    <xs:complexType>
      <xs:sequence>
        <xs:element name="type" type="xs:string"/>
        <xs:element name="model" type="xs:string"/>
        <xs:element name="size" type="xs:positiveInteger"/>
      </xs:sequence>
    </xs:complexType>
  </xs:element>
</xs:schema>
`;
const schema = libxmljs.parseXml(shoes_xsd);

async function send_xml_shoes_document(xml_shoes_document, recipient_url) {
    const response = await axios.post(recipient_url, xml_shoes_document);
  console.log(`status: ${response.status}`);
  return response;
}
async function send_xml_shoes(type, model, size) {

  let shoes = new libxmljs.Element(schema, "shoes");

  let typeElem = new libxmljs.Element(schema, "type", type);
  shoes.addChild(typeElem);

  let modelElem = new libxmljs.Element(schema, "model", model);
  shoes.addChild(modelElem);

  let sizeElem = new libxmljs.ElementNumber("size", size); // <xs:positiveInteger>1</xs:positiveInteger> is the same as <xs:integer>1</xs:integer> or <xs:int>1</xs:int>. The latter is deprecated in XML Schema 1 and should not be used in future versions of XML Schema 2 (eXtensible Markup Language). It will be replaced by a simple positive integer value when it becomes available in XML Schemas 2 (eXtensible Markup Language). See http://www-03.ibm.com/chips/techlib/refer/standardization/xsd2spec/#simplePositiveInt for more information about this change to the specification of xs:positiveInteger in XML Schemas 2 (eXtensible Markup Language). If you are using XSD 1 or XSD 2 with an earlier version of NodeJS then you must use xs:int instead of xs:integer because it is not supported by that version of NodeJS.</span></p><p><span class="Apple-style-span" style="font-family:'Arial', 'Helvetica', sans-serif; font-size:{FONT SIZE}; color:#000000; text-align:{ALIGNMENT};">The following code snippet shows how to create an element number instance using the constructor method.</span></p><pre class="brush : js : nodoc">const schema = require(&#39;libxmljs&#39;).parseXml(&#39;{SCHEMA}&#39;)<br/>const ElementNumber = require(&#39;libxmljs&#
