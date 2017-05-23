string decode(string seq) {
	string code;
	int starter;
	int dCount;
	int iCount;
	Queue<int> numbers;
	Vector<int> numberTracker;
	if(seq.at(0) == 'D'){
		starter = seq.length() + 1;
	}
	if(seq.at(0) == 'I'){
		starter = 1;
	}
	numberTracker.add(starter);
	numbers.enqueue(starter);
	for(int i = 1; i < seq.length(); i++){
		dCount = 0;
		iCount = 0;
		if(seq.at(i) == 'D'){
			if(seq.at(i + 1) == 'D'){
				starter--;
			} else{
				while(seq.at(i + 1) == 'I'){
					i++;
					iCount++;
				}
				i -= iCount;
				starter -= (iCount + 1);
			}
		}
		if(seq.at(i) == 'I'){
			if(seq.at(i + 1) == 'I'){
				starter++;
			} else{
				while(seq.at(i + 1) == 'D'){
					i++;
					dCount++;
				}
				i -= dCount;
				starter += (dCount + 1);
			}
		}
		numbers.enqueue(starter);
	}
	for(int i = 0; i < numbers.size(); i++){
		code += dequeue();
	}
	return code;
}
	
	
			
		
		
