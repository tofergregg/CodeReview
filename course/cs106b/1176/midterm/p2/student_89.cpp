string decode(string seq) {
	Queue<int> numList;
	string answer;
	int num = 1;
	int counter = 0;
	int j = 0;
	int temp = 0;
		
		for (int i = 0; i < seq.size(); i++) {
			//Checks if the current char is 'I' or 'D'.
			if (seq[i] == 'I') {
				numList.enqueue(num);
				num++;
			} else {
				//Cycles through to see how many 'D's are in a row.
				//Utilizes this data to enqueue the correct value.
				j = i;
				while (seq[j] == 'D') {
					counter++;
					j++;
				}
				temp = counter;
				while (counter > 0) {
					numList.enqueue(num + counter);
					counter--;
				}
				counter = temp;
			}
		}	
	
		//Captures final number
		if (seq[seq.size() - 1] == 'D') {
			numList.enqueue(num + (counter - 1));
		} else {
			numList.enqueue(num);
		}
		
		//Converts queue answers into string format
		for (int value : numList) {
			answer = answer + integerToString(value);
		}
	return answer; 
}