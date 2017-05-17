string decode(string seq) {

	//put all the options into a queue
	int n = seq.length();
	string possNumbers = ""
	for(int i = 1; i <= n+1; i++){
		possNumbers += i;
	}
	string soFar = "";
	Queue<string> options;
	getAllCombinations(soFar, possNumbers, options);
	
	//check for the options that meet the rule
	
	Stack<string> validOptions;
	
	while(!options.isEmpty()){
		string current = options.dequeue();
		if(checkValidOptions(seq, current)){
			validOptions.push(current);
		}
	}

	//find which one is the minimum
	
	int min = MAX_INT;
	while(!validOptions.isEmpty){
		int topValue = stringToInteger(validOptions.pop());
		if(topValue < min){
			min = topValue;
		}
	}
	
	
	return integerToString(min);
}

//Recursive function: get all combinations- useful b/c you know that a sequence of N numbers will always use the numbers 1 through N

void getAllCombinations(string soFar, string possNumbers, Queue<string> &options){
	
	if(possNumbers = ""){
		options.enqueue(soFar);
	}else{
		string rest = possNumbers.substr(0, i) + possNumbers.substr(i+1);
		getAllCombinations(soFar+possNumbers[i], rest, options);
	}
	
}

//function checks whether the output meets the rules
bool checkValidOptions(const string seq, string current){
	
	for(int i = 0; i<n; i++){
		char incOrDec = seq.at(i);
		if(char = 'I'){
			if(stringToInteger(current[i+1]) > stringToInteger(current[i])){
				return false;
			}
		}else if(char = 'D'){
			if(stringToInteger(current[i+1]) < stringToInteger(current[i])){
				return false;
			}
		}	
	}
	
	return true;
	
}