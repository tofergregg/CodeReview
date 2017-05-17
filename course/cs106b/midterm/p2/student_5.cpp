string decode(string seq) {
	Queue<int> finalQueue;
	Stack<int> interStack; // used to refer to last number of interest
	Stack<int> decreaseStack;
	finalQueue.enqueue(1);
	interStack.push(1);
	// arrange the numbers in the correct order on finalQueue
	// attempting to differentiate between the cases where the sequence increases and then increases, increases and then decreases, decreases and then increases, or decreases and then decreases
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i + 1] == 'I' && i + 1 < seq.length()) {
			if (seq[i] == 'I') {
				int curr = interStack.peek() + 1;
				finalQueue.enqueue(curr);
				interStack.push(curr);
			} else {
				decreaseStack.push(interStack.peek() + 1);
		} else if (seq[i + 1] == 'D' && i + 1 < seq.length()) {
			if (seq[i] == 'I') {
				int curr = interStack.peek() + 1;
				decreaseStack.push(curr);
				interStack.push(curr);
			} else {
				decreaseStack.push(interStack.peek() + 1);
		} else {
			if (seq[i] == 'I') {
				finalQueue.enqueue(interStack.peek() + 1);
			} else {
				finalQueue.enqueue(interStack.peek() - 1);
	}
	while (!decreaseStack.isEmpty()) {
		finalQueue.enqueue(decreaseStack.pop());
	//assuming that the finalQueue now has the numbers in order			
	string final = "";
	while (!finalQueue.isEmpty()) {
		final += integerToString(finalQueue.dequeue());
	}
	return final;
}
	