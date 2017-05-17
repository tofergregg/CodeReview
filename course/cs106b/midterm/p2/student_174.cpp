string decode(string seq) {
	Queue<int> output;
	for (int i = 1; i <= seq.length() + 1; i++) {
		output.enqueue(i);
	}
	string result = "":
	int n;
	if (seq.at(0) == 'I') {
		n = 1;
		output.pop();
	} else {
		n = seq.length() + 1;
	}
	for (int i = 1; i < seq.length() + 1; i++) {
		if (seq.at(i) == 'I') {
			while(output.peek() !> n) {
				n = output.pop();
				output.push(n);
			}
			result +=integerToString(output.pop());
		} else {
			while(output.peek() !<n) {
				output.push(output.pop());
			}
			n = output.pop();
			result +=integerToString(n);
		}
		q.add(seq.at(i);	  
	}
	return result;
}
		
	

		
		