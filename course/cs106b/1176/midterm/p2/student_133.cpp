string decode(string seq) {
	seq = toLowerCase(seq);
	Queue<int> return_queue;
	int length = seq.length();
	if (seq.length() == 1) {
		if (seq.at(0) == "i") {
			return integerToString(12);
		} else {
			return integerToString(21);
		}
	} else {
		int current = 1;
		while (current < length) {
			int counter_increase = 0;
			int counter_decrease = 0;
			for (int i = current-1; i < length; i++) {
				char temp = seq.at(i);
				if (temp == 'i') {
					counter_increase++;
					current++;
				} else {
					break;
				}
			}
			for (int i = current; i < counter_increase+current + 1; i++){
			return_queue.enqueue(i);
		}
		for (int i = current-1; i < length; i++) {
				char temp = seq.at(i);
				if (temp == 'd') {
					counter_decrease++;
					current++;
				} else {
					break;
				}
			}
			for (int i = counter_decrease+current; i > current + 1; i--){
			return_queue.enqueue(i);
			}
		}
	}
	string return_string;
	for (int i = 0; i < return_queue.size(); i++ {
		int a = return_queue.dequeue();
		return_string = return_string + integerToString(a);
	}
	return return_string;
}
	

	
	
	
	