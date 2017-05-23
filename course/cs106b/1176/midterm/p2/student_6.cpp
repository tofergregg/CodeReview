string decode(string seq) {
	string result;
	Stack<int> s1;
	Stack<int> s2;
	for (int i = 9; i >= 1; i ++) {
		s1.push(i);
	}
	for (int i = 0; i < seq.length(); i ++) {
		if (seq[i] == 'D') {
			s2.push(s1.pop());
		}
		if (seq[i] == 'I') {
			result += integerToString(s1.pop());
			while (!s2.isEmpty()) {
				result += integerToString(s2.pop());
			}
		}
		if (i == seq.length() - 1) {
			result += integerToString(s1.pop());
			while (!s2.isEmpty()) {
				result += integerToString(s2.pop());
			}
		}	
	}
	return result;
}
		