string decode(string seq) {
	Stack<int> s;
	Queue<int> q; int k=0, m=9;
	for (int i=0;i<seq.size();i++) {	
		if (seq[i] == 'I') {
			s.push(seq[i]);
			k++;
			cout << integerToString(k);
		} else if (seq[i] == 'D') {
			q.enqueue(seq[i]);
			m--;
			if(abs(k-m) >=0)
			cout << integerToString(k-m+q.size());
			else 
				cout << integerToString(k);
		}
	}
}