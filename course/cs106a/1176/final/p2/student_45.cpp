string decode(string seq) {
	
// length of the sequence determines which numbers need to be used		
// total the number of increases
	
	Stack<int> s1;
	Stack<int> s2;
	
	for (int i; i<seq.length(); i++){
		if (seq[i] == 'I'){			
			s1.push(i);
		} else {
			s2.push(i);	
		}
	}
		
	int startNum;
	
	if (s1.size >= s2.size) startNum = 1;
	else startNum = seq.length() - s1.size();
	
	
	
// total the number of decreases
	
	Queue<int> q1;
	for (int i=1; i<=seq.length(); i++){	
		q1.enqueue(i);		
	} // not useful
	

	string output;		
	
	for (int i; i<seq.length(); i++){
		if (seq[i] == 'I'){
		
			output[i+1] = output[i] + 1;
			//output[i+1] = s1.pop;
			
		} else{
		
			output[i+1] = output[i] - 1;
			//output[i+1] = s2.pop;
			   
		}

	
// if we get to zero, increment all the numbers by 1
	
	}
	
	string outputString = integerToString(output);	
	
}


