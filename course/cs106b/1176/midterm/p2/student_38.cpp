string decode(string seq) {
	
	int current = 1;
	Stack<int> i;
	Stack<int> d;
	if(seq[0] == 'D') d.push(current);
	else i.add(current);
	current++;
	string outPut;
	   
	for(int k = 0; k < seq.length() - 1; k++) {
		if(seq[k] == 'D') d.add(current);
		else i.add(current);
	}
	for(int k = seq.length() - 1; k >= 0; k--) {
		if(seq[k] == 'D'){
			string num = IntegerToString(d.pop());
			outPut+=num;
		} else {
			string num = IntegerToString(i.pop());
			outPut+=num;
			
		}
		
	}
	
	return outPut;
