import os
import cgi
def print_html_page_address():
  html_page_address = os.getenv("HTML_PAGE_ADDRESS")
  #Print the HTML page address
  print "Content-type: text/html\n\n"
  print "<html>"
  print "<head>"
  print "<title>Test</title>"
  print "</head>"
  print "<body>"
  print "<h2>Test</h2>"
  print "<p>HTML page address is %s</p>" % html_page_address
  print "</body>"
  print "</html>"

print_html_page_address()