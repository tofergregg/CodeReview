// This program will implement a stack, taking into consideration the number of D's following an I to determine the next number to push.

string decode(string seq) {
	int numI = 0;
	int numD = 0;
	int topNumber;
	int firstNumber;
	Set <int> allNumbers;
	Stack<int> numSeq;
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i]=='I') {
			numI++;
		}
		else if (seq[i]=='D') {
			numD++;
		}
	}
	if (numD > numI) {
		firstNumber = numD+1-numI;
	}
	else {
		firstNumber = 1;
	}
	numSeq.push(firstNumber);
	allNumbers.add(firstNumber);
	for (int i = 0; i < seq.length(); i++) {
		topNumber = numSeq.peek();
		if (seq[i] == 'D') { // if D, just decrease
			topNumber = topNumber-1;
			allNumbers.add(topNumber);
			numSeq.push(topNumber);
		}
		if (seq[i] == 'I') { // if I, count number of Ds, add it to previous number, and add 1.
			int nextD=0;
			for (int x = i+1; x < seq.length(); x++) {
				if (seq[x] == 'D') {
					nextD++;
				}
				else {
					break;
				}
			}
			topNumber = topNumber+nextD+1;
			if (allNumbers.contains(topNumber)) { // if number already used, use biggest
				for (int i = 0; i < 10; i++) {
					if (!allNumbers.contains(topNumber)) {
						topNumber= i + 1 + nextD;
					}
				}
			}
			allNumbers.add(topNumber);
			numSeq.push(topNumber);
		}
	}
	return numSeq.toString();
}