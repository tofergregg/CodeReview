string decode(string seq) {
	
	Queue<string> output; 
	
	int firstNum;   
	firstNum = randomInteger(1,8);
	string firstOutput = integerToString(firstNum); 
	output.enqueue(firstOutput); 
	
	// for loop through each character in string and depending on 	  //if the character is an I or a D, act accordingly
	for (int i = 0; i < seq.length()) {
		if (seq == 'I) { 
			// generate new number from previous number to 9
			int nextRandInt = (firstNum, 9); 
			string nextInt = integerToString(firstOutput); 
			output.enqueue(nextInt); 
			firstNum = nextRandInt; 
		} else if (seq == 'D) {
			// generate a new number lowest to highest as previous
			int newRandInt = (1, firstNum)
			string nextInteger = integerToString(newRandInt); 
			output.enqueue(nextInteger); 
			firstNum = newRandInt;
		}
	}
	string final; 
	while (!output.isEmpty()) {
		output.dequeue(); 
		output.toString(); 
		
	}
		
	return string; 
}
				  
	