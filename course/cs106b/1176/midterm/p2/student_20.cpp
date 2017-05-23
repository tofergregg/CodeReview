// My algorithm:
// We have the sequence of digits from 1 to 9 in order (represented by the for loop). Every time there // is a 'D', add the next unused digit to the Stack. Every time there is an I, add the next unused 
// digit to the string, and then pop off any digits from the Stack (which will now be in reverse 
// order). At the end, because the 'I' and 'D' really are relationships, not single numbers, act as 
// though there is an 'I': add the next unused digit, and pop off any final remaining digits from the // Stack.

string decode(string seq) {
	Stack<int> decNums;
	string minNum = "";
	seq += "I";
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == 'I') {
			string digit = i+1;
			minNum += digit;			
			while (!decNums.isEmpty()) {
				string digit = integertoString(decNums.pop());
				minNum += digit;
			}	
		} else if (seq[i] == 'D') {
			decNums.push(i+1);
		}	
	}	
	return minNum;
}