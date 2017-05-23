string decode(string seq) {
	int length = seq.size()+1;
	string str;
	int increases;
	int decreases;
	Queue<int> queue;
	Stack<int> stack;
	Vector<int> values;
	
	for (int i = 1; i <= length; i++) {
		queue.enqueue(i);
		stack.push(i);
		values.add(i);
	}
	
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == 'I') {
			increases++;
		}
		if (seq[i] == 'D') {
			decreases++;
		}
	}
	
	for (int i = 0; i < length; i++) {
		
		//seeing if there are any "I"s following to see what value to choose
		int increasingCount;
		if (seq[i] == 'I') {
			while (seq[i] == 'I' && i < length) {
				increasingCount++;
				i++;
			}
			str = str + value(i);
		}
		
		int decreasingCount
		if (seq[i] == 'D') {
			while (seq[i] == 'D' && i < length) {
				decreasingCount++;
				i++;
			}
			str = str + value(value.size()-i);
			
			//or
			/*for (int i = 0, i < seq.size(); i++)
			 stack.pop();
			 stack
			*/
		}
	}
	
	}
	return str;
}
	
	/* numbers in increasing order: queue
		numbers in decreasing order: stack
	*/
	




/* for (int i = 1; i <= length; i++) {
		queue.enqueue(i);
		stack.push(i);
	}
*/

/* for (int i = 0; i < seq.size()/2; i++) {
		if seq[i] == 'I' {
			int num1 = queue.dequeue();
			int num2 = queue.dequeue();
			string number1 = integerToString(num1);
			string number1 = integerToString(num2);
			str = str + num1 + num2;
		}
		if seq[i] == 'D' {
			int num = stack.pop();
			string number = integerToString(num);
			str = str + num;
		}
		*/
		
		
	/*Put all values onto a queue and onto a stack
	queue has values 123456789 (or however many numbers were entered)
	stack has values 987654321
	
	
	
	If letter is "I", take from the queue, this will increase
	If letter is "D", take from the stack, this will decrease
	Make sure the number has not been used before--this is taken care of because we always go from the lowest or highest possible
	*/
	
