string decode(string seq) {
	Stack<int> inc;
	Stack<int> dec;
	for (int i=1; i<10; i++) {
		inc.push(i);
		dec.push(10-i);
	}
	Queue<int> result;
	// first value
	if (seq[0]=='I') {
		result.enqueue(1);
	} else {
		result.enqueue(2);
	}
	
	for (int i=1; i<seq.size(); i++) {
		if (seq[i] == 'I') {
			result.enqueue(inc.pop);
		} else {
			result.enqueue(dec.pop);
		}
	}
	string output;
	for (int i=0; i<result.size(); i++) {
		output+=result.dequeue();
	}
	return output;
}
