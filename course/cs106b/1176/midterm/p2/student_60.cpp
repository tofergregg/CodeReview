string decode(string seq) {
	Queue<int> increasing;
	Stack<int> decreasing;
	string complete = "";
	
	for(int i = 0; i < seq.length(); i++){
		char c = seq[i];
		if( c == "I"){
			increasing.enqueue(i+1);

		} else if(c == "D"){
			decreasing.push(i+1);
		}
	}
	
	for(int j = 0; j < seq.length(); j++){
		char c = seq[j];
		if( c == "I"){
			complete += integerToString(increasing.dequeue());
		} else if(c == "D"){
			complete += integerToString(decreasing.pop());
		}
	}
	
	if(seq[seq.length() - 1] == "I"){
		complete += seq.length() + 1;
	} else if(seq[seq.length() - 1] == "D"){
		complete += seq.length()-(seq.length()-1);
	}
	return complete;
}
