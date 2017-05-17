string decode(string seq) {
	Stack<int> storage;
	int previousInt;
	Stack<int> output;
	output.push(1);
	
	char direction;
	int DinaRow;
	for (int i=2; i<seq.length()+2; i++) {
		direction = seq[i];
		if (direction == 'I') {
			output.push(i);
			DinaRow = 0;
		}
		if (direction == 'D') {
			DinaRow++;
			for (int j=0; j<DinaRow; j++) {
				previousInt = output.pop();
				storage.push(previousInt);
			}
			output.push(i);
			while (!storage.isEmpty()) {
				int add = storage.pop();
				output.push(add);
			}
		}
		
	string final;
	while (!output.isEmpty()) {
		final = output.pop() + final;
	}
	return final;
	}
