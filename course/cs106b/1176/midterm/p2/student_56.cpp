string decode(string seq) {
	
	//Puts the letters of teh word into a queue
	Queue<char> wordLetters;
	for (int i = 0; i <seq.length(); i++){
		char letter = seq[i];
		wordLetters.enqueue(letter);				
	}
	
	//Creates a set that will have all of the single-digit numbers that will be used in the creation of the end result number
	Set<int> numbersToUse;
	for (int i = 1; i <= wordLetters.size()+1; i++){
		numbersToUse.add(i);
	}
	
	//I will concatenate numbers onto tis string;
	string finalNumber = "";
	
	int Is = 0;
	int Ds = 0;
	int inARow = 0;
	
	for (int i = 0; i <= wordLetters.size(); i++){
		
		//checks to see how many I's or D's are in a row
		char currentLetter = seq[i]
		char nextLetter = currentLetter;
		while(nextLetter == currentLetter){
			if(nextLetter == 'I'){
				Is++;
			}
			if(nextLetter == 'D'){
				Ds++;
			}
			inARow++;
			currentLetter = nextLetter;
			nextLetter = seq[i+inARow];
		}
		
		if(seq[i] == I''){
			
			
		}
		
	}
		
	
	
	
	//returns the smallest number
	return smallestNum; 
}

