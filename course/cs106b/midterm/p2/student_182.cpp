void helper(string output, int maxNo, int lastNo, Queue<bool>& sequence, const HashSet<int>& existingNos, Queue<string>& outputs) {
	if (sequence.isEmpty()) {
		outputs.enqueue(output);
	} else {
		int startNo, endNo;
		if (sequence.dequeue()) {	// If increasing
			startNo = lastNo + 1;
			endNo = maxNo;
		} else {					// If decreasing
			startNo = 1;
			endNo = lastNo - 1;
		}
		for (int i = startNo; i <= endNo; i++){
			if (!existingNos.contains(i)) {
				output += integerToString(i);
				existingNos.add(i);
				helper(output, maxNo, i, sequence, existingNos, outputs);
			}
		}				   
	}
}

string decode(string seq) {
	Queue<bool> sequence;
	Queue<int> outputs;
	HashSet<int> existingNos;
	
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] == 'I') {
			sequence.enqueue(true);		// True if increasing
		} else if (seq[i] == 'D') {
			sequence.enqueue(false);	// False if deceasing
		} else throw ("Invalid sequence!");
	}
	
	for (int i = 1; i <= seq.length() + 1; i++) {
		helper(integerToString(i), seq.length() + 1, i, sequence, existingNos, outputs);
	}
	
	if (!outputs.isEmpty()) {
		return outputs.dequeue();		// We need only the first output - which is the minimum number.
	} else {
		return "";
	}
	
}