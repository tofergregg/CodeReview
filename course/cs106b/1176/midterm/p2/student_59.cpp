string decode(string seq) {
	Stack<int> output;
	Queue<int> temp;
	int currValue = 1;
	output.push(currValue);
	currValue++;
	for(int i = 0; i < seq.length(); i++) {
		if(seq[i] == 'I') {
			output.push(currValue);
			currValue++;
		} else if (seq[i] == 'D') {
			int switch = output.pop();
			temp.enqueue(switch);
		}
		if (i > 0) {
			if(seq[i] == 'D' && seq[i-1] == 'I') {
				output.push(temp.dequeue());
			}
		}
	}
	// reverse the numbers in the output stack so they're in correct order
	Stact<int> reverseOutput;
	while(!output.isEmpty()) {
		reverseOutput.push(output.pop());
	}
	string result = "";
	while(!reverseOutput.isEmpty()) {
		string num = integertoString(reverseOutput.pop());
		result += num;
	}
	return result;
}