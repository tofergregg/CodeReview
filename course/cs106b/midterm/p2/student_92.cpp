string decode(string seq) {
	Stack<int> nums;
	Stack<int> ans;
	for (int i = 9; i > 0; i--) {
		nums.push(i);
	}
	Vector<int> vec(seq.length());
	
	for (int i = 0; i < seq.length(); i++) {
		char ch = seq[i];
		
		// increasing sub sequence
		if (ch = 'I') {
			ans.push(nums.pop());
		}
		// decreasing sub sequence
		else {
			int count = 0;
			while (! ans.peek() < nums.pop()) {
				nums.push(ans.pop());
			count++;
			}
			for (int i = 0; i < count; count++) {
			ans.push(nums.pop());
				}
		}
	}
	
	
	
	
	
	string s = ""; 
	while (!ans.isEmpty()) {
		s = integerToString(ans.pop()) + s;
	}
	return s;
}
