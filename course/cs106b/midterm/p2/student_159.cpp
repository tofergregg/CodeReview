string decode(string seq) {
	string num; // declare string to hold answer
	queue<string> smallNums; // to order numbers in ascending order
	int numSize = seq.size()+1;
	int numD=0;
	
	Set<char> set; // create set to store used chars for 'D's in the seq
	
	// fill collection. Count # of D's
	for(int i=1; i<=seq.size(); i++) { // add numbers to be used in the string to the big and small number collections
		smallNums.enqueue(i);
		if(seq[i]=='D') {
			numD++
		}
		
	}
	smallNums.enqueue(numSize);
		
	
	// create number
	int discard=0; // create discard int for numbers in queue that have already been used
	for(int i=0; i<seq.size(); i++) {
		if(seq[i]=='I') { // for an 'I' dequeue next lowest number. see if the set of used numbers contains this number. if not, add.
			if(set.containsKey(i)) {
				discard+=smallNums.dequeue();
			}
			num+=smallNums.dequeue();
		} else { // otherwise, sequence has a 'D' at that index
			int numToAdd = integerToString(numD+1) + 1; // peak at next highest number and add one for a 'D'
			num+=numToAdd;
			numD--; // update the remaining number of 'D's
			set.add(numToAdd); // update set w/ this number so that it doesn't appear in the num string again
		}
	}
	// add last number
	num+=smallNums.dequeue();
	
	return num;
}