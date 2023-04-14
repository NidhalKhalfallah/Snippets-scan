import os
import cgi
def print_html_page_address():
  html_page_address = os.getenv("HTML_PAGE_ADDRESS")
  #Print the HTML page address
  print("<html>")
  print("<head>")
  print("<title>Hello World</title>")
  print("</head>")
  print("<body>")
  print("<h1>Hello World</h1>")
  print("<p>Hello World</p>")
  print("<p>Hello World</p>")
  print("<p>Hello World</p>")
  print("<p>Hello World</p>")
  