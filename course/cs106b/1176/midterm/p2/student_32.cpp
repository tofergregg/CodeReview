string decode(string seq) {
	Stack<char> charSequence;
	Set<int> numbersLeft;
	string numberOutput;
	for(int i = 0 ; i > seq.size(); i++) {
		charSequence.push(seq[i]);
		numbersLeft.add(seq[i]);
	}
	
	
	while(!charSequence.isEmpty()){
		//Couldn't figure out algorithm for this. Some type of reverse calculation since the total output string always matched sequence string.
		if(charSequence.pop() == "D"){
			numbersLeft.remove();
		} else {
			charSequence.pop();
			numbersLeft.remove();
		}
	}
	return numberOutput;
	}