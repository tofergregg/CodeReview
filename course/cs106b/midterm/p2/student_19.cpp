string decode(string seq) {
	start = 0;
	sum = 0;
	Stack<int> finalStack;
	Stack<char> stack;
	for (int i = 0; i < seq.length(); i++) {
		stack.push(seq[i])]
	}
	for (int i = 0; i < seq.length(); i++) {
		temp1 = stack.peek();
		sum = 0;
		if (stack.peek() == 'I') {
			while(stack.peek() == 'I') {
				sum += 1;
				stack.pop();
			}
			for (j = 0; j < sum; j++){
				finalStack.push(j);
				
			}
		}
		else if (stack.peek() == 'D') {
			while(stack.peek() == 'D') {
				sum += 1;
				stack.pop();
			}
			for (j = 0; j < sum; j++) {
				finalStack.push(sum);
				sum--;
			}
		}
	}
	string newstring;
	while (!stack.isEmpty()) {
		newstring += integerToString(stack.pop());
	}
	return newString;
}
				
		
			
			
		
		/* test = seq[0];
		if (seq[0] == 'I'){
			ourQueue.enqueue(-1);
		}
		else if (seq[0] == 'D'){
			ourQueue.enqueue(1);*/ 
			
