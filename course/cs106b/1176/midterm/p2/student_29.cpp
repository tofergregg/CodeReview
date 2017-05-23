string decode(string seq) {
	Queue<int> smallestNum;
	Stack<int> digits;
	for (int i = 9; i > 0; i--) {
		digits.push(i);
	}
	int i = 0;
	while (seq.length > i - 1){
		if (seq.at(i)== 'I') {
			while (seq.at(i)== 'I' && seq.length > i) {
				smallestNum.enqueue(digits.pop());
				i += 1;
			}
		} else if (seq.at(i)== 'D') {
			Stack<int> dec;
			while (seq.at(i)== 'D' && seq.length > i) {
				dec.push(digits.pop());
				i += 1;
			}
			dec.push(digits.pop());
			i += 1;
			while (!dec.isEmpty()){
				smallestNum.enqueue(dec.pop());
			}
		}
	}
	if (seq.at(i) == "I" ) smallestNum.enqueue(digits.pop());
	
	string number = "";
	while (!smallestNum.isEmpty()){
		number += integerToString(smallestNum.dequeue());
	}
	return number;
}