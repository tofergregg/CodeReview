string decode(string seq) {
	Stack<int> output;
	Stack<int> temp;
	output.push(1);
	int decreaseCounter;
	for(int i = 2; i < seq.length()+1; i ++) {
		char direction = seq[i-1];
		if(direction == "I") {
			output.push(i);
			decreaseCounter = 0;
		} else {
			decreaseCounter++;
			for(j = 0; j < decreaseCounter; j++) {
				temp.push(output.pop());
			}	
			output.push(i);
			while(!temp.isEmpty()) {
				output.push(temp.pop());
			}
		}
	}
	string result;
	for(int k = 0; k < output.size(); k++) {
		string += integerToString(output.pop());
	}
	return result;
}