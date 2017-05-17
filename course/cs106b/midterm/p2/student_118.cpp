/* Pseudocode:
* Stores all the digits into a Q, with 9 being the first stored value
* and 1 being the last stored value. Depending on the I or D value, 
* a value will be removed from the queue to add onto the string. No 
* repeats will occur due to values being pulled from the queue.
*/

string decode(string seq) {
	// Assumes inputs are either "I" or "D"
	string minNumber = ""; 
	counter = 0;
	Queue<int> digitsQ; // For decreasing
	for (int i = 9; i <= 1; i++){
		digitsQ[i] = i;
	}
	while (minNumber.length() < 10) {
		if (seq[minNumber.length()] == "I") {
			for (int i = 0; i < 9 - minNumber.length - 1; i++) {
				digitsQ.dequeue();
				digitsQ.enqueue();
			minNumber += integerToString(digitsQ.dequeue());
		} else if (seq[minNumber.length()] == "D") {
			while (seq[minNumber.length - 1] == "D") {
				counter++;
			}
			for (int j = counter; j >= 0; j--) {
				digits.dequeue.();
				digits.enqueue();
			}
			for (int k = counter; k >= 0; k--) {
				minNumber += integerToString(digits.dequeue());
			}	
			counter = 0;
		}	
	}	
	return minNumber;
}	

/*	
	int counter = 0;
	// Gets the first few numbers.
	if (seq[0] = "I") {
		minNumber += (string)(1);
	} else if (seq[0] == "D") {
		int i = 0;
		while (seq[i] == "D") {
			counter++
		}
		for (int j = counter; j >= 0; j--) {
			minNumber += string(counter);
			counter--;
		}	
	} else {
		throw("Error: Enter a valide string");
		string line = getLine("Enter string");
		deco
	*/	
