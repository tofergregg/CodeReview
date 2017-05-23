string decode(string seq) {
	// where we store the number result
	string result;
	int min;

	// create a stack of to count the numbers of pairs of ID
	Stack<int> countPair;
	for(int i = 0; i < seq.length(); i++){
		if(seq[i] == 'I'){
		  countPair.push('I');
	}else{
	      if(!countPair.isEmpty){
		  countPair.pop();
		  }else{
		 // if the countpair is empty add one to the min
			min ++;
		  }
			
		}
		
	}
	
	for (int i = 0; i < seq.length(); i++){
		int start = 1 + min;
		result = integerToString(start);
		if(seq[i] == 'I'){
			int new = stringToInteger(result[result.size() - 1]) + 1;
			string newStr = inTegerToString(new);
			result.add(newStr);
		}else{
			int new = stringToInteger(result[result.size() - 1]) - 1;
		    string newStr = inTegerToString(new);
			result.add(newStr);
		}
	}
    
}