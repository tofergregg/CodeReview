string decode(string seq) {
	string result = "";
	int curr = 1;
	Stack<int> decrStack;
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] == 'I') {
			result += integerToString(curr);
			while(!decrStack.isEmpty()) {
				result += integerToString(decrStack.pop());
			}
			curr++;
		} else if (seq[i] == 'D') {
			decrStack.push(curr);
			curr++;
		}
	}
	result += integerToString(curr);
	while(!decrStack.isEmpty()) {
		result += integerToString(decrStack.pop());
	}
        // added by Chris
        return result;
}
	
				
				
