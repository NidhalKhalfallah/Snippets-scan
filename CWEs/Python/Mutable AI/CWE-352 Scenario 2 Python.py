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
    send_email(sender, receiver, message)

if __name__ == '__main__':
    main()