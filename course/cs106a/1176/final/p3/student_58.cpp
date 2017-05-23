string decode(string seq) {
	Stack<int> sequence;
	for (int i = 1; i < 10; i++) {
		int start = i;
		sequence.push(start);
		for(int j = 0; j<seq.length(); j++) {
			int current;
			if(seq[j] == "I") {
				current = sequence.peek() + 1;
				if(current > 9) break;
				sequence.push(current);
			}else if (seq[j] == "D") {
				current = sequence.peek() - 1;
				if(current < 1) break;
				sequence.push(current);
			}
		}
		if(sequence.size() == seq.length()){
			break;
		} else {
			sequence.clear();
		}
	}
	string solution = "";
	while(!sequence.isEmpty()) {
		solution = integerToString(sequence.pop()) + solution;
	}
	return solution;
}