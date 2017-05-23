string decode(string seq) {
//write this recursively? LOL FML
//start off w/ lowest possible number
//for each number, try each next number that follows the command of I/D
//if there are no more letters in sequence, return the string w/ the shortest value
//base case
	Stack <int> fwdNumbers;
	Stack <int? bkwdNumbers;
	for (int i = 1; i <= 9; i++) {
		fwdNumbers.push(i); //gives stack of order 1-9, large numbers popped first
	}
	for (int j = 9; j >= 1; j--) {
		bkwdNumbers.push(j); //gives stack of order 9-1, small numbers popped first
	}
	string output = "";
	if (seq[0] == "I") {
		output = 1;
	}
	if (seq[0] == "D") {
		output = seq.length(); 
	}
	return decodeHelper(seq, fwdNumbers, bkwdNumbers, output);
}

string decodeHelper(string seq, Stack<int> fwdNumbers, Stack<int> 		 
		bkwdNumbers, string output){
	if (seq == "") {
		return output;
	}
	if (output.length() == seq.length()+1){
		retun output;
	}
	int bestOutput = stringToInteger(currentOutput);
	for (int i = 1; i < seq.length(); i++) {
		if (seq[i] == "I"){
			while(bkwdNumbers.peek() <= output[length-1) { //makes sure that the numbers will be increasing;
				bkwdNumbers.pop();
			}
			output += integerToString(bkwdNumbers.pop());
			decodeHelper(string seq, Stack<int> fwdNumbers, Stack<int> 			 		bkwdNumbers, string output);
		}
		if (seq[i] == "D"){
			while(fwdNumbers.peek() <= output[length-1) { //makes sure that the numbers will be decreasing 
				fwdNumbers.pop();
			}
			output += integetToString(fwdNumbers.pop());
			decodeHelper(string seq, Stack<int> fwdNumbers, Stack<int> 			 	bkwdNumbers, string output);
		}
		if (integerToString(output) < bestOutput) {
			bestOutput = output;
		}
	}
	return bestOutput;
}
	
