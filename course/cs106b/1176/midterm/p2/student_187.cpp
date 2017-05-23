string decode(string seq) {
	int start = 1; 
	string temp = "";
	Stack<char> decoding;
	string output = "";
	int count = 0;
	while (seq.length() > 0){
		while(seq[0] == 'I'){
			decoding.push('I');
			temp.add(seq[0]);
			seq.erase(0,1);
		} 
		while (seq[0] == 'D'){
			if (!decoding.isEmpty()) {
				
				decoding.pop();
			} else {
				decoding.push('D') 
			}
			temp.add('D');
			seq.erase(0,1);
		} 
		int newStart = 0;
		if (count == 0) {
			newStart = start + decoding.size();
		else {
			newStart = start + decoding.size() + 1;
		}
		output += newStart; 
		while (temp.length() != 0) {
			if (temp[0] == 'I') {
				if (
				newStart++;
				output += newStart;
			} else {
				newStart--;
				output += newStart;
			}
			temp.erase(0,1);
		}	
		start = newStart;
		while (!decoding.isEmpty()){
			decoding.pop();
		}
		count++;
	}
	return output;
}
					
		
		
		