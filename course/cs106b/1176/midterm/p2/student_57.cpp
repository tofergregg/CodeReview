// function prototype
int highestNum (string seq);

string decode(string seq) {
	int highestNum = highestNum(seq);
	// create a queue containing all numbers to be used
	Queue<int> q;
	for (int i = 1; i <= highestNum; i++) {
		// 1 will be the front of q
		q.enqueue(i);
	}
	// create an empty stack
	Stack<int> s;
	// loop over sequence to produce output
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] == 'I') {
			// add 'I''s corresponding # to output
			output += q.dequeue();
			// everytime we hit an 'I' we can unload the stack
			while(!s.isEmpty()) {
				// add the numbers popped off to output
				output += s.pop();
			}
		} else {
			// if 'D' is next in seq, add # to stack
			s.add(q.dequeue());
		}
	}
	/*
	** before returning the output, make sure all numbers 
	** left in the stack are used
	*/
	while(!s.isEmpty()) {
		output += s.pop();
	}
	return output;
}

int highestNum (string seq) {
	int sum = 0;
	int maxNum = 9;
	string output = "";
	// determine the largest number needed (1-9)
	for (int i = 0; i < seq.length(); i++) {
		if(seq[i] == 'I'){
			sum++;
		} else {
			sum--;
		}
	}
	// add one more of the same string to the end of sequence
	seq += seq(seg.length() - 1);
	return maxNum - sum;
}