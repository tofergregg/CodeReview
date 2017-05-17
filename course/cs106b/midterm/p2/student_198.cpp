string decode(string seq) {
	//sorry that its not decomposed...
	Queue<int> number; //holds number of the type of characters are consequtively(spl?)
	number.enqueue(1);
	Queue<char> type; //holds the type in order appeared and adds them in order
	type.enqueue(seq[0]);
	int highest = 0;
	int lowest = seq.length()-1;
	
	Queue<int> result; //result queue of numbers
	if(seq[0] == 'I'){
		result.enqueue(1);
		used.add(1);
	} else{
		result.enqueue(seq.length()+1);
		used.add(seq.length() +1);
	}
	
	for(int i = 1; i < length; i++){ //adds all the correct values to number and type
		if(type.peek() == seq[i]){
			int temp = number.dequeue;
			number.enqueue(temp + 1);
		} else{
			number.enqueue(1);
			type.engueue(seq[i]);
		}
	}
	
	while(!number.isEmpty()){ //converts the number in a row to 
		int n = number.dequeue();
		char ch = type.dequeue();
		if(ch == 'I'){
			for(int i = 0; i < n; i++){
				int start = result.peek();
				if(start < highest){
					result.enqueue(highest+1);
				} else{
					result.enqueue(start+1);
				}
				highest++;
			}
		} else{
			int start = result.peek();
			for(int i = start + number; i > start; i--){
				result.enqueue(i+1);
				if(i+1 > highest){
					highest = i+1;
				}
			}
		}
	}
/*this function works really well if you assume that the first number is the lowest, i
* tried to implement the other way as well but ran out of time
*/
	
	string resultStr;
	while(!result.isEmpty()){
		int val = result.dequeue();
		string individual = integerToString(val);
		resultStr.apend(individual);
	}
	return resultStr;
}
