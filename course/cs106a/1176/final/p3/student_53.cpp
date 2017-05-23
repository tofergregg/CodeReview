string decode(string seq) {
	string number;
	int firstNumber = 1;
	for(int k = 0; k < seq.size(); k++) {
		if(seq[k] == 'D') {
			firstNumber++;
		} else {
			break;
		}
	Queue<int> lessThan;
	if(firstNumber != 1) {
		for(int i = 1; i < firstNumber; i++) {
			lessThan.enqueue(i);
		}
	}
	Queue<int> greaterThan;
	if(firstNumber != seq.size() + 1){
		for(int j = firstNumber + 1; j < seq.size() + 2; j++) {
			greaterThan.enqueue(j);
		}
	}
	for(int i = 0; i < seq.size(); i++) {
		if( seq[i] == 'I') {
			number = number + greaterThan.dequeue();
			}
		} else {
			number = number + lessThan.dequeue();
		}
	}
	return number;
}
