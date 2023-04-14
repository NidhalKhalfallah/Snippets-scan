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
    print(response.text)

def main():
    xml_shoes_document = """
    <shoes>
      <type>sneaker</type>
      <model>Jordan 1 Retro High OG</model>
      <size>12</size>
    </shoes>
    """
    send_xml_shoes_document(xml_shoes_document, "http://localhost:8000/shoes")