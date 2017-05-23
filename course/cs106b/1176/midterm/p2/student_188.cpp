string decode(string seq) {
	Stack<int> stack;
	Queue<int> queue; 
	Set<int> numsUsed;
	int value = 1;
	string final;
	for (int i = 0; i < seq.length(); i++) {
		string str = seq.substr(i, 2);
		if (str == "II") {
			while(true) {
				if (!numsUsed.contains(value)) {
					queue.enqueue(value);
					numsUsed.add(value);
					value++;
					break;
				} else {
					value--;
			    }
			}
		} else if (str == "DD") {
			while(true) {
				if (!numsUsed.contains(value)) {
					stack.push(value);
					numsUsed.add(value);
					value--;
					break;
				} else {
					value++;
				}
			}
		} else if (str == "ID") {
			queue.enqueue(value);
			numsUsed.add(value);
			value++;
			for (int i = 0; i < queue.size(); i++) {
				int num = queue.dequeue();
				string str = integerToString(num);
				final.append(str);
			}
			queue.clear();
		} else if (str == "DI") {
			stack.push(value);
			numsUsed.add(value);
			value--;
			for(int i = 0; i < stack.size(); i++) {
				int num = stack.pop();
				string str = integerToString(num);
				final.append(str);
			stack.clear();
		}
	}
	return final;
			
			
