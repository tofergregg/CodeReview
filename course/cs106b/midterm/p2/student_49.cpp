string decode(string seq) {
	//Declare Variables
	Stack<int> numberPool;
	Stack<int> runningNumber;
	Stack<int> finalNumber;
	string outPut;
	
	//initialize a stack of numbers
	if(seq[0] == "D"){
		for(int i = 1; <= seq.size(); i++){
			numberPool.push(i);
			lastChar = 'D';
		}
	
	}else{
		for(int i = seq.size(); >= 1; i--){
			numberPool.push(i);
			lastChar = 'D';
		}
	
	}
	
	//add the first two number.  They will be correct because of the previous steps
	
	runningNumber(numberPool.pop());
	runningNumber(numberPool.pop());
	
	for(int j = 1; j < seq.size(); j++){
	
		if (seq[j] == 'D' && numberPool.peek() < runningNumber.peek()){
			
			runningNumber(numberPool.pop());
			
		} else if(seq[j] == 'D' && numberPool.peek() > runningNumber.peek()){
			int temp = runningNumber.pop();
			runningNumber(numberPool.pop());
			runningNumber(temp);
		} else if(seq[j] == 'I' && numberPool.peek() > runningNumber.peek()){
			runningNumber(numberPool.pop());
		} else if(seq[j] == 'I' && numberPool.peek() < runningNumber.peek()){
			int temp = runningNumber.pop();
			runningNumber(numberPool.pop());
			runningNumber(temp);
		}
		
	}
	
//move the current stack to a new stack to print to a string
	
	
	for (int i = 0; i < runningNumber.size(); i++){
	
		finalNumber.push(runningNumber.pop();
	}
						 
						 
	//now convert to a string
	for (int k = 0; k < finalNumber.size(); k++){
	
		output.add(integerToString(finalNumber.pop()));
	}
						 
 	return output;
		
		
	
