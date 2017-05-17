string decode(string seq) {
	Stack<int> numS;
	numS.push(1);
	for(int i = 0; i < seq.length(); i++) {
		if(seq[i] == 'I') {
			int next = numS.peek() + 1;
			numS.push(next);
		} else {
			int prev = numS.pop();
			numS.push(prev + 1);
			numS.push(prev - 1);
		}
	}
	string numString = "";
	while(!numS.isEmpty()){
		numString = numS.pop() + numString;
	}
	return numString;
