string decode(string seq) {
	Queue<int> output;
	Set<int> remaining;
	
	//Have a set of remaining ints to use in helper function
	for(int i = 0; i < 9; i++) {
		remaining.add(i+1);
	}
	
	//Begins helper function with output starting at every #1-9
	for(int i = 0; i < 9; i++) {
		output.clear();
		output.enqueue(i+1);
		decodeHelper(output, seq, remaining);
	}
	
	//converts output queue into a string of numbers
	if(!q.isEmpty()) {
		int i = output.dequeue();
		string str += integerToString(int i);
	}
	
	//get lowest
	
	return i;
	
}

Queue<int> decodeHelper(Queue<int> &output, string &seq, Set<int> &remaining) {
	remaining.remove(output[i]);
	
	//Gets the length of the sequence so can stop the recursion if sequence is less than 8, I just used this as a way to prevent using n in the for loop later if that makes sense.
	int n = seq.length();
	
	//if given an empty sequence string
	if(seq.length() == 0) return;
	
	//base case
	if(remaining.size() == 0 || n == 0) {
		return output;
	}
	//recursive case
	for(int i = 0; i < 8; i++) { //for each char in sequence
		if(seq[i] == 'I') {
			if(i > output[i]) {
				output.enqueue(i);
				remaining(remove(i);
				decodeHelper(output, seq.subtr(1), remaining);
				n--;
			}
		}
		else if(seq[i] == 'D') {
			if(i < output[i]) {
				output.enqueue(i);
				remaining.remove(i);
				decodeHelper(output, seq.subtr(1), remaining);
				n--;
			}
		}
	}
}