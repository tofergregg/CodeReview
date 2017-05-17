string decode(string seq) {
	
	string output = "";
	for (int i = 1; i <= (int)seq.length() + 1; i++) {
		//append number to output of length n + 1 in increasing order
		output += integerToString(i);
	}	
	
	//create stack
	Stack <char> s = createstack(seq);
	
	
	//return changed output
	changeSequence(output,s);
}

// function to create stack with sequence
Stack<char> createStack(string seq) {	
	Stack <char> s;
	for (int i = 0; i < (int)seq.length(); i++) {
		char ch = seq[i];
		s.push(ch);
	}
	return s;
}	

//function to traverse through the stack inspecting each element removed	
string changeSequence(string output, Stack<char> s) {
	int size = s.size();
	for (int i = 0; i < size; i++) {
		char top = s.pop();
		if (top == 'D') { //swap if decreasing sequence
			char temp = output[i];
			output[i] = output[i+1];
			output[i+1] = temp;
		} 
	}
	return output;
}