string decode(string seq) {
	int size=seq.length();
	stack<int> store;
	queque<int> nums;
	queue<int> out
	int numI,numD;
	for(int i=1;i<=size+1;i++){
		nums.enqueue(i);
	}
	for(int i=0;i<size;i++){
		if(seq[i]=="I"){
			out.enqueue(nums.dequeue());	
			out.enqueue(nums.dequeue());
		}else{
			store.push(nums.dequeue());
			out.enqueue(nums.dequeue());
			out.enqueue(store.pop());
		}
		
	}
		
	return toString(out);		
	
}

string toString(queue<int> & out){
	for(int i=0;i<queue.size();i++){
		string s;
		s+=integerToString(out.dequeue(i));
	}
	return s;
}
