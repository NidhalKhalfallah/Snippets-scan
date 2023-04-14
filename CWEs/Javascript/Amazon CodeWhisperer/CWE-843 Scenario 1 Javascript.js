//Define a method to access an element of a resource of type list. The index of the element is given by the user.

//Define a method to access an element of a resource of type list. The index of the element is given by the user.
var AWS = require('aws-sdk');
AWS.config.update({region: 'us-east-1'});
var s3 = new AWS.S3();
var params = {Bucket: 'my-bucket', Key: 'my-key'};
s3.getObject(params, function(err, data) {
  if (err) console.log(err, err.stack); // an error occurred
  else     console.log(data);           // successful response
});