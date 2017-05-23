string decode(string seq) {
	
	Stack<int> numbers;// will contain our final order with first element at bottom of stack
	numbers.push(1);
	for(int i = 2; i <= seq.length() + 1; i++) {
		Stack<int> helper; // will help oredering on the fly
		helper.push(i);
		
		// looping through string of IsDs every single time we add
		// a new number
		for(int c = i - 2; c >= 0; c--) {
			int anterior = numbers.pop();
			int posterior = helper.pop();
			
			if(seq[c] == "I"){
				helper.push(posterior);
				helper.push(anterior);
			} else {
				helper.push(anterior);
				helper.push(posterior);
			}
		}
		
		//Puting them in the original stack
		while(!helper.isEmpty()) {
			numbers.push(helper.pop())
		}
	}
	
	// Reversing the order and that is the result
	
	string result = "";
	while(!numbers.isEmpty) {
		result = integerToString(numbers.pop()) + result;
	}
	return result;
}
		
