string decode(string seq) {
	Queue<char> input;
	for(int j = 0; j < seq.length(); j++){
		input.add(seq[j]);
	}
	string output;
	int length = seq.length()+1;
	Queue<int> numbers;
	Stack<int> reverse;
	for(int i = 1; i <= length; i++) {
		numbers.enqueue(i);
		reverse.push(i);	
	}
	string firstNum = input.peek();
	if(firstNum == 'I'){
		output = numbers.dequeue();
	} else {
		output = reverse.pop();
	}
		
	while(!input.isEnpty()) {
		string current = input.dequeue();
		if(current == "I"){
			output = output + numbers.dequeue();
		} else {
			output = output + reverse.pop();
			
		}
	}
}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	

		
		
		
	}
	
		

}
