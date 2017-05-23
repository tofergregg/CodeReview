string decode(string seq) {

	int numDs = 0;
	Queue <string> sequence;
	for(int i = 0; i < seq.size(); i++){
		string temp = seq.substr(i, i+1);
		if(temp == "D"){
			numDs++;
		}
		sequence.enqueue(temp);
	}
	Stack <int> lowNums;
	Queue <int> highNums;
	for(int i = 1; i <= 9; i++){
		if(i <= numDs){
			stack.push(i);
		}
		else if(i>numDs + 1){
			highNums.enqueue(i);
		}
	}
	string result = "" + integerToString(numDs);
	while(!sequence.isEmpty()){
		string letter = sequence.dequeue();
		if(letter == "D"){
			result+= integerToString(lowNums.pop());	
		}
		else{
			result+= integerToString(highNums.dequeue());
		}
	}
	
	return result;
}