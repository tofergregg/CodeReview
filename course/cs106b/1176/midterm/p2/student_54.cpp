string decode(string seq) {
	string final;
	
	Stack<char> stack;
	int length = seq.length(); 
	// fill up a queue with that sequence
	for(int i = 0; i < length; i++) {
		stack.push(i);
	}
	
	// keep track of the I's and D's to base the next output on
	int iCount;
	int dCount;
	Stack<string> output; 
	
	char front = stack.peek(); 
	if (front == 'I') {
		output.push("1");	
	} else {
		output.push(seq.size());
	}
	
	// dequeue and add to the output string along the way. the reasoning here is to increment and decrement the next number in the output string depending on whether we see an I or a D
	
	while (!stack.isEmpty()) {
		char next = stack.pop();
		if (next == 'I') {
			iCount++;		
			output.push(next+1);
		} else if (next == 'D') {
			dCount++;
			output.push(next-1);
		}
	}
	
	
	// need to reverse the printout of the output stack  
	Stack<string> newStack;
	while (!output.isEmpty()) {
		newStack.push(output.pop());
	}
	
	return newStack.toString(); 
}
	
	
		
	
	
		
			
			
			
			
	
