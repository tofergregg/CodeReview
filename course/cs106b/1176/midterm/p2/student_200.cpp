string decode(string seq) {
	string result = "";
	Queue<int> queue;
	for (int i = 1; i < 10; i++) {
		queue.enqueue(i);
	}
	char start = seq[0];
	int count = 0;
	while (count < seq.length()) {
		while (count < seq.length() && seq[count] == 'I') {
			result += integerToString(queue.dequeue());
			count++;
		}
		int timesToDecrease = 0;
		while (count < seq.length() && seq[count] == 'D') {
			timesToDecrease++;
			count++;
		}
		for (int i = 0; i < timesToDecrease; i++) {
			result = result.substr(0, result.length() - i) + integerToString(queue.dequeue()); + result.substr(result.length() - i);
		}
	}
	return result;
}