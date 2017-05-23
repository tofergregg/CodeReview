/* Pseudocode - To avoid repeats, I am using a queue to store all my digits from 1 to 9. From the queue, I will be able to take out the numbers that are necessary. 
First I am going to read in the sequence
If increase: get out the first value
If decrease: make a copy of the queue except in reverse, go to the last one of the queue
Return a string
*/
string decode(string seq) {
	string numbers = "";
	Queue<int> digits;
	//initialize the queue
	for (int i = 1; i <= 9; i++){
		digits.enqueue(i);
	}
	for (int j = 0; j < seq.size() - 1; j++){
		if (seq.at(j) == 'I'){
			int peek = digits.peek();
			// convert the queue number to a string
			string peekString = "" + peek; 
			number += peek;
			digits.dequeue();
		} else {
			if (seq.at(j) == 'D'){
				// reverse the queue
				
			}
			// revert the queue back to normal again
	}
	return numbers;
	
}