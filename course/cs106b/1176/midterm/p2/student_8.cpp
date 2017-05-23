string decode(string seq) {
	// Calculate max number to be down relative to first. Keep enqueuing differnece to first
	int maxDown = 0;
	int currentDown = 0;
	Queue<int> deltaFromFirst;
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] = 'D') {
			currentDown += 1;
		} else {
			currentDown -= 1;
		}
		
		// Save delta vs. first in queue
		deltaFromFirst.enqueue(currentDown);
		
		// Update max down, if relevant
		if (currentDown > maxDown) {
			maxDown = currentDown;
		}
	}
	
	// Calculate number and add to queue
	str solution = "";
	int firstNumber = 1 + maxDown;
	solution += integerToString(firstNumber);
	while (!deltaFromFirst.isEmpty()){
		int delta = deltaFromFirst.dequeue();
		solution += integerToString(firstNumber - delta);
	}	

	return solution;
}
