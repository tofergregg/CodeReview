string decode(string seq) {

	Stack<char> seqStack;
	Queue<string> output;
        Set<int> outputSet;
	for (int i = seq.length() - 1; i > 0; i--) {
		seqStack.push(seq[i]);
	}
	
	int number = 1;
	for (int i = 0; i < seq.length() - 1; i++) {
		char nextLetter = seqStack.peek();
		int count = 0;
		
		if (nextLetter == 'D') {
			
			while (nextLetter == 'D') {
				seqStack.pop();
				count++;
				i++;
				nextLetter = seqStack.peek();
			}
			seqStack.pop();
			count++;
			i++;
		
			int total = number + count;
			total++;
			while (outputSet.contains(total)) {
				total++;
			}
			outputSet.add(total);
			output.enqueue(integerToString(total));

			
			while (count > 0) {
				number--;
				output.enqueue(integerToString(number));
				count--;
			}

		} else {
			if (i==0) {
				number++;			
				output.enqueue(integerToString(number));
				number++;
				output.enqueue(integerToString(number));
			} else {
				number++;
				while (outputSet.contains(number)) {
					number++;
				}
				seqStack.pop();
				output.enqueue(integerToString(number));
		}
	}
    }	
    string toReturn;
    for (int i = 0; i < output.size() - 1; i++) {
            toReturn += output.dequeue();
    }
	
    return toReturn;
}
	
	
			
	

				
