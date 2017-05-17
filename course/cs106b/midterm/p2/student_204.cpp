string decode(string seq) {

	Queue<int> inc;
	Stack<int> dec;
	
	if(seq[0] = 'I'){
			inc.enqueue(1);
		}else{
			dec.push(1);
		}
	
	for(int i = 1; i < seq.size()+1; i++){
		if(seq[i] = 'I'){
			inc.enqueue(i);
		}else{
			dec.push(i);
		}
	}
	
	string answer = "";
	
	if(seq[0] = 'I'){
			answer += inc.dequeue();
		}else{
			answer += dec.pop();
		}
	
for(int i = 1; i < seq.size()+1; i++){
	if(seq[i] = 'I'){
		answer += inc.dequeue();
	}else{
		answer += dec.pop();
	}
}
	
	return answer;
	
}