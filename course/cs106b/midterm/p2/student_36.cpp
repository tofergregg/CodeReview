string decode(string seq) {
	

	int maxNum = seq.length() + 1;
	int newNum;
	string output = "";
	Stack<int> sequence;
	Set<int> usedNumbers;
	
	char first = seq[0];
	if (first == 'I') {
		newNum = 1;
		usedNumbers.add(newNum);
		sequence.push(newNum); //starts with 1
	}
	else if (first == 'D') { 
		newNum = maxNum;
		usedNumbers.add(newNum);
		sequence.push(newNum); //starts at max
	}
	
	for (i = 0; i < seq.length(); i++) {
		if (seq[i] == 'I') { //increase number
			newNum++;
			sequence.push(newNum);
		}
		if (seq[i] == 'D') {
			newNum--; 
			sequence.push(newNum);
	}
	}
		while(!sequence.isEmpty()) {
			int j = sequence.pop();
			string addInt = integerToString(j);
			output += add; 
		}
		
		return output;
	}
	