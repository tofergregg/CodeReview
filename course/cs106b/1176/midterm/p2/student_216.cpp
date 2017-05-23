// Assume the input sequence length will be one to eight characters
// Run time should be at worst O(N)
string decode(string seq) {
	Stack<string> sequenceLetters;
	HashSet<int> usedInts;
	string result = "";
	string incOrDec = "";
	int maxNumber = seq.length() + 1;
	
	// Adds the sequence to a stack (which behaves via LIFO)
	for(int i = 0; i < seq.length(); i++){
		sequenceLetters.push(seq[i]);
	}
	while(result.length() != seq.length() + 1){
		incOrDec = sequenceLetters.pop();
		if(incOrDec == "I"){
			addMax(result, usedInts, maxNumber);		
		}else{
			int decCounter = 0;
			while(incOrDec != "I" || sequenceLetters.isEmpty()){
				incOrDec = sequenceLetters.pop();
				decCounter++;
			}
			addDec(result, usedInts, maxNumber, decCounter);
		}
		// Add last number to the result
		
	}
	
	
	
}

// Adds the numbers to the result string when "D"s are found in the stack
void addDec(string & result, HashSet<int> & usedInts, int maxNumber, int decCounter){
	for(int i = maxNumber; i > 0; i--){
		if(usedInts.contains(i){
			continue;
		}else{
			while(decCounter != 0){
				int value = i - decCounter;
				result = integerToString(value) + result;
				decCounter--;
			}
			result = integerToString(i) + result;
		}
	}
}
		   
// Adds	numbers to the result string when an "I" is found on the stack	  

void addMax(string & result, HashSet<int> & usedInts, int maxNumber){
	for(int i = maxNumber; i > 0; i--){
		if(usedInts.contains(i){
			continue;
		}else{
			result = integerToString(i) + result;
			usedInts.add(i);
		}
	}
}
