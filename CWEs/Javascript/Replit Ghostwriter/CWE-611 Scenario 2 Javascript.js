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
  const xml_shoes_document_string = xml_shoes_document.toString();

  const request = axios.post(recipient_url, {
    headers: {
      'Content-Type': 'application/xml',
    },
    data: xml_shoes_document_string,
  });
  return request;
}