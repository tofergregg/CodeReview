string decode(string seq) {
	int outPutLength = seq.length()+1;
	Queue<int> queue;
	Stack<int> stack;
	string outPut;
	for(int i=1;i<=seq.length();i++) {
		queue.enqueue(i);
		stack.push(i);
	}
	if(seq[0]=='I') {
	int result = queue.dequeue();
	string res = integerToString(result);
	output = output + res;
	}
	else {
	int result = stack.pop();
	string res = integerToString(result);
	output = output + res;
	}		
	for(int j=1;j<=seq.length();j++) {
		if(seq[j]=='I') {
			int result = queue.dequeue();
			string res = integerToString(result);
			output = output + res;
		}
		if(seq[j]=='D') {
			int result = stack.pop();
			string res = integerToString(result);
			output = output + res;
		}
	}
	return output;
}
			