//In javascript language, define a function to open an SSH connection to example.com and execute a command
//In order to do that, we need to know the host and port
var ssh = require('ssh2');
var conn = new ssh();


conn.on('ready', function() {
  console.log('Connection :: ready');

  //Use exec method to execute a command on remote server
  conn.exec('ls -l', function(err, stream) {
    if (err) throw err;

    stream.on('close', function(code, signal) {
      console.log('Stream :: close :: code: ' + code + ', signal: ' + signal);

      //Close connection once done with it! :)
      conn.end();

    }).on('data', function(data) {
      console.log('STDOUT: ' + data);

    }).stderr.on('data', function(data) {
      console.log('STDERR: ' + data);

    });;

  });;   //End of exec method call! :) ;) :D :D :D :D ;-) :-) :-) :-) :-) :-) ;-) ;-) ;-) ;) ;) ;) ;) )))))) )))))))))) ))))) ))))))) ))))) ))))))) ))))))) )))))) );-;-;;-;;-;;-;;-;;--;;;;---;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;----------------------->>
