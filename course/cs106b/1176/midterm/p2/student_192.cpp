string decode(string seq) {
	Stack<int> unorderedNums;
	Queue<int> orderedNums;
	int digits = seq.length() + 1;
	for (int i = digits; i > 0; i--) {
		unorderedNums.push(i);
	}
	for (int i = 0; i < digits - 1; i++) {
		int first = unorderedNums.pop();
		int second = unorderedNums.pop();
		if ((seq[i] == 'I' && second > first) || (seq[i] == 'D' 					&& first > second)) {
			orderedNums.enqueue(first);
			unorderedNums.push(second);
		} else if ((seq[i] == 'D' && second > first) || (seq[i] 					== 'I' && first > second)) {
			orderedNums.enqueue(second);
			unorderedNums.push(first);
		}
	}
	int last = unorderedNums.pop();
	orderedNums.enqueue(last);
	string orderedNumsStr = orderedNums.toString();
	//concatenate string? to get rid of brackets and commas but Idk the function help I ran out of time
	return orderedNumsStr;
}
			
				