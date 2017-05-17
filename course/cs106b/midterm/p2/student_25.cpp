string decode(string seq) {
	string output;
	seq = seq + "-";
	int num = 1;
	Stack<int> stack;
	if (seq[0] == 'I') {
		output = integerToString(num);
	} else {
		stack.push(num);
	}
	for (int i=0; i < seq.size()-1; i++) {
		if (seq[i] == 'I' && seq[i+1] != 'D') {
			output = output + integerToString(num+1);
			num++;
		} else if (seq[i] == 'I' && seq[i+1] == 'D') {
			stack.push(num+1);
			num++;
		} else if (seq[i] == 'D' && seq[i+1] == 'I') {
			output = output + integerToString(num+1);
			num++;
			while (!stack.isEmpty()) {
				output = output + stack.pop();
			}
		} else if (seq[i] == 'D' && seq[i+1] == 'D') {
			stack.push(num+1);
			num++;
		} else if (seq[i] == 'D' && seq[i+1] == '-') {
			while (!stack.isEmpty()) {
				output = output + stack.pop();
			}
		}
	}
}
								
				
			