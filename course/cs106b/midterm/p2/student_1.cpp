string decode(string seq) {
	Queue<char> letters
	Queue<int> numbers;
	Set<int> used;
	int numOfD = 0;
	for(char c : seq) {
		if(c == 'D') {
			numOfD++;
		} 
		letters.enqueue(c);
	}
	
	//Find first number
	char firstChar = seq[0];;
	if(firstChar == 'I') {
		numbers.enqueue(1);
		used.add(1);
		int firstNum = 1;
	} else if(firstChar == 'D') {
		numbers.enqueue(1 + numOfD);
		used.add(1 + numOfD);
		firstNum = 1 + numOfD;
		numOfD--;
	}
	
	//Find the rest of the numbers
	int currentNum = firstNum;
	for(int i = 0; i < seq.length(); i++) {
		char move = letters.dequeue();
		if(move == 'D') {
			currentNum = currentNum - 1;
			numOfD--;
		} else if(move == 'I') {
			if(numOfD == 0) {
				currentNum = currentNum + 1;
			} else {
				currentNum = 1 + numOfD;
				while(used.contains(currentNum) {
					currentNum++;
				}
				currentNum++;
			}
		}
		numbers.enqueue(currentNum);
	}	   
		   
	//Put the numbers from the queue into a string and
	//return the result
	string output;
	for(int i = 0; i < (seq.length() + 1); i++) {
		string nextNum = integerToString(numbers.dequeue());
		output[i] = nextNum[0];
	}
	return output;
}
		
		
			