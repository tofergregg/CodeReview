string decode(string seq) {
	Queue<int> q;
	for(int i = 1; i < seq.size()+2; i++) {
		q.enqueue(i);
	}
	Stack<int> s;
	s.push(0);
	for(int j = 0; j < seq.length(); j++) {
		int num = q.dequeue();
		while(q.length() == seq.length()-(i-1)) {
			if(seq[j] == 'I') {
				if(num > s.peek() || s.peek() == 0) {					
					s.push(num);
				} else {
					q.enqueue(num);
				}
			}
			if(seq[j] == 'D') {
				if(num < s.peek() || s.peek() == 0) {
					s.push(num);
				} else {
					q.enqueue(num);
				}
			}
		}
	}
	string result;
	while(!s.isEmpty()) {
		result = s.pop() + result();
	}
	return result;
		
		
