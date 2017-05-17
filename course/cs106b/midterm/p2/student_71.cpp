string decode(string seq) {
Queue<int> increasing;
Stack<int> decreasing;
Set<int> terminator;
string fianlString = " ";
for(int i = 0; i < seq.length() + 1; i++) {
	increasing.enqueue(i + 1);
	terminator.add(i + 1);
}
for(int i = seq.length()+ 1; i > 0; i--) {
	decreasing.push(i + 1);	
}

for(int i = 0; i < seq.length(); i ++) {
	if(i == seq.length()-1 && seq[i] == 'I') {
		finalString += integerToString(increasing.dequeue());
		finalString += integerToString(increasing.dequeue());
	}
	if(i == seq.length()-1 && seq[i] == 'D') {
		finalString += integerToString(decreasing.pop());
		finalString += integerToString(decreasing.pop());
	}
	if(seq[i] == 'I' && terminator.contains(increasing.peek())) {
		terminator.remove(increasing.peek());
		finalString += integerToString(increasing.dequeue());
	} else {
		while(!terminator.contains(increasing.peek()) {
			increasing.deque();
		}
		terminator.remove(increasing.peek());
		finalString += integerToString(increasing.deque());
			  }
	if(seq[i] == 'D' && terminator.contains(decreasing.peek())) {
		terminator.remove(decreasing.peek());
		finalString += integerToString(decreasing.pop());
	} else {
		while(!terminator.contains(decreasing.peek()) {
			decreasing.pop();	
		}
		terminator.remove(decreasing.peek());
		finalString += integerToString(decreasing.pop());
		}
}
return finalString;
			  }