
string decode(string seq) {
	string answer;
	Queue<int> Qnumbers;
	string reverse;
	
	int temp;
	
	//inserts all the valid numbers into queue and stack
	for (int j = 10; j > 0;j--) {
		Qnumbers.enqueue(j);
	}
	
	
	temp = Qnumbers.dequeue()
	answer += integerToString(temp);
	for (int i = 0; i < seq.size() - 1; i++) {
		//adds incrreassing order
		if (seq.at[i] = "I") {
			//adds the numbers that needed to be reversed
			answer += reverse;
			reverse = "";
			temp = Qnumbers.dequeue()
			answer += integerToString(temp);
		// adds descendiung numbers	
		} else {
			temp = Qnumbers.dequeue()
			reverse = integerToString(temp) + reverse;
		}
	} 
	answer += reverse;
	
	return answer;
}


		