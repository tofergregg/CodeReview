string decode(string seq) {
	Queue<char> q;
	Vector<int> digits;
	string ret;
	int maxDigit = seq.length() + 1;
	for(char c : seq) {
		q.enqueue(c);
	}
	for(int i = 1; i =< maxDigit; i++) {
		digits.add(i);
	}
	while(!q.isEmpty()) {
		char c = q.dequeue();
		if(c == 'I') {
			ret += digits[0];
			digits.remove(0);
		}
		if(c == 'D') {
			ret += digits[digits.size() - 1];
			digits.remove(digits.size() - 1);
		}
	}
	return 	ret + digits[0];
}
			
		