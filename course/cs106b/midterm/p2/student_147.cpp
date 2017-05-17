string decode(string seq) {
	
	//I didn't have time to fully fix the code, but the idea is to keep a queue of digits that are in order. Then go through the string sequence. If the next character is I, then add the next digit in the queue to the resulting stack if it is greater than the previous, and vice versa for D. If the queue doesn't contain a digit that is valid (hits a dead end where for e.g. next char in seqence is "I", except there are no values greater than the previous one and therefore cannot increase), then pop off the stack (in otherwords backtrack and restart) and continue. Then it recurses for the next value until we find a combination that works (doesn't hit a dead end) and returns it. 
	
	Stack<int> result;	
	decodeHelper(seq, result);
	Queue<int> digits; //enqueue digits 1 to 9; 		
}

string decodeHelper(string seq, Stack<int>& result, Queue<int>& digits) {		
	
						 	 	 
		if (seq == ""){
			return result; 
		}
	
		if (seq[0] == "I") { //get next digit from queue of digits
			
			while (digits.dequeue > result.peek() { //keep going through the queue of digits until you get a larger one than before
				int current = digits.dequeue();
				digits.enqueue;
			}
			result.push(digits.dequeue);
			digits.dequeue; 
			decode(seq.erase[0], result, digits);
			result.pop
			 
		}
				   
		if (seq[0] == "D") {
			while (digits.dequeue < result.peek() { //keep going through the queue of digits until you get a smaller one than before
				int current = digits.dequeue();
				digits.enqueue;
			}
			result.push(current);
			digits.dequeue();
  			decode(seq.erase[0], result, digits);
			result.pop
				   
		}
	}						 						 
}

						 
						 