string decode(string seq) {
	Queue<int> possibleNumbers;
	for (int i = 0; i < 10; i++) {
		possibleNumbers.enqueue(i);
	}
	Stack<string> sequence;
	for (int i = 0; i < (int)seq.length(); i++) {
		sequence.push(s[i]);
	}
	int seqLength = seq.length();
	if ( seqLength == 1) {
		if (equalsIgnoreCase(seq, "I") { // base case #1
			return "12";
		}
		if (equalsIgnoreCase(seq, "D") { // base case #2
			return "21";
		}
			}
	else { // recursive step here 
	
	

	}
	return "";
		
	}