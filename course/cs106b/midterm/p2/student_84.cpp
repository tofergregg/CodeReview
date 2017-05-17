void transfer(Queue<int> & q, Stack<int> & s);

string decode(string seq) {
	
	Queue<int> numberQueue;
	Stack<int> numberStack;
	
	// To begin with, we should put "1" inside the stack.
	numberStack.push(1);
		
	for(int index = 0; index < seq.length(); index++){
		
		if(seq[index] == 'I'){
			transfer(numberQueue, numberStack);
		}
		
		numberStack.push(index + 2);
	}
	// Transfer all of the remaining numbers in the stack to the queue.
	transfer(numberQueue, numberStack);
	
	// At this point, the numbers are stored in the queue in the exact
	// order that they should be sequenced.
	string result = "";
	while(!numberQueue.isEmpty()){
		int next = numberQueue.dequeue();
		result += integerToString(next);
	}
	
	return result;
}

/* This method pops the top value from the stack, and enqueues it into
 * the queue until the stack becomes empty. The queue and the stack are
 * passed in as reference parameters.
 */
void transfer(Queue<int> & q, Stack<int> & s){
	while(!s.isEmpty()){
		int value = s.pop();
		q.enqueue(value);
	}
}