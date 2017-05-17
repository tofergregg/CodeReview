string decode(string seq) {
	
	int max = seq.length() + 1;
	Queue<int> integers;
	for (int i = 1; i <= max; i++){
		integers.enqueue(i);
	}
	
	Stack<int> decoded;	
	decoded.push(integers.dequeue());
	
	for(int i = 0; i < seq.length(); i ++){
		if(seq[i] == 'D'){
			int temp = decoded.pop();
			decoded.push(integers.dequeue());
			decoded.push(temp);
		}else{
			decoded.push(integers.dequeue());
		}
	}
	
	return decoded.toString();
}


