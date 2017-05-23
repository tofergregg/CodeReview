string decode(string seq) {
	Queue<int> increase;
	Stack<int> decrease;
	//put digits in queue for increasing and stack for decreasing
	for (int i = 1; i <= 9; i++) {
		increase.enqueue(i);
	}
	
	string answer = "";
	
	//find number of I and D
	int numI = 0;
	int numD = 0;
	for(int i = 0; i < seq.size(); i++) {
		if(seq[i] = 'I') numI++;
		else numD++;		
	}
	
	//adds first value 
	int n;
	if(seq[0] = 'I') {
		n = increase.dequeue();
		for(int i = 0; i < numD - 1; i++) {
			decrease.push(increase.dequeue());
		}
	} else {
		for(int i = 0; i < numD + 1; i++) {
			//makes sure min value is used 
			decrease.push(increase.dequeue());
		}
		n = decrease.pop();
	}
	string num = integerToString(n);
	answer += num;
	
	//adds rest of numbers to answer
	for (int i = 0; i < seq.size(); i++) {
		if(seq[i] = 'I') {
			if (numD > 0) decrease.push(increase.dequeue());
			n = increase.dequeue();
			numD--;
		} else {
			n = decrease.pop();
		}
		string num = integerToString(n);
		answer += num;
	}
	
	return answer;
}

//note to self to make sure it works
//if its IDIDII
//you want 1325467
//queue is 56789
//stack is 
//output is 132





















