string decode(string seq) {
	Set<int> canUseThese;
	Queue<char> input;
	string output;
	for(int i = 0; i <= numInt; i++){
		canUseThese += i;
	}
	for(int i = 0; i < numInt; i++){
		input.enqueue(seq[i]);
	}
	numInt = seq.length();
	Stack<int> numbers;
	if (input.dequeue() == 'I') {
		input.enqueue('I');
		numbers.push(1);
		output.append(1);
		canUseThese.remove(1);
	} else {
		input.enqueue('D');
		numbers.push(numInt + 1);
		output.append(numInt + 1);
		canUseThese.remove(numInt + 1);
	}
	while(!input.isEmpty()) {
		int currNum = numbers.pop();
		if(input.dequeue == 'I') {
		int min = INT_MAX;
		for(int possibleNum: canUseThese){
			if (possibleNum < min) {
				min = possibleNum;
			}
		}
		output.append(min);
		canUseThese.remove(min);
		} else {
			int max = -1;
			for(int possibleNum: canUseThese){
				if (possibleNum > max) {
					max = possibleNum;
				}
			}
			output.append(max);
			canUseThese.remove(max);
		}
	}
	return output;
}