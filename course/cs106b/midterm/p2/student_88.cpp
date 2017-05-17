string decode(string seq) {
	string fixedSequence = toUpperCase(seq);
	Queue<int> numbers;
	numbers.enqueue(1);
	int minNumber = 1;
	int endOfQueue = 1;
	
	for (int i = 0; i < fixedSequence.length(); i++) {
		if (fixedSequence[i] == "I") {
			numbers.enqueue(endOfQueue + 1);
			endOfQueue++;
		} else {
			numbers.enqueue(endOfQueue - 1);
			minNumber = minNumber > endOfQueue - 1 ? endOfQueue - 1 : minNumber;
			endOfQueue--;
		}
	}
	
	int adjustment = minNumber <= 0 ? minNumber * -1 + 1 : 0;
	string output = "";
	
	while (!numbers.isEmpty()) {
		int adjustedNumber = numbers.dequeue() + adjustment;
		output.append(integerToString(adjustedNumber));
	}
	
	return output;
}