// assumes that passed in string is always upper case
// assumes that passed in string only contains the two letter I and D
// assumes that sequense is valid and doesnt produce numbers over 9
string decode(string seq) {
	string minN = "";
	Queue<int> seqN;
	Stack<string> s;
	int sum = 0;
	// find out start position
	for (int i = 0; i < seq.length(); i++){
		currChar = seq[i];
		if (currChar == "I") {
			sum += 1;
		} else {
			sum -= 1;
		}
	}
	if (sum < 1) {
		seqN.enqueue(abs(sum));
	} else {
		seqN.enqueue(1);
	}
	for (int i = 0; i < seq.length(); i++){
		int currN = seqN.peek();
		if (seq[i] == "I") {
			seqN.enqueue(currN + 1);
		} else {
			seqN.enqueue(currN - 1);
		}
	}
	// create string
	while (!seqN.isEmpty) {
		minN += integerToString(seqN.dequeue());
	}
	cout << minN << endl;
}
