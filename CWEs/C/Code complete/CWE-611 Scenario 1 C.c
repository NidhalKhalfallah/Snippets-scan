//In C language, define a function to parse an xml string
//and return a DOM tree
	xmlDocPtr doc = xmlParseMemory(xml_string, strlen(xml_string));

	if (doc == NULL) {
		printf("Document not parsed successfully.");
	}

	xmlNodePtr root = xmlDocGetRootElement(doc);

	if (root == NULL) {
		printf("empty document");
	}

	xmlNodePtr cur = NULL;
	for (cur = root->children; cur != NULL; cur = cur->next) {
		if (cur->type == XML_ELEMENT_NODE && !strcmp((char*)cur->name, "title")) {
			printf("%s", cur->children->content);
		} else if (cur->type == XML_ELEMENT_NODE && !strcmp((char*)cur->name, "link")) {
			printf("%s", cur->children->content);
		} else if (cur->type == XML_ELEMENT_NODE && !strcmp((char*)cur->name, "description")) {
    printf("%s", cur->children->content);
		} else if (cur->type == XML_ELEMENT_NODE && !strcmp((char*)cur->name, "pubDate")) {
    printf("%s", cur->children->content);
		} else if (cur->type == XML_ELEMENT_NODE && !strcmp((char*)cur->name, "guid")) {
    printf("%s", cur->children->content);
		}

  }

  xmlFreeDoc(doc);

  return 0;
}
