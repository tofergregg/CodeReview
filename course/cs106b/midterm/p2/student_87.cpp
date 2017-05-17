string decode(string seq) {
	Stack<string> s; // store the I's
	Queue<string> q; // store the D's
	// if the string starts with I, then the first output is 1
	if (seq[0] == 'I'){
		cout<< 1 ;
	} else {
		cout<< seq.size() + 1;
	}
	int i = 0; // index
	int counter = 1; // counter of the numbers
	while ( i < seq.length() ){
		if (seq[i] == "I"){
			q.enqueue(counter); //counting the number of strings
		} else {
			s.push(counter);
		}
		counter++;
		i++;
	}
	int j = 0;
	while ( j <seq.length()){
		if (seq[j] == "I"){
			q.dequeue();
		}else {
			s.pop();
		}
		j++;
	}
}
	
		
			
		
		
	
	
