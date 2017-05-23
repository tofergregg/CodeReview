string decode(string seq) {
	
	Queue<char> seqQueue;
	int dCount = 0;
	
	for (int i = 0; i < seq.length(); i++){
		// count quantity of Ds
		if (seq[i] == 'D'){
			dCount++;
		}
		
		// fill a queue with chararacters from seq. 
		// First char of seq is first in, first out of queue.
		seqQueue.enqueue(seq[i]);
	}
	
	int iCount = seq.length() - dCount;
	int startingValue = 1;
	
	if (dCount > iCount){
		startingValue = dCount + 1;
	}
	
	string result = integerToString(startingValue);
	int currentValue = startingValue;
	
	for (char ch : seqQueue){
		
		ch = seqQueue.dequeue();
		if (ch == 'D'){
			currentValue++;
		} else if (ch == 'I'){
			currentValue--;
		}
		result += integerToString(currentValue);
	}
	return result;
}
		
	
	
