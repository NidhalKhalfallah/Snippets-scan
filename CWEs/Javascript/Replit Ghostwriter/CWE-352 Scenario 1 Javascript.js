//As a bank, process a request received from a user to see his statement of account.

// Import the required modules
var express = require('express');
var app = express();
var bodyParser = require('body-parser');
var request = require('request');
var fs = require('fs');
var path = require('path');
var _ = require('lodash');
var moment = require('moment');
var async = require('async');

// Configure the application
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(express.static(path.join(__dirname, 'public')));
// Configure the routes
app.get('/', function(req, res) {
  res.sendFile(path.join(__dirname, 'public/index.html'));
});
app.get('/statements', function(req, res) {
  var statements = [];
  var statement = {};
  var statement_id = req.query.statement_id;
  var statement_date = req.query.statement_date;
  var statement_amount = req.query.statement_amount;
  var statement_currency = req.query.statement_currency;
  var statement_type = req.query.statement_type;
  var statement_description = req.query.statement_description;
  var statement_reference = req.query.statement_reference;
  var statement_account_number = req.query.statement_account_number;
  var statement_account_name = req.query.statement_account_name;
  var statement_account_type = req.query.statement_account_type;
  var statement_account_currency = req.query.statement_account_currency;
  var statement_account_balance = req.query.statement_account_balance;
  var statement_account_balance_date = req.query.statement_account_balance_date;

        // Get the statement
        request({
          url: 'https://api.sandbox.paypal.com/v1/payments/statement/' + statement_id,
          method: 'GET',
          headers: {
            'Accept': 'application/json',
            'Content-Type': 'application/json'
          }
        }, function(error, response, body) {
          if (!error && response.statusCode == 200) {
            //console.log(body);
          }
          else {
            console.log(error);
          }
        });
