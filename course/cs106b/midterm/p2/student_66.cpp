string decode(string seq) {
Stack <int> output;
if (seq[0] == 'I'){
	output.push(1);
} else {
	output.push(2);
}
	for (int i = 1; i < seq.length(); i++) {
		if (seq[i] == 'I'){
			int current = output.pop();
			int new = current + 1;
			output.push(current);
			output.push(new);
		} else {
			int current = output.pop();
			int new = current - 1;
			output.push(current);
			output.push(new);
		}
	}
	int size = output.size();
	int final = 0;
	for (int i = 0; i < size; i++) {
		final += output.pop()*10^i;
	}
	string result = integertoString(final);
	return result;
}