string decode(string seq) {
	Queue<char> sequenceCollection;
	int seqLength = seq.length();
	int i = 0;
	Vector<int> numbers;
	for(int j = 1; j <= seqLength() + 1; j++) {
		number.add(j);
	}
	
	while(true) {
		if(seqLength) == 0) {
			break;
		}
		char letter = seq.[0];
		// first time through
		if(i = 0) {
			if(letter == "I") {
				sequenceCollection.enqueue(1);
				numbers.remove(1);
			} else if(letter == "D") {
				sequenceCollection.enqueue(seqLength + 1);
				numbers.remove(seqLength + 1);
			}
			i++;
			seqLength--;
		}
		
		// remaining times
		if(i != 0) {
			if(letter == "I" && seq.find("D") == string::npos) {
				sequenceCollection.enqueue(numbers.get(0));
			} else if(letter == "I" && seq.find("D") != string::npos) {
				sequenceCollection.enqueue(number.get(seqLength));
			} else if(letter == "D" && seq.find("I") == string::npos) {
				sequenceCollection.enqueue(numbers.get(0));
			} else if(letter == "D" && seq.find("I") != string::npos) {
				sequenceCollection.enqueue(number.get(seqLength));
			}
			seqLength--;
		}
	}
		
	// prepares final string to return
	string fullString;
	while(!sequenceCollection.isEmpty()) {
		int number = sequenceCollection.dequeue();
		string toAdd = integerToString(number);
		fullString += toAdd;
	}
	return fullString;
}
			
		
		
		
		
		
		
		
	