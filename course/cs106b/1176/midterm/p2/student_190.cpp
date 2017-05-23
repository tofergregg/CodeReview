string decode(string seq) {
	//returns minimum number without repeating any digits
	//only 1 - 9
	//minimum input: 1 character, maximum length: 8
	Vector<int> numbers;
	Vector<int> finalList;
	Stack<int> stacky;
	int next;
	for (i = 1; i < 10; i++) {
		numbers.add(i); //creates: 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9
	}
	for (i = 0; i < seq.length(); i++) {
		if (seq.at(i) == 'I') {
			if (i == 0) {
				next = numbers[0]; //1
				numbers.remove(0);
				finalList.add(0); //final {1}
				next = numbers[0]; //2
				numbers.remove(0);
				stacky.push(next); //stack {2}
			} else if (seq.at(i-1) == 'I') {
				next = numbers[0];
				numbers.remove(0);
				finalList.add(stacky.pop());
				next = numbers[0];
				numbers.remove(0);
				stacky.push(next);
			} else if (seq.at(i-1) == 'D') {
				while (!stacky.isEmpty()) {
					stacky.push();
				}
				next = numbers[0];
				numbers.remove(0);
				finalList.add(stacky.push());
			}
		} else {
			if (i == 0) {
			} else {
				next = numbers[0];
				numbers.remove(0);
				stacky.push(next);
			}
		}
	}
	while (!stacky.isEmpty()) {
		stacky.push();
	}
	
	return finalList;
}
				
				
				
