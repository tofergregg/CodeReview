string decode(string seq) {
	int addCount;
	int subCount;
	Queue<int> output;
	Queue<string> q;
	for (char c : seq) {
		sequence.enqueue(c);
	}
	if (q.peek() == "I") {
		output.enqueue(1);
		while (!q.isEmpty()) {
			char c = q.dequeue();
			while (c != "I") {
				addCount++;
			}
			if (c == "I") {
				output.enqueue(output.peek()+addCount);
		} 
	}	
	if (q.peek() == "D") {
		while (!q.isEmpty()) {
			char c = q.dequeue();
			while (c != "D") {
				subCount++;
			}
			if (c == "D") {
				output.enqueue(output.peek()-subCount);
		}
	}	
	string final;
	while (!output.isEmpty()) {
		final += integerToString(output.dequeue());
	}
	return final;
}
			
