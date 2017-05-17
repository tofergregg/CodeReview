string decode(string seq) {
	string minDecoded = "";
	Stack<int> s;
	int nextNum = 1;
	for(int i = 0; i < seq.length(); i++){
		if(seq[i] == 'I'){
			minDecoded += integerToString(nextNum);
			while(!s.isEmpty()){
				minDecoded += integerToString(s.pop());
			}
			nextNum++;
		} else if(seq[i] == 'D') {
			s.push(nextNum);
			nextNum++;
		}
	}
	minDecoded += integerToString(nextNum);
	while(!s.isEmpty()){
		minDecoded += integerToString(s.pop());
	}
	return minDecoded;
}
	