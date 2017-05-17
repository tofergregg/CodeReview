string decode(string seq) {
	
	Queue<string> outputQueue
	
	for (int i = 0; i <= seq.length; i++){
		for (int num = 1; num <=9; num++) {
			if (i == 0) {
				string output = "";
				output += integerToString(num);
				outputQueue.enqueue(output);
			} else {
				string output = outputQueue.dequeue();
				if ((int)output.length() == i) {
					if (seq[i - 1] == 'D') {
						if (num < output[i - 1]) {
							output += integerToString(num);
							outputQueue.enqueue(output);
						}
					} else { // 'I'
						if (num > output[i - 1]) {
						output += integerToString(num);
						outputQueue.enqueue(output);
						}
					}
				} else {
					outputQueue.enqueue(output);
				}
			}
		}
	}
	
	while (true) {
		string output = output.dequeue();
		if (noRepeatDigits(output)) {
			break;	
		}
	}
	return output;
}


bool noRepeatDigits(string) {
	//	
}
	
	
	