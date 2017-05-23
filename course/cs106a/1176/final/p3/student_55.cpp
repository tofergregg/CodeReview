string decode(string seq) {
	// declare output
	Queue<int> outputQueue;
	string outputString = "";
	
	// calculate outputLength
	int outputLength = seq.length() +1:
	// populate set of possible numbers
	Set<int> nums
	for (int i = 1; i <= outputLength, i++){
		nums.add(i);
	}
	// load string into queue of characters
	//Queue<char> seqQue;
	//for (int i = 0; i < seq.length(), i++){
	//	seqQue.enqueue(seq[i]);
	//}
	
	// If first character is D
	if (seq[0] == 'D'){
		outputQueue.enqueue(outputLength);
		// remove from set of avaiable numbers
		nums-=outputlength;
	}
	
	// If first character is I 
	if (seq[0] == 'I'){
		outputQueue.enqueue(1);
		// remove from set of avaiable numbers
		nums-=outputlength;
	}
	
	// loop through remaining letters in sequence
	for (int i = 1; i < seq.length(); i++){
		
		// dequeue to a stack?
	}
	
	
	// maybe try counting the number of I's and D's?

	
	// print out result
	while(!outputQueue.isEmpty()){
		outputString += integerToString(outputQueue(dequeue));
	}

}