string decode(string seq) {
	string result;
	int n=1;
	stack<int> stack;
	Queue<int> queue;
	//put the first number 1
	stack.push(n);
	for (int=0;i<seq.length();i++) {
		//add the next number
		n++;
		stack.push(n);
		//if letter is 'D', take the number the previous number out, change order
		if (seq[i]=='D'){
			int last = stack.pop();
			int secLast = stack.pop();
			stack.push(last);
			stack.push(secLast);
		}
	}
	//return the result as a string
	while(!stack.isEmpty()){
		queue.enque(stack.pop());
		result += integerToString(queue.deque);
	}
	
	return result;
}
