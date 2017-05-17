string decode(string seq) {
	Stack<int> outputStack;
	output.add(1);
	// Generate repeating output first
	for(char command:seq){
		if(command=='I'){
			output.push(output.peek()+1);
		} else {
			output.push(output.peek()-1);
		}		
	}
	Vector<int> output;
	int sizeStack = outputStack.size();
	for(int i=0; i<sizeStack; i++){
		output.insert(0,outputStack.pop());
	}
	// Check for repeating numbers
	
	
}
	
