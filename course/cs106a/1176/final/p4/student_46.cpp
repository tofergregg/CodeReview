string decode(string seq) {
	string result;
	Queue<int> increasing();
	for(int i=1; i<=seq.size()+1; i++){
		increasing.enqueue(i);
	}
	Queue<char> sequence();
	for(int i=0; i<seq.size(); i++){
		sequence.enqueue(seq.at(i));	
	}
	Stack<int> decreasing();
	while(!increasing.isEmpty()){
		if(sequence.peek()=='I'){
			result+=integerToString(increasing.dequeue());
			sequence.dequeue();
		} else {
			decreasing.push(increasing.dequeue());
			while(sequence.peek()=='D'){
				sequence.dequeue();
				decreasing.push(increasing.dequeue());
			}
			while(!decreasing.isEmpty()){
				result+=integerToString(decreasing.pop());
			}
		}
	}
	return result;
}

//Should I be doing this recursively??? I feel like maybe???
//This doesn't seem like it should be that hard but it defies all logic

	
	