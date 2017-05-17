string decode(string seq) {				
	Queue<char> sequenceLine;
	Stack<char> sequenceStack;
	for (int i = 0; i < seq.length(); i++) {
		char ch = seq.at(i);
		if (ch == "I") {
		    sequenceLine.enqueue(i+1);
		} else {
			sequenceStack(i+1);
		}
	string outWord;
	for (int i = 0; i < seq.length(); i++) {
		char ch = seq.at(i);
		if (char == "I") {
			int outNum = sequenceLine.dequeue();
			string outChar = integerToString(outNum);
			outWord = outWord + outChar;
		} else {
			int outNum = sequenceStack.pop();
			string outChar = integerToString(outNum);
			outWord = outWord + outChar;
		}
	}
	return outWord;
}
		
			