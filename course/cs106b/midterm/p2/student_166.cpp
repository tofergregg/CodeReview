string decode(string seq) {

	string output = "";
	if (seq[0] == 'I') {
			output += "1";
	} else {
		string num = seq.length() + 1;
		output += num;
	}
	for (int j = 0; j < seq.length(); j++) {
			if (seq[j] == 'I') {
			Queue<int> numbers;
			for (int i = 2; i <= 9; i++) {
				numbers.enqueue(i);
			}
				output += integerToString(numbers.dequeue());
		} else {
			Stack<int> numbers;
			for (int i = seq.length(); i >= 1; i--) {
				numbers.push(i);
			}
			output += integerToString(numbers.pop());
		}
	}