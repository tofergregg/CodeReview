string decode(string seq) {
Stack<string> outputStack; 
	string outputString = "";
	int minValue;
	
	for (int i = 1; i < 10; i++) {
	for (int s = 0; s < seq.length(); s++) {
		outputString[s] = i;
		if (seq[s] == "I") {
			for (int n = i+1; n < 10; n++) {
				outputString[s+1] = n;
			}
		}
		if (seq[s] == "D") {
			for (int n = i-1; n > 0; n--) {
				outputString[s+1] = n;
			}
		}
	}
		outputStack.push(outputString);
	}
			
// find minimum output in the stack 	
	int n = stringToInteger(outputStack.pop());
	int m = stringToInteger(outputStack.peek());
	minValue = min(n,m);
	while (!outputStack.isEmpty()) {
		n = stringToInteger(outputStack.pop());
		minValue = min(n, minValue);	
	}

