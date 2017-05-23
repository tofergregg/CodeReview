string decode(string seq) {
	int size = seq.size();
	string answer;
	Stack<int> stack;
	Queue<int> q;
	if(seq.at(0) == 'I') {
		q.enqueue(1);
	} else if(seq.at(0) == 'D'){
		q.enqueue(size + 1);
	}
	for(int i = 1; i < size; i++) {
		if(seq.at(i) == 'I'){
			q.enqueue(q.peek()++);
		} else if(seq.at(i) == 'D') {
			q.enqueue(q.peek()--);
		}
	}
	for(int z = 0; z < q.size()) {
		answer += string(q.dequeue());
	}
	return answer;
} 