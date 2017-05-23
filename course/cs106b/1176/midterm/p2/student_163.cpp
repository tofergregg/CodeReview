string decode(string seq) {
	stack<int> s;
	s.push(1);
	for(int i = seq.size() - 1; i >= 0; i--) {
		if(seq[i] == "D") {
			s.push(s.peek() + 1);
		} else {
			int temp = s.pop();
			s.push(temp + 1);
			s.push(temp);
		}
	}
	string output = "";
	while(!s.isEmpty()) {
		int temp = s.pop();
		output += integerToString(temp);
	}
	return output;
}