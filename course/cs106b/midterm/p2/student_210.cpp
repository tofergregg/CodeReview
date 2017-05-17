/* Utilizes two stacks: the first to keep track of the actual
 * sequence and the second to keep track of what numbers to add 
 * to the sequence with it is decreasing
 */

string decode(string seq) {
	int idx = 0; // index of current letter
	int currNum = 0; // sets first number to enter
	int temp = currNum; // initialize temp

	char currLetter = seq[idx]; // sets current letter
	char nextLetter = seq[idx + 1]; // looks @ the next letter

	Stack<int> stack1; // actual sequence
	Stack<int> stack2; // temp holder
	
	while (idx < seq.length() - 1) {
		
		if (currLetter == nextLetter || idx == 0) {
			if (currLetter == 'I') {
				currNum++;
				intSeq.push(currNum);
				idx++;
			}
			
			if (currLetter == 'D') {
				temp++;
				stack2.push(temp);
			}
		}
		
		if (currLetter != nextLetter) {
			if (nextLetter == 'I') {
				while (!stack2.isEmpty()) {
					stack1.push(stack2.pop());
				}
				currNum = temp;
				idx++;
			}
			if (nextLetter == 'D') {
				stack1.push(currNum);
				temp = stack1.peek();
				temp++;
				stack2.push(temp);
				idx++;
			}
		}
		
	}
	
	string final = "";
	for (int i : stack1) {
		string curr = integerToString(i);
		
		final.insert(0, curr);
	}
	
	return final;
	
}
