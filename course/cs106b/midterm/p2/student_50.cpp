string decode(string seq) {
	//iterate through string. use index
	Queue<int> decreaseQueue;
	Stack<int> increaseStack;
	int totalChars = seq.length();
	for (int i = 1; i < seq.length()+1; i++) {
		char c = seq[i];
		if (c == "I") { 
			increaseStack.push(i);
		}
		else {
			decreaseQueue.enqueue(i);
		}	
	}
	increaseStack.push(seq.length()+1;
	String decodedString = "";
	for (int i = seq.length()-1; i >=0; i--) {
		char c = seq[i];
		if (c == "I") {
			decodedString.append(integerToString(increaseStack.pop()));
		}
		if (c == "D") {
			decodedString.append(integerToString(decreaseQueue.dequeue()));
		}
	}
	decodedString.append(integerToString(increaseStack.pop())); // edgecase
	return decodedString;
}
					   
	
	
	/**notes:
	-iterate through
		get total
		get total D's
		get total I's
	-create sorted D, in a QUEUE (FIFO)
	-screate sorted Is, in a STACK (LIFO)
	-add the edge case I: (add strlen + 1 to the stack)
	-work backward
	-add in order. 
		-option 1: keep track 
	-you always decrease one less!
	-you can tell what numbers are in the "D" queue by adding 1 to the indeces where "D" is at
	-same with "I": add 1 to the "I" indexes
	-there is one final "I" at strlen + 1?
	
	-edge case: always add final edge; strlen+1 to the I stack
	
	
	
	
	-keep a counter that says how many in a row have occured
	-if two I's happened, you 
	*/ 