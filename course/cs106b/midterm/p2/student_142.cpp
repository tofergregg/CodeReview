string decode(string seq) {
	Queue<string> queue;
	Set<int> numbers;
	string output;
	for (int i = 1; i < 10; i++) {
		numbers.add(i);
	}
	int decreases = 1;
	for (int i = 0; i < seq.size(); i++) {
		string letter = "" + seq[i];
		if (letter == "D") {
			decreases++;
		}
		queue.enqueue(letter);
	}
	if (queue.peek() == "I") {
		output += 1;
		numbers.remove(1);
	} else if (queue.peek() == "D") {
		output += decreases;
		numbers.remove(decreases);
	}
	while (!queue.isEmpty()) {
		string sequence = queue.dequeue();
		string before = "" + output[output.length()-1];
		if (sequence == "I") {
			for (int number: numbers) {
				if (number > stringToInteger(before)) {
					output += number;
					numbers.remove(number);
					break;
				}
			}
		} else if (sequence == "D") {
			for (int number: numbers) {
				if (number < stringToInteger(before)) {
					output += number;
					numbers.remove(number);
					break;
				}
			}
		}
	}
	return output;
}

		
		
		