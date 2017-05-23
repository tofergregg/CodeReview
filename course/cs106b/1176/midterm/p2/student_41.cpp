string decode(string seq) {
		Queue<int> numbers;
		Queue<char> letters;
		Stack<int> decreasingNumbers;
		int counter = 0;
		int decreasingCounter = 0;
		string answer = "";
	for (int n = 0; n < seq.size(); n++) {
		char direction = seq[i];
		letters.enqueue(direction);
	}	
		numbers.enqueue('1');
		counter++;
	while (!letters.isEmpty()) {
		char newMarker = letters.dequeue();
		if (newMarker == "I") {
		counter++;
			for (int n = 0; n < decreasingCounter; n++) {
				int number = decreasingNumbers.pop();
				numbers.put(number);
			}
			numbers.put(counter - decreasingCounter);
		} else {
			if (newMarker == "D") {
				decreasingCounter++;
				decreasingNumbers.push(counter + decreasingCounter + 1);
			}
		}
	}
	while (!decreasingNumbers.isEmpty()){
		for (int n = 0; n < decreasingCounter; n++) {
				int number = decreasingNumbers.pop();
				numbers.put(number);
			}
	}
	while (!numbers.isEmpty()){
		int finalNumber = numbers.dequeue();
		string answer.append(integerToString(finalNumber);
	}
	return answer;
}
							 
				
	
		
				
				
			
		
	
		
	
		

		
