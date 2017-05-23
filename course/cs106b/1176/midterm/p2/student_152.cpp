string decode(string seq) {
		
	Vector<int> used;
	int totalD = 0;
	Stack<int> output;

	
	for (int i = 0; i < seq.size(); i++) {
		if(seq[i] == 'D') {
			totalD++;
		}
	}
	
	int starter = 1 + totalD;
	used.add(starter);
	output.push(starter);
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == 'D') {
			while (used.contains(starter)) {
				starter -= 1;
			}
		} else {
			while (used.contains(starter)) {
				starter += 1;
			}
		}
		used.add(starter);
		output.push(starter);
	}
	
	while (!used.contains(1)) {
		for (int i = 0; i = seq.size(); i++) {
			int num = output.pop();
			output.push(num - 1);
		}
	}
	
	return output.toString();
}
				
		
			
	
			
		