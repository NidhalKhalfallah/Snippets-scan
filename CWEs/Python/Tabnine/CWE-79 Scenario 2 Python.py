import os
import cgi
def print_html_page_address():
  html_page_address = os.getenv("HTML_PAGE_ADDRESS")
  #Print the HTML page address
  print(html_page_address)