string decode(string seq) {

	Queue<string> letters;
	string yourNumbers;
	int counter = 1; 
	int backCounter = letters.size() + 1'
	
	
	for (int i = 0; i < seq.length(); i++) {
		
		letters.enqueue(seq.substr(i, 1));  //add each letter to q 
		
	}
	
	if (letters.peek() == "I") {
		yourNumbers = "1";
	}
	
	if letters.peek() == "D") {
		yourNumbers == intergerToString(backCounter);	
	}
	
	
	
	for (int i = 1; i < letters.size(); i++) {

		
		if (letter.dequeue() == "I") {
		counter++;
			
	yourNumbers = yourNumbers.append(integerToString(counter));
		
		}
	
		
		if (letter.dequeue() == "D") {
		
		backCounter--; 
	yourNumbers = yourNumber.append(interToString(backCounter));
	
		
		}
	
	
	
	}
	
	return yourNumbers;
	
	
	
}
