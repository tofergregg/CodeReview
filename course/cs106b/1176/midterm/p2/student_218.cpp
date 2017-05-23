string decode(string seq) {
	int minNum = 1000000000;
	Vector<Stack<int>> allPossibilities;
	Stack<int> result;
	Vector<bool> usedNum;
	
	if(seq.size() == 1) {
		if(seq[0] == 'I') {
			return "12";
		} else {
			return "21";
		}
	}
	
	//get all possible numbers
	
	//Choose the first digit
	for (int i = 1; i <= 9; i++) {
		result.push(i);
		
		//choose other digits
		for(int j = 0; j < seq.size(); j++) {
			char c = seq[j];
			int pre = result.peek();
			
			if(c == 'I') {
				for(int m = pre + 1; m <= 9; m++) {
					if(!usedNumber[m-1]) {
						result.push(m);
					}
					if(result.size() == seq.size()+1) {
						allPossibilities.add(result);
						result.clear();
					}
				}
				
			} else {
				for(int m = pre - 1; m >= 1; m--) {
					if(!usedNumber[m-1]) {
						result.push(m);
					}
					if(result.size() == seq.size()+1) {
						allPossibilities.add(result);
						result.clear();
					}
				}
			}
		}
		
	}
	
	//choose the minimum number

	for(Stack<int> v: allPossibilities) {
		string s;
		int n;
		while(!v.isEmpty()) {
			s.insert(0, charToString(v.pop()));
		}
		n = stringToInteger(s);
		if(n <= minNum) {
			minNum = n;
		}
	}
	
	return integerToString(minNum);
}
	
	
	
string decode(string seq) {
	
	

	
	
	
	
	
	
	
	
	
	
	
	
	