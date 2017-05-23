string decode(string seq) {
	Queue<int> numD;
	Queue<int> numI;
	int counterI = 0;
	int counterD = 0;
	for(char ch: seq){
		if((seq == 'D') && (counterI == 0)){
			counterD++;	
			numI.enqueue(counterI);
			counterI = 0;
		} else if((seq == 'I') && (counterD == 0)){
			counterI++;	
			numD.enqueue(counterD);
			counterD = 0;
		}
	}
		
	Stack<string> output;
	string output = '';
	Char character = seq[0];
	int currValue = 0;
	while(!(numD.isEmpty()) && !(numI.isEmpty())){
		if(character == 'I'){
			int numberOfI = numI.dequeue();
			
			for (int i = 0; i < numberOfI; ++i){
				//output.push(currValue + i);
				output += intergerToString(currvalue + i)
			}
			currValue += numberOfI;
			character = 'D';
		} else if(character == 'D'){
			int numberOfD = numD.dequeue();
			currvalue += numberOfD + 1;
			
			for (int j = 0; j < numberOfD; ++j){
				//output.push(currValue - j );
				output += intergerToString(currvalue - j)
			}
			character = 'I';
			currValue--;
		}
		
	}
	return output;	
}