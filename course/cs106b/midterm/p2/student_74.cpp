string decode(string seq) {
	Queue<Stack<int>> possibleOutputs;
	Set<int> usedNumbers;
	char c = seq[0];
	chooseFirstDigit(seq, possibleOutputs, usedNumbers);
	string smallestResult = findSmallest(possibleOutputs);
	return smallestResult;
}
				 
void findPossibilities(string seq, Queue<Stack<int>> &possibleOutputs, Set<int> &usedNumbers, Stack<int> ¤tPossibility) {
	for (int i = 0; i < seq.length(); i++) {
		char c = seq[i];
		if (c == 'I') {
			for (int j = 1; j <= 9; i++) { 
				//finds next smallest, unused number that is larger than previous
				if (!usedNumbers.contains(j) && j > currentPossibility.peek()){
					currentPossibility.push(j);
					usedNumbers.add(j); 
					break; //exits for loop testing digits to move onto next char
				} else { //no numbers left that fit, currentPossibility is invalid
					currentPossibility.clear();
					return; //method returns to try new set of numbers
				}
			}
		} else if (c == 'D'){
			for (int k = 9; k >= 1; k--) {
				if (!usedNumbers.contains(k) && k < currentPossibility.peek()){
					currentPossibility.push(k);
					usedNumbers.add(l); 
					break;	
				} else {
					currentPossibility.clear();
					return;
				}
			}				
		}
	}
	possibleOutputs.enqueue(currentPossibility);
}
			
void chooseFirstDigit(string seq, Queue<Stack<int>> &possibleOutputs, Set<int> &usedNumbers) {
	char c = seq[0];
	Stack<int> currentPossibility;
	if (c == 'I') {
		for (int j = 1; j <= 9; i++) {
			currentPossibility.push(j);
			usedNumbers.add(j); 
			findPossibilities(seq, possibleOutputs, usedNumbers, currentPossibility);
		}
	} else if (c == 'D'){
		for (int k = 9; k >= 1; k--) {
			currentPossibility.push(j);
			usedNumbers.add(j); 
			findPossibilities(seq, possibleOutputs, usedNumbers, currentPossibility);
		}
	}
}

string findSmallest(Queue<Stack<int>> &possibleOutputs) {
	int smallestValue;
	string result;
	while(!possibleOutputs.isEmpty()) {
		Stack<int> output = possibleOutputs.dequeue();
		string current = "";
		while (!output.isEmpty()) {
			current += output.pop(); //ints will be added to string current
		}
		int currentValue = stringToInteger(current);
		if (currentValue < smallestValue) {
			currentValue = smallestValue;
			result = current;
		}
	}
	return result;
}