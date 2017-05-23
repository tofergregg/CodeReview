string decode(string seq) {
	Queue<int> result;
	Set<int> used;
	string endString;
	if(seq[0] == I) {
		result.enqueue(1);
		used.add(1);	
	} 
	else {
		result.enqueue(seq.size() + 1);
		used.add(seq.size() + 1);
	}	
	for (int i=1; i < seq.size(); i++) {
		if(seq[i] == I) {
			if(!used.contains(result.peek() + 1)){
				result.enqueue(result.peek() + 1);
				used.add(result.peek() + 1);
			}
			else {
				result.enqueue(result.peek() + 2); 
				used.add(result.peek() + 2);
			}
		}
		else {
			if(!used.contains(result.peek() - 1)){
				result.enqueue(result.peek() - 1);
				used.add(result.peek() - 1);
			}
			else {
				result.enqueue(result.peek() - 2);
				used.add(result.peek() - 2);
			}
		}
	}
	while(!result.isEmpty()){
		endString.append(result.dequeue());
	}
	return endString;
)	


// Pseudocode: look at sequence. If first char is I, add 1 to the result queue and add 1 to used set. If first char is D, print out the length of seq + 1. If the next char is I, queue result.peek()+1 and store that in used. If a D comes right after an I, update the queue so that instead of imcrementing by one, it will add two or more, depending on which char is next.

// If all Is, print increasing numbers, same for all Ds but decreasing #s. 
		