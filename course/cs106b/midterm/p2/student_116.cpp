string decode(string seq) {
	if (seq == "") return integerToString(1);
	
	int length = seq.length();
	Set<int> numbers;
	
	for (int i=0; i<length+1; i++) {
		numbers.add(i+1);
	}
	
	Stack<int> output;
	
	for (int i=length+1; i>=1; i--) {
		output.push(i);
		if (seq[i-2] == "D") {
			if(i<length+1 && numbers.contains(i)) {
				output.push(i);
			} else if (i>=length+1) {
				output.clear();
			} else {
				
			}
		} else {
			
		
		}
	}
