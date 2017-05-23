string decode(string seq) {
	string result = "";
	Stack<string> letterStack;
	for(int i = 0; i < seq.size(); i++) {
		letterStack.push(seq[i]);
		if(letterStack.size() == 1) {
			if(seq[i] == 'I') {
				result += '1';
				usedVals.add('1');
			} else {
				result += seq.size() + 1;
				usedVals.add('1');
			}
		} else {
			if(seq[i] == 'I') {
				int add = result[result(size) + 1];				
				result += integerToString(add);
			} else {
				int minus = result[result(size) - 1];				
				result += integerToString(minus);
			}			
		}
		
	}
}
