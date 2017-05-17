string helper1(HashSet<int> & rem;
		queue<int> seqQ;
		int & min
		int & last
		string answer) {
	//base case: no numbers remaining
	if(seqQ.isEmpty() {
		if(stringToInteger(answer) < min) {
			string bestAnswer = answer;
			min = stringToInteger(answer);
			}

		
	}
	//recusive case: number remaining
	//first call
	if(min == INT_MAX) {
		for(int first : rem) {
			rem.remove(first);
			int last = first;
			string answer = integerToString(first).append( 										helper(rem,seqQ,min,last));
			rem.add(first)
		}
	}
	string nextOrder = seqQ.dequeue();
	if(nextOrder == I) {
	//pick a non-used number above the last number	
		for(int next : rem) {
			if(next > last) {
				last = next;
				rem.remove(next);
				answer = helper(rem,seqQ,min
				,last).append(integerToString(next));
				rem.add(next);
			}
		}
	} else {
	//pick a non-used number below the last number	
		for(int next : rem) {
			if(next < last) {
				last = next;
				rem.remove(next);
				string answer = integerToString(next).append( 										helper(rem,seqQ,min,last))
				rem.add(next);
			}
		}
	}
	return bestAnswer;
	
}

string decode(string seq) {
	//make a set containing remaining numbers
	HashSet<int> rem;
	for(int i = 1; i <= 9; i++) {
		rem.add(i);
	}
	//make the minimum number
	int min = INT_MAX;
	//make a queue of the sequence
	queue<int> seqQ
	for(int i = 0; i < seq.length(); i++) {
		seqQ.enqueue(stringToInteger(seq[i]));
	}
	return helper1(rem,seqQ,min);
}
