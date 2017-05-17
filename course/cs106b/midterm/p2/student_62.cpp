string decode(string seq) {
	string output;
	Stack<int> stack;
	Queue<int> queue;
	int max = seq.size() + 1;
	for (int i=max; i>=0; i++) {
		num.push(i);
		queue.enqueue(i);
	}
	for (int i=0; i<seq.size()-1; i++) {
		char c = seq[i];
		if (c=="I") {
			output.add(stack.pop());
		} else if (c=="D") {
			output.add(queue.dequeue());
	}
	return output;
}