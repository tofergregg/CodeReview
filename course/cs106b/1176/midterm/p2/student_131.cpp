string decode(string seq) {
	Vector <char> nextSeq;
	Stack<int> number;
	Queue<int> options;
	//Put all the letters that tell us if the number should increase or decrease in a vector
	for(int i = 0; i < seq.length(); i++ ) {
		nextSeq.add(seq.at(i));
	}
	for(int i = 1; i < 10; i++) {
		options.enqueue(i);
	}
		
	int index = 0;
	number.push(options.dequeue());
	while(index < nextSeq.size() - 1) {
		
		if(nextSeq[index] == 'I') {
			number.push(options.dequeue);
			index++;
		} else if(nextSeq[index] == 'D'){
			options.enqueue(number.pop());
			index--;
		}
	}
	
	string result;
	while(!number.isEmpty()) {
		result = integerToString(number.pop()) + result;
}


