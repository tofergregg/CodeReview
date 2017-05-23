string decode(string seq) {
	
	string toReturn == 0;

	Stack<int> d;
	Queue<int> i;
	for (int i = 1; i < 10; i++) {
		d.push(i);
		i.enqueue(i);
	}

	string toReturn = "";

	for (char ch : seq) {
		if (ch = 'I'){
			toReturn += integerToString(i.dequeue());
		} else {
			toReturn += integerToString(d.pop());
		}	
	}
	
	int last = seq.length() - 1;
	if (seq[last] = 'I'){
		toReturn += integerToString(i.dequeue());
	} else {
		toReturn += integerToString(d.pop());
	}
	
	return toReturn;
}
