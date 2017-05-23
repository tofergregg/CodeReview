string decode(string seq) {
	string output;
	Queue<char> currentQueue;
	Vector<int> options;
	//Fill with available options.
	for (int i = 1; i <= 9; i++) {
		options.add(i);
	}
	//Create a queue with all the letters in the sequence.
	for (int i = 0; i < seq.length(); i++) {
		currentQueue.enqueue(seq[i]);
	}
	char firstChar = currentQueue.dequeue();
	if (firstChar == 'I') {
		output += stringToInteger(1);
		options.remove(0);
	} 
	char currentChar = firstChar;
	char nextChar;
	while(!currentQueue.isEmpty()) {
		//This strategy is to count the numbers of D's following
		//I, which allows us to choose a lowest number.
		if (currentChar = 'I') {
			int counter = 0;
			char nextChar = currentQueue.dequeue();
			while (nextChar == 'D') {
				counter += 1;
				nextChar = currentQueue.dequeue();
			}
			if (counter == 0) {
				output += integerToString(options[0]);
				options.remove(0);
			} else {
				for (int i = counter; i > 0; i--) {
					output += integerToString(options[i]);
					options.remove(i);
				}
			}
		} //for the case where currentChar is the letter D.
		else {
			nextChar = currentChar;
			while (nextChar == 'D') {
				counter += 1;
				nextChar = currentQueue.dequeue();
			}
				for (int i = counter; i > 0; i--) {
					output += integerToString(options[i]);
					options.remove(i);
				}
			//Add extra number that is the lowest value.
			output += integerToString(options[0]);
			options.remove(0);
			
		}
		nextChar = currentChar;
	}
	return output;
}
		
					
				
				
		
		
