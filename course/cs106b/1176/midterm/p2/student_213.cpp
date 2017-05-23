string decode(string seq) {
	int initialNumber = 1;
	Queue<int> sequence;
	string initialString = seq
	return finalOutput(seq, initialNumber, sequence, initialString);
	
}

string finalOutput(string &seq, int &initialNumber, Queue<int> &sequence, string initialString) {
	int currentNumber = initialNumber;
	sequence.enqueue(currentNumber);
	if(str == "") {
		string output;
		while(!(sequence.isEmpty())) {
			int nextInt = sequence.peek();
			sequence.dequeue();
			output += integerToString(nextInt);
		} 
	} else {
		string command = seq.at(0);
		if(command == "D" && currentNumber == 1) {
			currentNumber += 1;
			sequence.clear();
			seq = initialString;
			finalOutput(seq, currentNumber, sequence, initialString);
		} else if(command == "D") {
			currentNumber = currentNumber - 1;
			seq.erase(0, 1);
			finalOutput(seq, currentNumber, sequence, initialString);
		} else if(command = "I") {
			sequence.enqueue(currentNumber);
			currentNumber = currentNumber + 1;
			seq.erase(0, 1);
			finalOutput(seq, currentNumber, sequence, initialString);
		}
	}
	return output;
}
		
		
		
		
