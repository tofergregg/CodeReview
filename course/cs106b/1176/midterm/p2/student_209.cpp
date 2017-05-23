string decode(string seq) {
	Queue<char> q;
	int numI;
	int numD;
	int intAnswer;
	int count;
	string strAnswer;
	for (int i = 0; i < seq.size(); i++) {
		q.enqueue(seq.at(i));
		if (seq.at(i) == 'I') {
			numI ++;
		} else {
			numD ++;
		}
	}
	if (numD > numI) {
		intAnswer = 9;
	} else if (numI > numD) {
		intAnswer = 1;
	} else {
		intAnswer = 5;
	}
	strAnswer = integerToString(intAnswer);	
	while (!q.isEmpty()) {
		char ch = q.dequeue();
		if (ch == 'I') {
			if (q.peek() == 'I') {
				intAnswer += 1;
				for (int j = 0; j < strAnswer.size(); j++) {
					if (integerToCharacter(intAnswer) == strAnswer.at(j)) {
						intAnswer +=1;
					}
				strAnswer += integerToString(intAnswer);
			}			
		} else {
			if (q.peek() == 'D') {
				intAnswer -= 1;
				if (integerToCharacter(intAnswer) == strAnswer.at(j)) {
						intAnswer -=1;
				strAnswer += integerToString(intAnswer);
			}
		}
	}
}
		
		
	
