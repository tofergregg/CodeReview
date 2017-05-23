string decode(string seq) {
	// go through each letter in the sequence one by one
	// check if I or D
	result = "";
	Stack<int> stack;

	int numD = 0;

	for (int i = 0; (int) i < seq.length(); i++) {
		if (seq[i] == 'I') {
			for (int i = 0; i < numD; i--) {
				result += stack.pop();
				numD--;
			}
			result += integerToString(i + 1);
		} else if (seq[i] == 'D') {
			stack.push(i + 1);
			stack.push(i + 2);
			numD++;
		}
	}
	
	for (int i = 0; i < numD; i--) {
		result += stack.pop();
		numD--;
	}
		
	return result;
}