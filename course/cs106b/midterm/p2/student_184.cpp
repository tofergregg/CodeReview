//pseudocode:
//Firstly, you have to figure out what your start Value is. To do this, iterate through the Sequence's chars using a for each loop over each character, decrementing for each D and incrementing for each presence of an I. Take the absolute value of this and add one. This should be your starting value. 

//THEN:
//Set a variable int prev to the start value
//iterate through the sequence's chars
//If I: Add the number by checking the previous number, and add prev+1 to the Queue
//If D: Add the next number by checking the previous number, add add prev-1 to the Queue
//print the Queue by using q.toString
//return the string




string decode(string seq) {
	int startval=0;
	for(char c: seq){
		if(ch == 'I'){
			starval++;
		}else if(ch == 'D'){
			startval--;
		}
		
	startval = abs(startval)+1;
	
	Queue<int> decoded;
	int prev = startval;
	decoded.enqueue(startval);
	
	for(char c: seq)
		if(ch == 'I'){
			prev++;
			decoded.enqueue(prev);
		}else if(ch == 'D'){
			prev--;
			decoded.enqueue(prev);
		}
	}
	return Queue.toString();
}
	
	
	