string decode(string seq) {
	// determine starting number
	int first = 1;
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == 'D') first++;
		else first--;
	}
	if (first < 1) first =  1; // make sure the starting number is at least 1
	
	queue<int> output;
	output.enqueue(first);
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == 'D') first--;
		else first ++;
		output.enqueue(first);
	}
	
	string answer;
	for(int i = 0; i < output.size(); i++) {
		answer += integerToString(output.dequeue());
	}
	
	return answer;
}
		
