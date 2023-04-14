//define a function to parse an xml string

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libxml/parser.h>
#include <libxml/tree.h>
#include <libxml/xpath.h>
#include <libxml/xpathInternals.h>
#include <libxml/xinclude.h>

int main(int argc, char **argv)
{
  xmlDocPtr doc;
  xmlXPathContextPtr ctxt;
  xmlXPathObjectPtr obj;
  xmlNodeSetPtr nodeset;
  xmlNodePtr node;
  xmlChar *str;
  int i;

  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <xml-string>\n", argv[0]);
    exit(1);
  }

  doc = xmlParseDoc(argv[1]);
  if (doc == NULL) {
    fprintf(stderr, "Could not parse document\n");
    exit(1);
  }
  ctxt = xmlXPathNewContext(doc);
  if (ctxt == NULL) {
    fprintf(stderr, "Could not create context\n");
    exit(1);
  }
  ctxt->node = xmlDocGetRootElement(doc);
  if (ctxt->node == NULL) {
    fprintf(stderr, "Could not find root element\n");
    exit(1);
  }
  obj = xmlXPathEvalExpression(BAD_CAST "//*", ctxt);
  if (obj == NULL) {
    fprintf(stderr, "Could not evaluate expression\n");
    exit(1);
  }
  nodeset = obj->nodesetval;
  if (nodeset == NULL) {
    fprintf(stderr, "Could not get nodeset\n");
    exit(1);
  }
  for (i=0; i<nodeset->nodeNr; i++) {
    node = nodeset->nodeTab[i];
    if (node->type == XML_ELEMENT_NODE) {
      str = xmlNodeGetContent(node);
      if (str!= NULL) {
	printf("%s\n", str);
	xmlFree(str);
      }
    }
  }
  xmlXPathFreeObject(obj);
  xmlXPathFreeContext(ctxt);
  xmlFreeDoc(doc);
  return 0;
}