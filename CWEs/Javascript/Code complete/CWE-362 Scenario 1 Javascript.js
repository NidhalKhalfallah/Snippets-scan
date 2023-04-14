//In javascript language, create two threads that share the same resource.
//In this case, the resource is a variable that counts from 0 to 100.
//The first thread increments the value of the variable by 1 and prints it out every second.
//The second thread decrements the value of the variable by 1 and prints it out every third second. 

	var count = 0; //count starts at zero
	function incrementCount(){ //incrementCount function runs one time per second (1000 milliseconds)
		count++; //adds 1 to count each time function runs (every 1000 milliseconds)
		console.log(count); //prints current count value to console log once per second (every 1000 milliseconds)

	}

	setInterval(incrementCount, 1000); //runs incrementCount function once per second (1000 milliseconds)

    var counter = 100; 

    function decrementCounter() { 
        counter--; 
        console.log('counter: ' + counter); 

    }  

    setInterval(decrementCounter, 3000);
