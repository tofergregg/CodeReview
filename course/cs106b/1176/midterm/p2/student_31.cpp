string decode(string seq) {
	
	Stack<int> myOutput;
	Queue<Stack<int>> q;
	HashSet<int> usedNums;
	
	if (seq[0] == 'I') {
		myOutput.push(1);
	} else if (seq[0] == 'D') {
		int first = 1;
		for (int i = 0; i < seq.length(); i++) {
			if (seq[i] == 'D') first++;
			else if (seq[i] == 'I') break;
		}	
		myOutput.push(first);
	}
	
	usedNums.add(myOutput.peek());
	cout << myOutput.peek();
	
	for (int i = 0; i < seq.length(); i++) {
		int temp = myOutput.peek():
		if (seq[i] == 'I') {
			for (int j = i+1; j < seq.length(); j++) {
				if (seq[j] == 'D') {
						temp++;	
				} else if (seq[j] == 'I') break;
			}
			do {
				temp++;
			} while (sequence.contains(temp));
		} else if (seq[0] == 'D'){
			temp--;
		}
		usedNums.add(temp);
		myOutput.push(temp);
		cout << temp;		
	}
}