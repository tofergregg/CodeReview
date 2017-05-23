string decode(string seq) {
	Queue<char> sequence; // Creates a queue of all increase/decrease commands
	for (int i=0; i<seq.length(); i++) {
		sequence.enqueue(seq.at(i));
	}
	
	Set<int> digits; // Will use to keep track of used ints
	for (int i=1; i<=9; i++) {
		digits.add(i);
	}
	
	string concatenate;
	int currentnumber = 1; // initializes to zero
	for (int i=0; i<sequence.size(); i++) {
		char command = sequence.dequeue();
		if (command == 'I' && sequence.peek() == 'I') {
			currentnumber += 1;
			concatenate += integerToString(start + i);	
		}
		if (command.peek() == 'D')
			if (command == 'I') {
				
			int counter = 1;
			while (command == 'D') {
				if (sequence.peek() == 'D') {
					command = sequence.dequeue();
					counter++;
				}
			}
			for (int i1=counter + currentnumber; i1>counter; i1--) {
				concatenate += integerToString(i1);
			}
		}	
	}
}
// Unfinished. Sorry fam.
				
			
			
			
		