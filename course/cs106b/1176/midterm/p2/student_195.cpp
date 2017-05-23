string formString (Queue<int>& almostResult , string& result);
string decode(string seq) {
	int min = 1; 
	int max = 9; 
	Queue<string> currSeq; 
	int n = randomInteger ( min, max ); 
	Queue <int> almostResult; 
	almostResult.enqueue(n); 
	for (int i = 0; i < seq.size(); i++) {
		currSeq.enqueue(charToString(seq[i])); 
	}
	// reset the values of min and max to the previous value of n while there are more letters in the queue. 
	while(!currSeq.isEmpty()) {
		if(currSeq.dequeue() == "I") {
			max = 9; 
			if(n != 9) min = n + 1; 
			else min = n; 
			n = randomInteger(min, max); 
			almostResult.enqueue(n); 
			
			
		}else{
			min = 1;
			if(n != 1)max = n - 1; 
			else max = n; 
			n = randomInteger(min, max);
			almostResult.enqueue(n); 
		} 
	}		
	string result = ""; 
	result = formString(almostResult, result); 
	return result; 
}
	
string formString (Queue<int>& almostResult , string& result) {
	while(!almostResult.isEmpty()) {
		int next = almostResult.dequeue();
		string toAdd = integerToString(next);
		result += toAdd; 
	}
        return result;
}
