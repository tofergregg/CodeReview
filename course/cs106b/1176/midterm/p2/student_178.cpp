string decode(string seq) {

	Queue<char> letterFront;
	Stack<char> letterEnd;
	
	int lastNum;
	char lastChar;
	
	for(int i = 0; i < seq.length(); i++){
		letter.enqueue(seq.at(i));	
	}
	
	int size = letter.size();
	
	for(int i = 1; i <= size; i++){
		if(letter.isEmpty()){
			if(lastChar == "I") cout << lastNum++;
			else cout << lastNum--;
		}
		if(letter.peek() == 'I') && i == 1){
			lastChar = letter.dequeue();
			lastNum = 1;
			cout << 1;
		} else if (letter.peek() == "I" && lastChar == "I"){
			letter.dequeue();
			lastNum++;
			cout << lastNum;
		} else if (letter.peek() == "D" && i == 1){
			lastChar = letter.dequeue();
			lastNum = letter.size() + 1;
			cout << lastNum;
		} else if (letter.peek() == "D"){
			letter.dequeue();
			lastNum--;
			cout << lastNum;
		} else if(letter.peek() == "I"){
			letter.dequeue();
			lastNum++;
			cout << lastNum;
		}		   
	}
}