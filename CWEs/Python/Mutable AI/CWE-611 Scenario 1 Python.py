#Define a function to parse an xml string.
import xml.etree.ElementTree as ET

def parseXML(xml_string):
    try:
        root = ET.fromstring(xml_string)
        return root
    except:
        print("error in parseXML")
        return None