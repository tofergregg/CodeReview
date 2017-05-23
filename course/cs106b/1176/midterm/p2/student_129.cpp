string decode(string seq) {
	queue<int> numSeq;
	queue<int> tempNumSeq
	int numIsInRow = 0;
	int numDsInRow = 0;
	if (seq[0] == 'I') {
		currentNum = 1;
	} else {
		currentNum = 2
	}
	numSeq.enqueue(currentNum);
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == 'I') {
			currentNum++;
		} else {
			if (currentNum == 1) {
				for (int j = 0; j < numSeq.size() - 1; j++) {
					tempNumSeq = numSeq.dequeue;
					numSeq = tempNumSeq;
					i--
				}
			}
			currentNum--;
		}
		numSeq.enqueue(currentNum);
	}
	string numSeqStr = "";
	for (int j = 0; j < numSeq.size(); j++) {
		numSeqStr += numSeq.dequeue;
	}
	return numSeqStr;
}


*/
/*
Didnt have time but I was going to use this double for loop to check all the letters ahead of the current one in the sequence to determine the minimum number.
If I had more time I would mayb try to use both a stack and a queue so I could peek and pop and backtrack when I determined what values the sequence had.
I was also thinking of keeping track of the number of Ds or Is in a row to determine what value I could use in advance.
for (int i = 0; i < seq.size(); i++) {
		for(int j = i + 1; j < seq.size(); j++) {
			
*/