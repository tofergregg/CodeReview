string decode(string seq) {
	Queue<int> number;
	int iCounter = 0;
	int dCounter = 0;
	Set<int> numLine;
	for (int i = 0; i < 9; i++){
		numLIne.add(i+1);	
	}
	
	for (int i = 0; i < seq.length(); i++){
		if (seq[i] == 'I'){
			iCounter++;
		} else if (seq[i] == 'D'){
			dCounter++;		
		}
	}
	if (seq[0] == 'I'){
		number.enqueue(1);
		numLine.remove(number.peek());
	}else if (seq[0] == 'D'){
		number.enqueue(seq.length() + 1);
		numLine.remove(number.peek());
	}
	
	for (int i = 1; i < seq.length(); i++){
		if (seq[i] == 'I'){
			if (!numLine.contains(number.peek()+1)){
				number.enqueue(number.peek()+1));
				numLine.remove(number.peek());	
			} 
			
		} else if (seq[i] == 'D'){
			number.enqueue(dCounter
		}
	}
}