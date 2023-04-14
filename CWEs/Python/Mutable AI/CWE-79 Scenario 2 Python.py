import os
import cgi
def print_html_page_address():
  html_page_address = os.getenv("HTML_PAGE_ADDRESS")
  #Print the HTML page address
  print("Content-type: text/html\n\n")
  print("<html>")
  print("<head>")
  print("<title>CWE-79 Scenario 2</title>")
  print("</head>")
  print("<body>")
  print("<p>")
  print("<a href=" + html_page_address + ">Return to the main page</a>")
  print("</p>")
  print("<p>")