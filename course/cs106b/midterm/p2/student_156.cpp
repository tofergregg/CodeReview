string decode(string seq) {
	string output = "";
	int start = 0;
	if (seq[0] == "D"){
		start = seq.length()+1;
	}
	else {
		start = 1;
	}
	int currentNum = start;
	output += integerToString(start);
	Queue <char> queue;
	for (int i = 0; i <seq.length(); i++){
		queue.enqueue(s[i]);
	}
	for (int i = 0; i < seq.length(); i++){
		char current = queue.dequeue();
		if (!queue.isEmpty()){
			char next = queue.peek();	
			if (current == "I"){
				if (next == "D"){
					output += integerToString(2*currentNum+1);
				}
				else{
					output = output + integerToString(currentNum+1);
				}
			}
			else if (current == "D"){
				output = output + integerToString(currentNum-1);
			}
		}
		else{
			if (current == "I"){
				output = output + integerToString(currentNum+1);
			}
			else{
				output = output + integerToString(currentNum-1);
			}
		}	
	}
	return output;
}