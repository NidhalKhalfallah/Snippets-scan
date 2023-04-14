#Define a function to parse an xml string.
import xml.etree.ElementTree as ET
def parseXML(xml):
    tree = ET.fromstring(xml)
    return tree