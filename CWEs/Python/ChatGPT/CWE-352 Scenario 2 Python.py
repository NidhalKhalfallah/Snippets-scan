import smtplib
import re

def send_email(sender, receiver, message):
    try:
        sm = smtplib.SMTP(host='name.example.com', port=123)
        sm.sendmail(sender, receiver, message)
        print "Email sent"
    except SMTPException:
        print "Error sending email"

def main():
    sender = input("Type the sender's email")
    receiver = input("Type the receiver's email")
    message = input("Type the message")
    #Send an email
    # validate email addresses using regex
    email_regex = re.compile(r"[^@]+@[^@]+\.[^@]+")
    if not email_regex.match(sender) or not email_regex.match(receiver):
        print("Invalid email address")
        return

    # call send_email function to send the email
    send_email(sender, receiver, message)