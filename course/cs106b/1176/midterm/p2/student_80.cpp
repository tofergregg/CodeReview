string decode(string seq) {
	Queue<String> queueProceedingNum;
	int length = seq.length();
	for(int i=0; i<length; i++){
		queueProceedingNum.enqueue(seq.charAt(i);
	}
	int firstVal;
	if(queueProceedingNum.peek()=="D"){
		firstVal=length+1;
	}
	else{
		firstVal=1
	}
								   
	Vector<int> alreadyUsed;
	alreadyUsed.add(firstVal);
	int currentVal=firstVal;
	while(!queueProceedingNum.isEmpty()){
		string next = queueProceedingNum.dequeue();
		if(next=="D"){
			int nextNum = currentVal--;
			while(alreadyUsed.contains(nextNum){
				nextNum--;
			}
			alreadyUsed.add(nextNum);
			currentVal=nextNum;
		}
		else{
			int nextNum = currentVal++;
			while(alreadyUsed.contains(nextNum){
				nextNum++;
			}
			alreadyUsed.add(nextNum);
			currentVal=nextNum;
		}
	}
	while(!inUpperBounds){
		for(int eachNumber:alreadyUsed){
			alreadyUsed[eachNumber] = eachNumber--;
		}
	}
	while(!inLowerBounds){
		for(int eachNumber:alreadyUsed){
			alreadyUsed[eachNumber] = eachNumber++;
		}
	}
	string result;
	for(int eachValue : alreadyUsed){
		string addition = integerToString(eachValue);
		result.append(addition);
	}			  
				  
	return result;
				  
}
				  
bool inUpperBounds(Vector<int> numbers){
	for(eachNumber:numbers)	{
		if(eachNumber>9) return false;
	}
	return true;
}
	
bool inLowerBounds(Vector<int> numbers){
	for(eachNumber:numbers)	{
		if(eachNumber<1) return false;
	}
	return true;
}