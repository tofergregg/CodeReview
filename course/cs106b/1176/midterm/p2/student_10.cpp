string decode(string seq) {
//I am assuming by minimum number, you mean the mininum number value 
// min number value: each time it decreases, it decreases as much as possible. each time it increases, it increases as little as possible
	//leftmost digits must have lowest value in order to result in the smallest-valued number
	
	Stack<int> resultStack;
	HashSet<int> usedDigits;
	if(seq[0] == 'I') {
		resultStack.push(1) 
	} else if(seq[0] == 'D') {
		resultStack.push(2);
	}
	for(int i = 1; i < seq.lenth() +1; i++) {
		char ch = seq[i-1];
		int curr = resultStack.peek();
		if(ch == 'I') {
			//start at the left with the smallest digits,
			//increment your way up to get smallest value
			while(usedDigits.contains(curr ++)) {
				curr ++;
			}
			usedDigits.add(curr);
			resultStack.push(curr);
		} else if(ch == 'D'){
			//decreases that integer by the maximum amount
			int subtraction= 10
			while(curr > 0 && ! usedDigits.contains(curr)) {
				curr--;
			}
			resultStack.push(curr);
		}
	}
	//transfers ints in stack to string
	string str;
	while(! resultStack.isEmpty()) {
		int n = resultStack.pop();
		str = integerToString(n) + str;
	}
	return str;
}
			
