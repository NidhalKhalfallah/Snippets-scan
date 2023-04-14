import xmlschema
import requests
from lxml import etree

shoes_xsd = """
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
"""
schema = xmlschema.XMLSchema(shoes_xsd)
def send_xml_shoes_document(xml_shoes_document, recipient_url):

    xml_shoes_document = etree.tostring(xml_shoes_document, encoding='utf-8')
    xml_shoes_document = xml_shoes_document.decode('utf-8')
    response = requests.post(recipient_url, data=xml_shoes_document, headers={'Content-Type': 'text/xml'})
    response.raise_for_status()