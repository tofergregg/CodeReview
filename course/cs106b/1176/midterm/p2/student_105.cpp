string decode(string seq) {
	//Initializing set of numbers that have not been used
	Set<int> numbersLeft;
	for (int i = 1; i <= seq.size() + 1; i++) {
		numbersLeft.add(i);
	}
	
	Queue<int> sequenceForward;
	for (int i = 0; i < seq.size(); i++) {
		if (seq.at(i) == 'I') {
			//Since sets are automatically sorted, index 0 will contain the lowest value
			sequenceForward.enqueue(numbersLeft[0]);
			numbersLeft.remove(numbersLeft[0]);
		} else { //if seq.at(i) == 'D'
			int stringD = 0;
			int j = i;
			while (j != seq.size() && seq.at(j) == 'D') {
				stringD++;
				j++;
			}
			sequenceForward.enqueue(numbersLeft[stringD]);
			numbersLeft.remove(numbersLeft[stringD]);
		}
	}
	sequenceForward.enqueue(numbersLeft[0]); //since the output will always be one character longer than the string sequence entered.
	
	//Returning the sequence in string form:
	string result = "";
	for (int i = 0; i < sequenceForward.size(); i++) {
		result += integerToString(sequenceForward.dequeue());
	}
	return result;
}

//Definitely not O(n), my apologies!