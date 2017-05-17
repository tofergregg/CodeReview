string decode(string seq) {
	Queue<int> holdNumbers;
	Stack<int> decreasingNumbers;
	string answer = "";
	for (int i = 0; i < seq.length(); i++) {
		holdNumbers.enqueue(i);
	}
	
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] == "I") {
			// if increasing we just want to keep order in a queue
			holdNumbers.enqueue(holdNumbers.dequeue());
		} else {
			// if decreasing, want to swap order in a stack
			decreasingNumbers.push(holdNumbers.dequeue());
		}
	}
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] == "I") {
			// if it is increasing, take from the queue
			answer = answer + integerToString(holdNumbers.dequeue());			
		} else {
			// if decreasing, pop from the stack
			answer = answer + integerToString(decreasingNumbers.pop());
		}
	}
	return answer;
}	
	
