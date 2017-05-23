string decode(string seq) {

	Queue<char> sequence;
	Stack<int> nums;
	Stack<int> lowestNum;

	for (char letter : seq) {
		sequence.enqueue(letter);
	}

	for (int i = seq.size() + 1; i > 0; i--) {
		nums.push(i);
	}
	
	output += nums.pop();  //initialize with 1
	
	while (!sequence.isEmpty()) {
		char next = sequence.dequeue();
		if (next == 'I') {
			lowestNum.push(nums.pop());
		} else if (next == 'D') {
			int temp = lowestNum.pop();
			lowestNum.push(nums.pop());
			lowestNum.push(temp);
		}
	}
	
	string output = lowestNum.toString();
	return lowestNum.toString();
}