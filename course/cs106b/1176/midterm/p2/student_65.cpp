string decode(string seq) {
	Queue<string> q;
	string output = "";
	for (int i = 0; i <= seq.length(); i++) {
		if (seq[0] == 'I') {
		output += "1"
		} else {
		output += "9"
		}
	}
	q.enqueue(output);
	while (!q.isEmpty()) {
		output = q.dequeue();
		if (allCorrect(output) return output;
		//permute through every number according to I or D
		for (int i = 1; i <= seq.length(); i++) {
				if (seq[i-1] == 'I') {
					//cant go higher than 9
					if (output[i] != 9) {
					for (int num = output[i]; num <= 9; num++) {
						output[i] = num;
						string newOutput = output;
						q.enqueue(newOutput);
					}
					}
				} else if (seq[i-1] == 'D') {
					//cant go lower than 1
					if (output[i] != 1) {
					for (int num = output[i]; num > 0; num--) {
						output[i] = num;
						string newOutput = output;
						q.enqueue(output);
					}
					}
				}
		}
	}
	return "";
}
	
			boolean allCorrect(sting s) {
				
			}