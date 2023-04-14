//In javascript language, process an HTTP POST request of sorting a list of 1000000 elements
//The request is sent to a server that sorts the list in O(n log n) time.
//Then, the client receives the sorted list and displays it on the screen.
function sortList() {

    //the following code will be executed when user clicks on "Sort List" button
    var http = new XMLHttpRequest();
    var url = "/sortlist";

    //set up callback function for HTTP response from server
    http.onreadystatechange = function () {

        if (this.readyState == 4 && this.status == 200) {

            console.log("Response received from server");
            console.log("HTTP Status: " + this.status);

            //parse JSON data from server into JavaScript object literal (an associative array) called jsonData 			
            var jsonData = JSON.parse(http.responseText);

            //display sorted list of 1000000 elements in browser window using html <table> element and <tr> table row tag 			    	        
            document.getElementById('sorted-list').innerHTML += "<table id='sorted-list'><tr><th>Sorted List</th></tr>" + "<tr><td>" + jsonData["sorted_array"] + "</td></tr></table>";            

        } else if (this.readyState == 4 && this.status != 200){   //if HTTP status is not OK...      

           alert("HTTP Error: " + this .status);              //show error message in browser window     

        } else {                                                //otherwise...      
           console.log("Waiting for response...");              //print message to console indicating waiting for response         
        }    	    	    	    	    	    	        
    };   //end of callback function definition  ... end of event handler for HTTP POST request to /sortlist route     

    httpRequestMethodAndURL(http, url, 'POST');               /*call method which sends an HTTP POST request with form data*/   /*passing three arguments - http object, URL string & method type as strings*/     
}
