#Define a function to parse an xml string.
import xml.etree.ElementTree as ET
def parse(xmlString):
  tree = ET.fromstring(xmlString)