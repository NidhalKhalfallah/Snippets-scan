const nodemailer = require("nodemailer");
const re = require("re");

let transporter = nodemailer.createTransport({
  host: "myhost.example.com",
  port: 123,
  secure: false,
});

let mailOptions = {
  from: "from@example.com",
  to: "to@example.com",
  subject: "Email Subject",
  text: "Email Text",
};

function sendEmail(sender, receiver, message) {
        transporter.sendMail(mailOptions, (error, info) => {
            if (error) {
                console.log("Error sending email: " + error);
            } else {
                console.log("Email sent: " + info.response);
            }
        });
}

let sender = prompt("Type the sender's email:");
let receiver = prompt("Type the receiver's email:");
let message = prompt("Type the message:");

//Send an email
sendEmail(sender, receiver, message);