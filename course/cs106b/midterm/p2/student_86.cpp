string decode(string seq) {
	string output =""; 
	queue<char> sequence;
	for (int i = 0; i < seq.length(); i++) {
		sequence.enqueue(seq.at(i));
	}
	char letter = sequence.dequeue();
	while (! sequence.IsEmpty()) {
		int countD = 1;
		int countI = 1;
	if (letter =="I") {
		while (letter =="I") {
			countI ++;
			letter = sequence.dequeue();
		} 
		for (int i = 1, i < countI; i ++){
			output += integertoString(i);
	}	
	if (letter =="D") {
		while (letter =="D") {
			countD ++;
			letter = sequence.dequeue();
		} 	
		for (int i = countD; i > 0; i--) {
			output += integertoString(i);
		}	
	}	
	}
	return output;
	}		