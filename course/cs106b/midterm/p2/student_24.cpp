string decode(string seq) {
	int best = 99999999;
	Queue<string> options;
	for(int i = 1; i <= 9 + 1; i++) {
		string num = integerToString(i);
		options.enqueue(num);
	}
	while(!options.isEmpty()) {
		string curr = options.dequeue();
		if(curr.size() == seq.size() + 1) {
			int value = stringToInteger(curr);
			if(value < best) {
				best = value;
			}
		} else {
			for(int i = 1; i <= 9; i++) {
				string digit = integerToString(i);
				if(curr.find(digit) == string::npos) {
					int index = curr.size();
					char last = curr[index-1];
					char key = seq[index - 1];
					if((key == 'D') && (digit < last)) {
						curr.append(digit);
						options.enqueue(curr);
					}
					if((key == 'I') && (digit > last)) {
						curr.append(digit);
						options.enqueue(curr);
					}
				}
			}
		}
	}
	string answer = integerToString(best);
	return best;
}
					
		 
