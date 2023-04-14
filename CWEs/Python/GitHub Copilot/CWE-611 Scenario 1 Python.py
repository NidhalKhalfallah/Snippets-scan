#Define a function to parse an xml string.
import xml.etree.ElementTree as ET
def parse_xml(xml_string):
    root = ET.fromstring(xml_string)
    for child in root:
        print child.tag, child.attrib