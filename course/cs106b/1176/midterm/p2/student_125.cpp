string decode(string seq) {
	
	Stack<int> numbers
	string output = "";
	
	//Add all of the requisite numbers to the queue
	for(int i = 1 ; i <= seq.length() + 1 ; i++) {
		numbers.push(i);
		
	}
	
	for(int i = 0; i < seq.length() ; i++) {
		if( seq[i] == "D" ){
			int num = numbers.pop(i);
			string strnum = integerToString(num);
			output.append(strnum);
		}
		if(seq[i] == "I") {
			int num = 
		
		}
		
	
			
		
	
	
	

	
	
	
	
	
	
	
		
		