string decode(string seq) {
	//takes in a string and 
	//returns a string that represents the minimum number without repeating 	any digits
	
	//gets the first digit of the sequence
	
	int dCounter;
	int iCounter;
	
	for(int i=0; i<seq.length(); i++) {
		if (seq.at(i)== "I") {
			iCounter++;
		} 
		 if (seq.at(i) == "D") {
			 dCounter++;
		 }
			
	}
	
	int first  = 9 - dCounter + 1;
	Queue<string> returnsequence;
	Set<int> set;
	Vector<int> numbersused;

	int firstdigit = randomInteger(first,length-1); //gets first digit
	set.add(firstdigit);
	numbersused.add(firstdigit);
	returnsequence.enqueue(integerToString(firstdigit));
	
	
	//loops through string and adds numbers to the vector 
	for(int i=0; i<seq.length(); i++) {
		if (seq.at(i) == "I") {
			int currNum = numbersused(i);
			
			int rando = randomInteger(currNum+1,9);
			while (set.contains(rando) {
				rando = randomInteger(currNum+1,9);
			}
			
			returnsequence.enqueue(integerToString(rando));
			numbersused.add(rando);
				   set.add(rando);
			
		}	
		
		else {
			int currNum = numbersused(i);
			
			int rando = randomInteger(1,currNum-1);
			while (set.contains(rando) {
				rando = randomInteger(1,currNum-1);
			}
			
			returnsequence.enqueue(integerToString(rando));
			numbersused.add(rando);
			set.add(rando);

	}
	
	int length2 = returnsequence.size();
	
	string result;
	for(int i = 0; i<length2; i++ {
		result = result + returnsequence.dequeue();	
	}
	
	
	return result;

	
	
}
