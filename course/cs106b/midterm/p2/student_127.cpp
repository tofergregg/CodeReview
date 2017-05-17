string decode(string seq) {
	Stack<int> output;
	Set<int> usedNum;

	if (seq[0] == 'I'){
		int curr = 1;
	}
	else {
		int curr = 2;
	}
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == 'I') {
			curr = output.peek();
			curr++;
			while (usedNum.contains(curr)) {
				if (curr <= 9) {
					curr++;
				}
				else {
					curr = 1;
				}
			}
			usedNum.add(curr);
		}
		else {
			curr = output.peek();
			curr--;
			while (usedNum.contains(curr)) {
				if (curr >=1) {
					curr--;
				}
				else {
					curr = 9;
				}
			}
			usedNum.add(curr);
		}
		
		
	}
	output = usedNum.toString();
	return output;
}
	
	