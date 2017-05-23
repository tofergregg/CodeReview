string decode(string seq) {
	Stack<int>decode;
	Set<int>usedNums;
	if(seq.length() == 0) return integerToString(randomInteger(1,9));
	
	int startingValue = 5; //chose this value as is good midpoint
	decode.push(startingValue);
	int counter = 0;
	while(counter != seq.length() - 1){
		string currStep = seq[counter];
		if(decode.isEmpty()){
			decode.push(randomInteger(1,9));
		}
		int prev = decode.peek();
		int next = prev; 
		if(currStep == "I"){
			while(usedNums.contains(next) && next !> 9){
				next++;
			}
			if(next == prev){ //no new value found, must move one step back
			 decode.pop();
			 counter--;
			} else{
				usedNums.add(next);
				decode.push(next);
			}
			
		} else{ //if D
			while(usedNums.contains(next) && next !< 1){
				next--;
			}
			if(next == prev){ //no new value found
			 decode.pop();
			 counter--;
			} else{
				usedNums.add(next);
				decode.push(next);
			}
		}
	}

	return reverseToPrint(decode); 
}

//Method to get stored information in stack in right order as stack will print opposite
string reverseToPrint(Stack<int>& decode){
	Stack<int>tmp;
	tmp = decode;
	string toPrint; 
	for(int i = decode.size(); i > 0; i--){
		int next = tmp.pop();
		toPrint += integerToString(next);
	}
	
	return toPrint;
}
	
	