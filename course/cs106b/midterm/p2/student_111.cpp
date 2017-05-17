string decode(string seq) {
	string numString = "";
	Queue<int> availableNums;
	for (int n = 1; n <= 9; n++) {
		availableNums.enqueue(n);
	}
	Queue<int> attempt;
	Queue<int> tryAgain;
	int counter;
	while (!seq.isEmpty()) {
		char command = seq[0];
		if (command == 'I') {
			if (availableNums.dequeue < tryAgain.deque){
				attempt.enqueue(availableNums.dequeue());
			] else {
				attempt.enqueue(tryAgain.dequeue())
			}
			seq.remove[0];
		} else {
			counter++;
			seq.remove[0];
			int tooSmall = availableNums.dequeue();
			tryAgain.enqueue(tooSmall);
		}
		 
	}
	while (!attempt.isEmpty()){
		numString += iintegerToString(attempt.dequeue());
	}
	return numString;
}