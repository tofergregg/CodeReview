string decode(string seq) {
	stack <int> sequenceStack;
	for (int i = seq.length(); i > 0; i--){
		sequenceStack.push(seq.at(i))
	}
Vector <int> output;
	if (sequenceStack.peek() == "I"){
		sequenceStack.pop();
		output+= 1;
	}
	else if (sequenceStack.peek() == "D"){
		sequenceStack.pop();
		output += sequenceStack.size() +1;
	}
	if (sequenceStack.peek == "I"){
		sequenceStack.pop();
		for (int i = 1; i < 10; i++){
			if (!output.contains(i)){
				output += i;
			}
		}
	}
	else if (sequenceStack.peek== "D"){
		sequenceStack.pop();
		for (int i = 9; i > 0; i--){
			if (!output.contains(i)){
				output+=i;
			}
		}
	}
	return output.toString();
