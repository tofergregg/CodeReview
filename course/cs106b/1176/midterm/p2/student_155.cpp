string decode(string seq) {
	Queue<char> q;
	for(int i = 0; i < seq.length(); i++) {
		q.enqueue(seq.[i]);
	}
	Stack<int> stack;
	int largest = 0;
	
	while(!q.isEmpty()) {
		if(q.peek() == 'I') {
			q.dequeue();
			largest++;
			stack.push(largest);
			if(q.isEmpty()) stack.push(largest + 1);
		} else {
			int decCounter = 0;
			while(q.peek == 'D') {
				decCounter++;
				q.dequeue;
			}
			if(!q.isEmpty()) q.dequeue();
			addFromDs(stack, decCounter, largest);
			largest++;
		}
	}
	
	int size = stack.size();
	string decoded = "";
	for(int i = 0; i < size; i++) {
		decoded = integerToString(stack.pop) + decoded;
	}
	return decoded;
}

addFromDs(Stack<int>& stack, int decCounter, int& largest) {
	largest = largest + decCounter + 1;
	for(int i = 0; i <= decCounter; i++) {
		stack.push(largest - i);
	}
}