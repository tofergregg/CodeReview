string decode(string seq) {
	int length = seq.size();
	Set<int> used;
	Stack<int> stack1 = setupStack();
	Vector<int> fin;
	int dNumber = dNum(seq, length) + 1;
	int iNumber = length - dNumber + 1;
	for (int i = 0; i < length; i++) {
		char ch = seq[i];
		if (ch == 'I') {
			if (i == 0) {
				fin.add(1);
				used.add(1);
			} else {
				int cur = stack1.pop();
				while (used.contains(cur)) {
					cur = stack1.pop();
				}
				fin.add(cur);
			}
			used.add(cur);
			if (i == length-1) {
				fin.add(stack1.pop());
			}
		}
		} else {
			int cur = dNumber;
			while (used.contains(cur)) {
				cur--;
			}
			if (cur == 0) {
				cur = dNumber + inumber + 1;
				while (used.contains(cur)) {
					cur++;
				}
			}
			fin.add(cur);
			used.add(cur);
			if (i == length-1) {
				fin.add(cur--);
			}
		}
		
	}
	string fina;
	for (int i = 0; i < fin.size(); i++) {
		fina += integerToString(fin[0]);
	}
	return fina;
}
			
Stack<int> setupStack() {
	Stack<int> stack1;
	for (int i = 9; i > 0; i--) {
		stack1.push(i);
	}
	return stack1;
}

int dNum(string& seq, int& length) {
	int count = 0;
	for (int i = 0; i < length; i++) {
		if (seq[i] == 'D') {
			count++;
		}
	}
	return count;
}