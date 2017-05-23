void determineStartingValue(int outputLength, string seq, Stack <int> &outputNum, Set <int> &usedNums);
void increase(Stack<int> &outputNum, Set<int> &usedNums);
void decrease(Stack<int> &outputNum, Set<int> &usedNums)

string decode(string seq) {
	int outputLength = seq.length() + 1;
	Stack <int> outputNum; 
	Set <int> usedNums;
	//create numerical sequence
	for (int i = 0; i < outputLength; i++) {
		if (i == 0) {//first "current key"
			determineStartingValue(outputLength, seq, outputNum, usedNums);
		} 
		if (seq[i] == 'I') {
			increase(outputNum, usedNums);
		} else if (seq[i] == 'D') {
			decrease(outputNum, usedNums);
		}
	}	
	//print string sequence
	string result;
	while (!outputNum.isEmpty()) {
		int num = outputNum.pop();
		string number = integerToString(num);
		result = number + result; //reverse it to be the correct output (LIFO)
	}
	return result;
}

//determines what the starting value of the sequence will be
void determineStartingValue(int outputLength, string seq, Stack <int> &outputNum, Set <int> &usedNums) {
	if (seq[0] == 'I') { //increasing
		outputNum.push(1);
		usedNums.add(1);
	} else { //decreasing
		if (seq.length() == 8) { //incase all are decreasing
			outputNum.push(9);
			usedNums.add(9);
		} else {
			outputNum.push(5);
			usedNums.add(5);
		}
	}
}

//creates increasing portion of sequence
void increase(Stack<int> &outputNum, Set<int> &usedNums) {
	int current = outputNum.pop(); //take the last value
	int next = current ++;
	while (usedNums.contains(next)) {//already used value
		next = current ++;
	}
	usedNums.add(next); //make sure this doesnt get resued
	outputNum.push(current);
	outputNum.push(next);
}

//creates decreasing portion of sequence
void decrease(Stack<int> &outputNum, Set<int> &usedNums) {
	int current = outputNum.pop(); //take the last value
	int next = current --;
	while (usedNums.contains(next)) {//already used value
		next = current --;
	}
	usedNums.add(next);
	outputNum.push(current);
	outputNum.push(next);
}		