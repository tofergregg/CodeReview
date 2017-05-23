string decode(string seq) {
	string result = "";
	int highestNum = seq.length() + 1
	Queue<int> decrQ;
	Queue<int> incrQ;
	Stack<int> decr;
	Stack<int> incr;
	Stack<int> allNums;
	int numD;
		for (int k = 0; k < seq.length(); k++) {
			if (seq[k] == 'D') {
				numD++;
			}
		}
	for (int j = 1; j <= highestNum; j++) {
		incr.push(j);
		decr.push(highestNum - (j - 1);
		if (seq[0] == 'I') {
			incrQ.enqueue(1);
			decr.pop();
		} else if (seq[0] == 'D') {
			if (numD == seq.length() {
				decrQ.enqueue(incr.pop());
				incr.pop();
			} else {
				decr.enqueue(1);
				decr.pop();
			}
		}
		if (seq[i] == 'I') {
			incrQ.enqueue(decr.pop(i));
			decr.pop();
		} else if (seq[i] == 'D') {
			decrQ.enqueue(incr.pop());
			incr.pop();
		}
	}			  
	for (int i = 0; i < seq.length(); i++) {
		if (seq[1] == 'I') {
			result.add(integerToString(incrQ.dequeue());
		} else {
			result.add(integerToString(decrQ.dequeue());
		}
	}
	return result;
}
					   
	/*string result = "";
		int highestNum = seq.length() + 1
		Queue<int> resultQ;
		int numI;
		int next;
	
		for (int i = 1; i <= highestNum; i++) {
			if (i == 0) {
				if (seq[0] == 'I') {
					resultQ.enqueue(1);
					//resultQ.enqueue(2);
					numI = 1;
					next = 2;
				} else if (seq[0] == 'D') {
					resultQ.enqueue(highestNum);
					//resultQ.enqueue(1);
					numI = 0;
					next = 1;
				}
			} else {
				if (seq[i - 1] == 'I') {
					resultQ.enqueue(next);
					next++;
					numI = i + 1;
				} else (seq[i - 1] == 'D') {
						for (int j = numI; j < i; j++) {
							next++;
						}
					resultQ.enqueue(next);
					next = 0;
				}
			}
		}
	for (int k = 0; k < seq.length(); k++) {
		result.add(integerToString(resultQ.deqeueue()));
	}
	return result;
}*/
	

							