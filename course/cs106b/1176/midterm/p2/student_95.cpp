string decode(string seq) {
	Queue<char> sequence;
	
	//this loop puts the sequence in a queue
	//that we will use latter on
	for(int i =0; i < seg.size(); i++){
		sequence.enqueue(seq[i]);
	}
	//this outer loop will go through all the numbers in ascending order
	//until 1B and check if they fulfill the criteria
	//it will return the smaller number that does
	for(int i=1; i<1000000000; i++){
		string num = integerToString(i);
		bool checker = True;
		//this loop checks if the numer i, fits the sequence criteria
		for(int n=0; n<seg.size(); n++){
			char letter = sequence.dequeue();
			if( letter == 'I'){
				if(stringToInteger(num[n])>stringToInteger(num[n+1])){
					checker = checker *1;
				} else {
					checker = 0;
				}
			}else{
				if(stringToInteger(num[n])<stringToInteger(num[n+1])){
					checker = checker *1;
				} else {
					checker = False;
				}
			}
			sequence.enqueue(letter);
		}
		
		//This section checks if the digits are repeated or 0
		HashSet<char> numerals;
		for( int n =0; n<num.size();n++){
			if(!numeral.contains(num[n]) && num[n] != '0'){
				numerals.add(num[n]);
			} else {
				checker = False;
		}
		
		//this returns if we found a number that works with
		//the different conditions of the problem
		if(checker){
			return i;
		}		
	}
	return "No number matches the sequence";
}
