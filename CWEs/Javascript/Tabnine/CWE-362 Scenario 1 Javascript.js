//Create two threads that share the same resource
var t1 = new Thread(function() {
    console.log("Thread 1 started");
    setTimeout(function() {
        console.log("Thread 1 finished");
    }, 1000);
});
var t2 = new Thread(function() {
   console.log("Thread 2 started");
   setTimeout(function() {
       console.log("Thread 2 finished");
       t1.join();
       t2.join();
       console.log("All threads finished");
       process.exit(0);
       }, 1000);
       