string decode(string seq) {
	Queue<int> Ique;
	Stack<int> stack;
	string output;
	for (int i=1; i<seq.length()+1;i++){
		Ique.enqueue(i);
		stack.push(i);
	}
	
	for (int j=0; j<seq.length();j++){
		if (seq[j]=='I'){
			int next=Ique.dequeue();
		}
		else{
			next=stack.pop();
			
		}
		string nextStr=integerToString(next);
		output+=nextStr;
		return output;
	}
			
		
