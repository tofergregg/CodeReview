string decode(string seq) {
	int length = seq.size() + 1; // size of decoded string
	int currentIndex = 0; // starting index
	bool increasing = true; // nums queued increasingly
	string decoded = "";
	Queue<int> nums;
	for(int i = 1; i <= length; i++) {
		nums.enqueue(i);
	}
	while(!nums.isEmpty()) {
		char next = seq.at(currentIndex);
		currentIndex++;
		getNextInt(next, increasing, decoded, nums);
		if(currentIndex == length - 1) { // determines last number
			getNextInt(next, increasing, decoded, nums);
		}
	}
	return decoded;
}
	
void getNextInt(char next, bool &increasing, string &decoded, Queue<int> &nums) {
	string nextInt = "";
	if(next == 'I') {
		if(!increasing) {
			reverse(nums);
			increasing = true;
		}
		nextInt = integerToString(nums.dequeue());
		decoded += nextInt;
	} else if(next == 'D') {
		if(increasing) {
			reverse(nums);
			increasing = false;
		}
		nextInt = integerToString(nums.dequeue());
		decoded += nextInt;
	}
}

void reverse(Queue<int> &nums) {
	Stack<int> holding;
	for(int i = 0; i < nums.size(); i++) {
		int number = nums.dequeue();
		holding.push(number);
	}
	for(int j = 0; j < holding.size(); j++) {
		int nextNum = holding.pop();
		nums.enqueue(nextNum);
	}
}
	
			
			
			