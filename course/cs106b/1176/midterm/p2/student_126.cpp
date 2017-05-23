string decode(string seq) {
	Queue<char> sequenceChars;
	queueSequence(seq,sequenceChars);
	Queue<int> numbers;
	queueNumbers(numbers);
	int temp;
	string finalStr = "";
	char previosChar;
	Stack<int> temp;
	int size = sequenceChars.size();
	if (size = 1) {
		if( sequenceChars.dequeue() == 'I') {
			str += "12";
		} else {
			str += "21";
		}
		
	}
	if(size > 1) {
		for (int x = 0; x<size; x++) {
			char init = sequenceChars.dequeue();
			if ( init == sequenceChars.peek() && init == 'I') {
				finalStr += numbers.dequeue();
				dequeueStack(finalStr, temp); 
			} else if (init == sequenceChars.peek() && init == 'D'){
				temp.push(numbers.dequeue());
			} else if ( init != sequenceChars.peek() && init == 'I') {
				finalStr += numbers.dequeue();
				dequeueStack(finalStr, temp); 
			} else if ( init != sequenceChars.peek() && init == 'D') {
				temp.push(numbers.dequeue());
			}
		}
		// checks in input is all D
		if (finalStr.size == 0){
			dequeueStack( finalStr, temp)
			finalStr = numbers.dequeue() + finalStr;
		} else {
			finalStr += numbers.dequeue();
		}
	}
	return finalStr;
}
	
void dequeueStack( string &str, stack<int> stack) {
	while(!stack.isEmpty()) {
		str += stack.pop();
	}
}
	
	
void queueNumbers(Queue<int> numbers) {
	for (int x=1; x<10; x++) {
		numbers.enqueue(x);
	}
} 
	
void queueSequence(int seq, Queue<char> & sequenceChars) {
	int size = seq.size();
	for(int x = 0; x<size; x++) {
		sequenceChars.enqueue(seq.at(x))
	}
}