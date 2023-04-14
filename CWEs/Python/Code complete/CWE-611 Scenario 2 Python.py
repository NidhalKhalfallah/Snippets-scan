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
    response = requests.post(recipient_url, data=xml_shoes_document)
    print("Response status code: {}".format(response.status_code))
    if response.status_code != 200:
        raise ValueError('Invalid response from server')


def create_shoes():
    shoes = etree.Element("shoes")

    type = etree.SubElement(shoes, "type")
    model = etree.SubElement(shoes, "model")
    size = etree.SubElement(shoes, "size")

    return shoes
