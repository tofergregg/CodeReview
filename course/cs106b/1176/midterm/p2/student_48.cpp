string decode(string seq) {
	Stack<int> newSeq;
	if(seq[0] == 'I') {
		newSeq.push(1);
		newSeq.push(2);
	} else if (seq[0] == 'D') {
		newSeq.push(2);
		newSeq.push(1);
	}
	if(seq.size() > 1) {
			
		for(int i = 3; i < seq.length() + 2; i++) {
			if(seq[i-2] == 'I'){
				newSeq.push(i);		
			} else if(seq[i-2] == 'D') {
				int oldVal = newSeq.pop();
				newSeq.push(i);
				newSeq.push(oldVal);			
			}
		}
	}

	
	//Must reverse order since we're dealing with a stack or could do newSeq.toString();
	string decSeq;
	for(int j = 0; j < newSeq.size(); j++){
		decSeq = newSeq.pop() + decSeq;
	}
	return decSeq;
}






