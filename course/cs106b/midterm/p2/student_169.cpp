string decode(string seq) {
	/*Queue<bool> sequence;
	for(int i = 0; i<seq.length(); i++){
		if(seq[i]=='I'){
			sequence.enqueue(true);
		}
		else{
			sequence.enqueue(false);
		}
	}
	
	Queue<int> result;
	
	while(!sequence.isEmpty){
		if(sequence.enqueue){
			result.push(
		}
	}*/
	
	Queue<int> incr;
	for(int i = 1; i < 9; i++){
		decr.enqueue(i);
	}
	Queue<int> decr;
	for(int i = -1; i>-9; i--){
		incr.enqueue(i);
	}
	
	Queue<int> result;
	result.enqueue(0);
	for(int i = 0; i<seq.length(); i++){
		if(seq[i]=='D'){
			result.enqueue(decr.dequeue());
		}
		else{
			result.enqueue(incr.dequeue());
		}
	}
	int scale = 0-decr.dequeue();
	string answer;
	for(int i = 0; i<seq.length(); i++){
		answer+=integerToString(result.dequeue() + scale);
	}
	return answer;
}
