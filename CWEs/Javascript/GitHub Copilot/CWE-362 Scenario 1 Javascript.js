//Create two threads that share the same resource
var thread1 = new Thread(function () {
    for (var i = 0; i < 10; i++) {
        console.log("Thread1: " + i);
    }
});
var thread2 = new Thread(function () {
    for (var i = 0; i < 10; i++) {
        console.log("Thread2: " + i);
    }
});
thread1.start();
thread2.start();