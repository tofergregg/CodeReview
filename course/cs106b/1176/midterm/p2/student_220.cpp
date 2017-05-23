// I want to search from the end of the sequence, when come to the first I, set the sequence.length()+1, which is the largest number, there. And then keep search, stop until the first I, set the remaining largest number there.

string decode(string seq) {
	Stack<char> id;
	string output;
	int countd=0;
	int counti=0;
	Map<<int>, <int>> m;
	int length=seq.length();
	for (int i = 0; i < length; i++){
		id.push(seq[i]);
	}
	while(true){
		for (int j = 0; j < length; j++){
		char a = id.pop();
		if (a == 'D'){		
			countd++;
		} else {
			
			counti++;
			m[length-j+countd+1]=length-countd;
			break;
			
		}
		length-=(countd+counti);
	}
	
	
	for (int k=0;k<=length+1;k++){
		output+=integerToString(m[k]);
	}
	return output;
}
		
		
			
			
		
