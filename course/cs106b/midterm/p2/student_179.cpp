string decode(string seq) {
	string output;
	int down = 1;
	int up = 1; 
	Queue<string> decoding;
	for(int i = 0; i < seq.size(); i++){
		if(seq[i] == "D") down++;
		decoding.enqueue(seq[i]);
	}
	if(seq[0] == "I"){
		output += integerToString(up);
		up++;
	} else {
		output += integerToString(down);
		down--;
	}
	for(int j = 1; j <= seq.size(); j++){
		string test = decoding.dequeue(seq[i - 1]);
		if(test == "I"){
			output += integerToString(up);
			up++;
		} else {
			output += integerToString(down);
			down--;
		}		
	}
	return output;	
}