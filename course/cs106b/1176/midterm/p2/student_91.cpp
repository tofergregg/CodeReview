string decode(string seq) {
	Stack<int> stack;
	Queue<int> queue;
	Stack<int> tempStack; 
	
	queue.enqueue(1);
	for (int i = seq.length() + 1; i > 1; i++) {
		stack.pop(i);
	}
	
	for (int i = 0; i < seq.length(); i++) {
		if (queue.peek() < stack.peek()) {
			if (seq[i] == 'I') {
				queue.enqueue(stack.pop());
			} else if (seq[i] == 'D') {
				tempStack.push(queue.dequeue());
				queue.enqueue(stack.push());
			}
		}
	}
	
	if (queue.size() == 0 || queue.size() == 1) { 
		while(!tempStack.isEmpty()) {
			queue.enqueue(tempStack.pop());
		}
	}
	
	string finalNum = "";
	while(!queue.isEmpty()) {
		finalNum += queue.dequeue();
	}
	cout << finalNum << endl;
}
			