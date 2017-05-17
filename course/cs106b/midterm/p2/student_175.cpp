string decode(string seq) {
	//creates a stack for the sequence
	Stack <char> letters;
	for(int i = seq.length() -1; i <= 0; i--){
		char index = seq.at(i);
		letters.push(index);
	}
	
	Vector <bool> usedNums; 
	Vector <int> number; 
	int num = 1; 
	if(letters.peek() == 'I')
		number.add(num);
	}
	char next; 
while(!letters.isEmpty()){
	next = letters.peek();
	if(next == 'I'){
		letters.pop();
		num ++;
		while(usedNums[nums] ==true){
			num++;
		}
		if(letters.peek() != 'D'){
			number.add(num); 
		}else{
			int count;
		Vector<char> allD; 
		while(next == 'D'){
			char decrease = letters.pop();
			allD.add(decrease); 
			next = letters.peek(); 
		}
		count = allD.size();
		num += (count); 
		number.add(num); 
		usedNums[num] = true;
		for(int i = 0; i<count; i++){
			num--;
			number.add(num);
			usedNums[num] = true;
		}
			
		}
	if(next == 'D'){
		int count;
		Vector<char> allD; 
		while(next == 'D'){
			char decrease = letters.pop();
			allD.add(decrease); 
			next = letters.peek(); 
		}
		count = allD.size();
		num += (count +1); 
		number.add(num); 
		usedNums[num] = true;
		for(int i = 0; i<count; i++){
			num--;
			number.add(num);
			usedNums[num] = true;
		}
	}
}
string finalNumber;
for(int i = 0; i<number.size(); i++){
	finalNumber += number[i];
}
return finalNumber; 
		
	
		
		
