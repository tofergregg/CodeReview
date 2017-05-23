string decode(string seq) {
	Queue<int> output;
	Queue<char> input;
	Vector<int> alreadyOutput;
	int sequenceLength = seq.size();
	int largestVectorValue;
	int smallestVectorValue;
	String output;
	for (int i = 0; i < seq.size; i++) {
		char sequence = seq[i];
		input.enqueue(sequence);
	}
	char inputOne = input.dequeue();
	if (inputOne == 'I'&& input.peek() == 'D') {		
		output.enqueue(1);
		alreadyOutput.add(output.peek);
		output.enqueue(output.peek+1);
		alreadyOutput.add(output.peek);
	} else if (inputOne == 'I' && input.peek() == 'I') {
		output.enqueue(1);
		alreadyOutput.add(output.peek);
		output.enqueue(output.peek + 1);
		alreadyOutput.add(output.peek);
	} else if (inputOne == 'D' && input.peek() == 'I') {
		output.enqueue(seq.size-1);
		alreadyOutput.add(output.peek);
		output.enqueue((output.peek)-1);
		alreadyOutput.add(output.peek);
	} else if (inputOne == 'D' && input.peek() == 'D') {
		output.enqueue(seq.size+1);
		alreadyOutput.add(output.peek);
		output.enqueue((output.peek)-1);
		alreadyOutput.add(output.peek);
	
	for (int i = 1; i < seq.size(); i++) {
		char input = input.dequeue();
		if (input == 'I') {
			for (int i = 0; i < alreadyOutput.size; i++) {
				int currentVectorValue = alreadyOutput[i];
				if (currentVectorValue > largestVectorValue) {
					currentVectorValue = largestVectorValue;
				}	
			}
			output.enqueue(largestVectorValue+1);
			alreadyOutput.add(output.peek);
		}
		if (input == 'D') {
			for (int i = 0; i < alreadyOutput.size; i++) {
				int currentVectorValue = alreadyOutput[i];
				if (currentVectorValue < smallestVectorValue) {
					currentVectorValue = smallestVectorValue;
				}
			}
			output.enqueue(smallestVectorValue-1);
			alreadyOutput.add(output.peek);
		}
	}
	for (int i = 0; i < output.size; i++) {
		int outputNumbers = output.dequeue(i);
		output += integerToString(outputNumbers);
	}
	return output;
}
			
					