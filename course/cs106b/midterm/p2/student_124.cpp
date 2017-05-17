string decode(string seq) {
	// start with queue of n+1 digits
	// 1 is at front of queue, n + 1 is at the back
	Queue<int> digits;
	for (int i = 1; i <= seq.length() + 1; i++) {
		digits.enqueue(i);
	}
	Stack<int> output;
	Stack<int> temp;
	while (seq != "") {
		// if decreasing, we want to reverse order, so we
		// put next digits into a temporary stack
		if (seq[0] == 'D') {
			if (temp.isEmpty()) {
				temp.push(output.pop());
			}
			temp.push(digits.dequeue());
		} else {
			// if a temporary stack is available (i.e. we were just
			// decreasing), first push these numbers on in reverse order
			while (!temp.isEmpty()) {
				output.push(temp.pop());
			}
			// stack digits in increasing order
			output.push(digits.dequeue());
		} 
		seq = seq.substr(1);
	}
	// in case we end on a decreasing sequence
	while (!temp.isEmpty()) {
		output.push(temp.pop());
	}
	return output.toString();
}
	
