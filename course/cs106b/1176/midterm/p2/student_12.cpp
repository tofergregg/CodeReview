string decode(string seq) {
	string result = "";
	nextInt = 1;
	Stack<int> nextDecreasingOutput;
	Queue<int> nextIncreasingOutput;
	if (seq.at(0) == 'I') {
		nextIncreasingOutput.enqueue(nextInt);
	} else {
		nextDecreasingOutput.push(nextInt);
	}
	for (int i = 0; i < seq.size(); i++) {
		if (seq.at(i) == 'I') {
			nextInt++;
			nextIncreasingOutput.enqueue(nextInt);
		} else {
			nextInt++;
			nextDecreasingOutput.push(nextInt);
		}
	}
	if (seq.at(0) == 'I') {
			result += nextIncreasingOutput.dequeue();
	} else {
			result += nextDecreasingOutput.pop();
	}
	for (int i = 0; i < seq.size(); i++) {
		if (seq.at(i) == 'I') {
			result += nextIncreasingOutput.dequeue();
		} else {
			result += nextDecreasingOutput.pop();
		}
	}
	return result;
}