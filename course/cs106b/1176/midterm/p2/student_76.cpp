string decode(string seq) {
	String seq = toUpperCase(seq);
	string result = "";
	Stack<int> record; //pop and push
	if(seq.size() == 1 & seq[0] == "I"){
		result += "12";
	}
	else if(seq.size() == 1 & seq[0] == "D"){
		result += "21";
	}
	for(int i = 0; i < seq.length(); i++){
		if(seq[i] == "I"){
			while(!record.isEmpty(){
				int numPrevious = record.peek();
				int newNum = newPrevious++;
				string nextNumber = integerToString(newNum);
				result+=nextNumber; 
				record.pop();
				record.push(newNum);
			}else{
				result += "12"
				record.push(2); 
			}
		}
		if(seq[i] == "D"){
			if(record.peek() == 1){
				throw("Cannot utilize number 0");
			}
			while(!record.isEmpty){
				int numPrevious = record.peek();
				int newNum = newPrevious--;
				string nextNumber = integerToString(newNum);
				result+=nextNumber; 
				record.pop();
				record.push(newNum);
			}else{
				result+= "21";
				record.push(1); 
	}
	return result;
}
 
		

				  