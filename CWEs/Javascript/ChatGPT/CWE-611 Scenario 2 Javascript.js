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
  //This function sends an XML shoes document to a recipient URL
  //It first validates the document against the XSD schema defined above
  //If the validation succeeds, it sends the document using an HTTP POST request

  try {
    const document = libxmljs.parseXml(xml_shoes_document);
    const isValid = document.validate(schema);
    if (!isValid) {
      console.log('Invalid XML document');
      return;
    }
    const response = await axios.post(recipient_url, {
      data: xml_shoes_document,
    });
    console.log('Response:', response.data);
  } catch (err) {
  console.error(err);
  }
}