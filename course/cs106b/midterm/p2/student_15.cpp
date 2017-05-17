string decode(string seq) {
	// Create a queue of all the numbers 1-9 that can be used
	// Could just use a counter or something. 
	// Don't really need a stack
	// Try alternate later
	Queue<int> numbers;
	for (int i=1; i<10; i++){
		numbers.enqueue(i);
	}
	// String to store result
	string result = "";
	
	// Remember index in string seq
	// Also consider trying to use substring
	int counter = 0;
	
	// How to store seq, or loop through it? Queue?
	// while seq.length() != result.length()
	Queue<string> seqQueue;
	for (int i=0; i< seq.length(); i++){
		seqQueue.enqueue(s[i]);
	}
	// temp = stack for temporarily storing for runs of Ds
	Stack<int> temp;
	// Now go through the seq and get Is and Ds
	while (!seqQueue.isEmpty()){
		while (seqQueue.peek() == "I"){
			seqQueue.dequeue();
			result += numbers.pop();
		}
		// In case of "D", need to pop off stack and
		// temporarily store in temp stack until run
		// of D's is complete (get highest D needed)
		while (seqQueue.peek() == "D"){
			temp.push(numbers.pop());
		}
		while (!temp.isEmpty()){
			result += temp.pop();
		}
	}
	return result;
}
		
			
		
		
		
