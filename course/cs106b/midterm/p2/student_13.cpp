string decode(string seq) {
	int seqSize = seq.length();
	string availNums = "";
	//Queue<int> availNums;
	for (int i = 1; i <= seqSize + 1; i++) {
		availNums.append(i);
	}
	
	Queue<int> output;
	for (int i = 0; i < seqSize + 1; i++) { // 1 more output than seq
		if (seq[i] == "I") {
			output.enqueue(availNums(0,1)); // add 1st (smallest) num
		} else { // seq[i] == "D"
			string numAvailNums = availNums.length();
			output.enqueue(availNums.substr(numAvailNums-1,1); // add last
		}
		string rest = availNums.substr(1);
		availNums = rest;
	}
	
	// convert output to a string
	string outputString;
	while (!output.isEmpty()) {
		outputString.add(output.dequeue());
	}
	return output;
}