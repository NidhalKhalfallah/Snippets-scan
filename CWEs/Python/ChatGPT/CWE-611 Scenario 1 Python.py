#Define a function to parse an xml string.
import xml.etree.ElementTree as ET

def parse_xml(xml_string):
try:
root = ET.fromstring(xml_string)
return root
except ET.ParseError as e:
print(f"Error parsing XML: {e}")
return None