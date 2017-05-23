string decode(string seq) {
	Queue<char> q;
	string result;
	for(char ch = '1', ch < '1' + seq.length; ch++){
		s.enqueue(ch);
	}
	result += s.dequeue;
	for(int i = 0, i < seq.length; i++){
		char c = seq[i];
		if(c == 'D'){
			result = s.dequeue + result;	
		} else {
			result += s.dequeue;	
		}
	}
	return result;
}
			
			
		

