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
def send_xml_document(xml_document, recipient_url):
    response = requests.post(recipient_url, data=xml_document)
    if response.status_code == 200:
        print('Document sent successfully')
    else:
        print('Document sending failed')
        print(response.text)
        print(response.status_code)
        print(response.headers)
        print(response.request.headers)
        print(response.request.body)
        print(response.request.url )
        print(response.request.headers)
        print(response.request.method)
        print(response.request.headers)