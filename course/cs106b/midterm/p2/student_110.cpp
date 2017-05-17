string decode(string seq) {
	string result = "";
	char ch = string seq[0];
	stack<int> s;
	Queue<int> q;
	Stack<int> answer;
	for(int i= 1; int i<10; i++) {
		q.enqueue(i);
	}
	if(ch=='I') {
		helper(0, seq, q, s, answer, 0, 100)
	} else if (ch=='D') {
		helper(10, seq, q, s, answer, 0, 100)
	}
	int size = answer.size();
	for(int i = 0; i<size; i++) {
		int dig = answer.pop();
		result = dig + result;
	}
	return result;
}
			
void helper(int curr, string& seq, Queue<int>& q, Stack<int>& s, Stack<int>& answer, int total, int& lowest) {
	if(seq.isEmpty()) {
		if(total<lowest) {
			answer = s;
			lowest = total;
		}
		return;
	}
	if(seq.charAt(0) == 'I') {
		seq.erase(0,1);
		Queue<int> copy = q;
		int totalCopy = total;
		for(int i= 0; i<q.size(); i++) {
			int next = q.dequeue();
			if(next>curr) {
				s.push(next);
				total+=next;
				helper(next,seq, q, s, total, lowest);
			}
			total = totalCopy;
			q.enqueue(next);
			s.pop();
		}
	} else if(seq.charAt(0) =='D') {
		seq.erase(0,1);
		Queue<int> copy = q;
		int totalCopy = total;
		for(int i= 0; i<q.size(); i++) {
			int next = q.dequeue();
			if(next<curr) {
				s.push(next);
				total+=next;
				helper(next,seq, q, s, total, lowest);
			}
			total = totalCopy;
			q.enqueue(next);
			s.pop();
		}
	}
	return;
}
		