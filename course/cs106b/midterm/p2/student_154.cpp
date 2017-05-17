string decode(string seq) {

	Stack<int> numbers;
	int largest = 0;
	if(seq[0] == 'I'){
		numbers.push(1);
		largest = 1;
	}
	
	else if(seq[0] == 'D'){
		int numD = 0;
		char c = 'D';
		
		numbers.push(numD+1);
		largest = numD+1;
	}
	
	for(int i = 0; i < seq.length(); i++){
		if(seq[i] == 'I' && seq[i+1] == 'I'){
			int temp = numbers.peek();
			temp++;
			largest = temp;
			numbers.push(temp);
		}
		if(seq[i] == 'D'){
			int temp = numbers.peek();
			temp--;
			numbers.push(temp);
		}
		if(seq[i] == 'I' && seq[i] == 'D'){
			char c = 'D';
			int numD = 0;
			int index = i;
			while(char c == 'D'){
				numD++;
				if(seq[index] == 'I'){
					break;
				}
				index++;
			}
			int temp = numD + 1 + largest;
			numbers.push(temp);
		}
	}
	
	string reverse;
	while(!numbers.isEmpty()){
		string next = integerToString(numbers.pop());
		reverse += next;
	}
	
	for(int i = reverse.length()-1; i > 0; i--){
		cout << reverse[i] <<;
	}
}