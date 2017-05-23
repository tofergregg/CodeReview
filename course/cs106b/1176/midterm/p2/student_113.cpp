string decode(string seq) {
	Queue<int> nums;
	for(int i = 0; i < seq.length + 1; i++) {
		nums.enqueue(i+1);
	}
	int dCount = 0;
	int icount = 0;
	string sequence;
	for(int i = 0; i < seq.length(); i++) {
		if (s[i] = I) {
			sequence += nums.dequeue());
			iCount++;
		}
		if (s[i] = D) {
			sequence +=;
			dCount++;
		}
		return sequence; 
	}
}
	