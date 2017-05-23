string decode(string seq) {
	int length = seq.size();
	Queue<int> numbers();
	string answer;
	for(int i = 1; i =< length; i++){
		numbers.enqueue(i);
	}
	if(seq[0] == 'I'){ //start with 1
		answer = integerToString(numbers.dequeue());
	} else{ //start with highest number
		for (int i = 0; i < length; i++){
			numbers.enqueue(numbers.dequeue);
		}
		answer = integerToString(numbers.dequeue);
	}
	for(int i = 0; i < length; i++){
		if (i + 1 < length){
			if(seq[i] == 'I' && seq[i+1] == 'I'){
				answer += integerToString(numbers.dequeue);
			} else if(seq[i] == 'I' &&  seq[i+1] == 'D'){
				int n = i+1
				while(seq[n] == 'D' && n < length){
					numbers.enqueue(numbers.dequeue);
					n++;
				}
				answer += integerToString(numbers.dequeue);
				for(int c = 0; c < numbers.size - (n - i); c ++){
					numbers.enqueue(numbers.dequeue);
				}

			} else if (seq[i] == 'D'){
				if(numbers.peek() < stringToInteger(answer[answer.size()-1])){
					answer += integerToString(numbers.dequeue);

				} else{
					for (int i = 0; i < numbers.size() - 1; i++){
						numbers.enqueue(numbers.dequeue);
					}
					answer += integerToString(numbers.dequeue);
				}
			}
		} else{
			answer += integerToString(numbers.dequeue);	
		}
	}
	retrun answer;