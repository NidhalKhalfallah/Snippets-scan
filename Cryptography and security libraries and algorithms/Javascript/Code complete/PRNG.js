//Generate a winning lottery number between 0 and 1000
int winningNum = (int)(Math.random() * 1000);

		//Create a new lottery object and set the winning number to the random generated number
		Lottery lotto = new Lottery();
		lotto.setWinningNumber(winningNum);

    //Generate 5 random numbers between 0 and 1000 for each ticket, store in array
    int[] ticket1 = generateTicket(5);
    int[] ticket2 = generateTicket(5);
    int[] ticket3 = generateTicket(5);
    int[] ticket4 = generateTicket(5);

     //Print out all of the tickets  with their corresponding numbers on them, as well as the winning number if it matches any of them.   The last line should be "You won!" or "Sorry you didn't win." depending on whether or not there was a match.  If there is no match at all, print "Sorry you didn't win."   Make sure to use your method from above!

      System.out.println("Your first Ticket: "+printArray(ticket1));//prints out what's in this array using my method I created above for printing arrays out nicely...I'm sorry about how messy this code looks but I just wanted to get it done before class ends so that I can come back later and clean it up! -Mikey McMichaelface-");//prints out what's in this array using my method I created above for printing arrays out nicely...I'm sorry about how messy this code looks but I just wanted to get it done before class ends so that I can come back later and clean it up! -Mikey McMichaelface-");//prints out what's in this array using my method I created above for printing arrays out nicely...I'm sorry about how messy this code looks but I just wanted to get it done before class ends so that I can come back later and clean it up! -Mikey McMichaelface-");//prints out what's in this array using my method I created above for printing arrays out nicely...I'm sorry about how messy this code looks but I just wanted to get it done before class ends so that I can come back later and clean it up! -Mikey McMichaelface-");System.out.println("Your second Ticket: "+printArray(ticket2));System.out.println("Your third Ticket: "+printArray(ticket3));
