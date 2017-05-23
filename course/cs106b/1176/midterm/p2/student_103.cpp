string decode(string seq) {

	Stack<int> waitList;
	Stack<int> output;

	for(int i = seq.length() - 1; i > -1; i--) {
		if(seq[i]=="I") {
			output.push(i+1);
			while(!waitList.isEmpty()){
				output.push(waitList.pop());
			}
		} else {
			waitList.push(i+1);
		}
	}
	
	string decoded = "";
	for (int i = seq.length(); i > 0; i--)) {
		string += integerToString(output.push());
	}
	
	return decoded;
	
	
	