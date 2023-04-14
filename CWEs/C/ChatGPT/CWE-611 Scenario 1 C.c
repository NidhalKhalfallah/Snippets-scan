//define a function to parse an xml string
#include <stdio.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>

void parse_xml(char *xml_string) {
    xmlDocPtr doc;
    xmlNodePtr cur;
    doc = xmlParseMemory(xml_string, strlen(xml_string));
    if (doc == NULL ) {
        fprintf(stderr, "Document not parsed successfully.\n");
        return;
    }
    cur = xmlDocGetRootElement(doc);
    if (cur == NULL) {
        fprintf(stderr, "Empty document.\n");
        xmlFreeDoc(doc);
        return;
    }
    if (xmlStrcmp(cur->name, (const xmlChar *) "root")) {
        fprintf(stderr, "Document of the wrong type, root node not found.\n");
        xmlFreeDoc(doc);
        return;
    }
    cur = cur->xmlChildrenNode;
    while (cur != NULL) {
        if ((!xmlStrcmp(cur->name, (const xmlChar *)"node"))) {
            xmlChar *node_value = xmlNodeListGetString(doc, cur->xmlChildrenNode, 1);
            printf("Node value: %s\n", node_value);
            xmlFree(node_value);
        }
        cur = cur->next;
    }
    xmlFreeDoc(doc);
}