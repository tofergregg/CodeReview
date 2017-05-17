string decode(string seq) {
	Stack<int> decreaseStack;
	string result;
	for (int i = 1; i <= seq.length(); ++i) {
		decreaseStack.push(i);
		if (seq[i-1] == 'I') {
			appendStack(result, decreaseStack);
		}
	}
	decreaseStack.push(i);
	appendStack(result, descreaseStack);
	return result;
}

/** utility function: appends (in place) the stack of ints (as strings) at the end of the string s. Stack is empty upon return. */
void appendStack(string& s, Stack<int>& stack) {
	while(!stack.isEmpty()) {
		s += integerToString(stack.pop());
	}
}
