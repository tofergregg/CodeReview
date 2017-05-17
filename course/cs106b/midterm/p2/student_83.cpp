string decode(string seq) {
	Queue<int> queue;
	Stack<int> stack;
	Vector<bool> isUsed(seq.length + 1);
	string result;
	if (seq.length > 1) {
		for (int i = 1; i < seq.length(); i++) {
			queue.enqueue(i);
			stack.push(i);
			isUsed[i] = false;
		}
		for (int i; i < seq.length(); i++) {
			if (seq[i] == 'I') {
				while (isUsed[queue.peek]) {
					queue.dequeue;
				}	
				result += integerToString(queue.dequeue);
			} else {
				while (isUsed[stack.peek]) {
					stack.pop;
				}
				result += integerToString(stack.pop);
			}
		}
	} else {
		result += "1";
	}
	return result;
}