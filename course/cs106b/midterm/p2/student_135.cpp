//DONT FORGET TO ACCOUNT FOR THE EDGE CASES

string decode(string seq) {
	Set<int> numbers;
	Queue<string> sequence;
	Stack<int> output;
			
	// Generate set of numbers 1-9
	for (int n = 1; n <= 9; n++) { // O(N) time
		numbers.add(n);
	}
	
	// Ensures that the first numbers are a reasonable value depending
	// on the first letter of the input sequence
	if (equalsIgnoreCase(seq[0], "I") {
		output += 1;
		numbers.remove(1);
	} else {
		output += 5;
		numbers.remove(5);
	}
		
	// For each letter in the sequence, choose a number to add to 
	// the output stack
	if (seq.length() > 1) {
	for (int i = 0; i < seq.length(); i ++) {
		string letter = seq(i);
		int nextNum; 
		if (equalsIgnoreCase(letter, "I") { //if the next number should be 												inc.
			nextNum = randomInteger(1, 9);
			while (stack.peek() < nextNum || !numbers.contains(nextNum) {
				nextNum = randomInteger(1, 9);
			}
			stack.push(nextNum);
			set.remove(nextNum)
			} else { // if the next number should be decreasing
			nextNum = randomInteger(1, 9);
			while (stack.peek() > nextNum || !numbers.contains(nextNum) {
				nextNum = randomInteger(1, 9);
			}
			stack.push(nextNum);
			set.remove(nextNum)
			}
		}
	}	
	string finalSequence;
	while (!output.isEmpty) {
		// Stack will return values in reverse order
		finalSequence.insert(0, integerToString(output.pop());
	}
	return finalSequence;	   	
}
		
