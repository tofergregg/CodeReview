string decode(string seq) {
	string result = "";
	int n = seq.size();
	Stack<char> stack;
	Queue<int> nums;
	for (int i = 1; i < 9; i++) {
		nums.enqueue(i);
	}
	for (int i = 0; i < n; i++) {
		stack.push(seq[i]);
	}	
	while (!nums.isEmpty() || !stack.isEmpty()) {
		char ch = stack.pop();
		int num = nums.dequeue();
		if (ch == 'I') {
			if (num < nums.peek()) {
				result += integerToString(num);
			} else {
				nums.enqueue(num);
				stack.push(ch);
			}
		} else if (ch == 'D') {
			if (num > nums.peek()) {
				result += integerToString(num);
			} else {
				nums.enqueue(num);
				stack.push(ch);
			}
		}
	}
	return result;
}
