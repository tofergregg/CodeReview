string decode(string seq) {
//minimum input is 1 character, max input is 8,
//so do not need to check validity of input string.
	//determines how many decreases we have.
	string result;
	int startD = 1;
	int startI = 1;
	for (int i = 0 ; i < seq.length(); i ++) {
		if (seq[i] == ('D') ) startD++; 
	}
	//
	Stack<int> nums;
	//this vector keeps track of the numbers I have used
	Vector<int> availableNums;
	for (int i = 0 ; i < seq.length(); i++) {
		availableNums.add(i);
	}
	string output = "":
	for (int i = 0; i < seq.length() + 1; i++) {
		char curr = seq[i];
		if (curr == 'I') {
			result += integerToString(startI); 
			//set startI equal to the next largest number
			//in availableNums. 
			availableNums.remove(integerToString(startI)); 
		} else {
			//I have not figured this out, but I would determine
			//a way to change startD for the next for loop. It has
			//to do with dequeueing the numbers off the stack.
			result += integerToString(startD);
		}
	}
	return result;
}
