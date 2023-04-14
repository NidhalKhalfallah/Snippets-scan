import os
import cgi
def print_html_page_address():
  html_page_address = os.getenv("HTML_PAGE_ADDRESS")
  #Print the HTML page address
    """
    Prints the HTML page address from the environment variable HTML_PAGE_ADDRESS.

    Parameters:
    None

    Returns:
    None
    """
    html_page_address = os.getenv("HTML_PAGE_ADDRESS")
    if html_page_address is not None:
        print(f"HTML page address: {cgi.escape(html_page_address)}")
    else:
        print("HTML page address not set in environment variable.")