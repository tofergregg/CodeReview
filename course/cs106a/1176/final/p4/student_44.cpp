string decode(string seq) {
	int len = string.length();
	
	Queue<int> nums;
	for(int i = 1; i < 10; i++) {
		nums.enqueue(i);
	}
	
	Stack<int> result;
	int base = nums.dequeue(0);
	result.push(base);
	
	for(int c = 0; c < len; c++) {
		int compare = nums.dequeue(0);
		if (seq[c] == "I") {
			if(result.peek() < compare) {
				result.push(compare);
			} else {
				int temp = result.pop();
				result.push(compare);
				result.push(temp);
			}
		} else if seq[c] == "D") {
			if(result.peek() > compare) {
				result.push(compare);
			} else {
				int temp = result.pop();
				result.push(compare);
				result.push(temp);
			}
		}
	}
	
	string output = "";
	
	while(!result.isEmpty()) {
		int d = result.pop();
		string digit = integerToString(d);
		output = d + output;
	}
	
	return output;
}
	

