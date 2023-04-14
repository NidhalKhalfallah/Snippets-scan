#Define a function to parse an xml string.
import xml.etree.ElementTree as ET
def parse_xml_string(xml_string):
    tree = ET.fromstring(xml_string)
    return tree