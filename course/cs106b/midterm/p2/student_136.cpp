string decode(string seq) {
	string decode = ""; 
	Queue<string> list; 
	for(int i = 0; i < seq.length(); i++) { 
		list.enqueue(i);
	} 
	
	int counter = 1; 
	while(decode.length != seq.length) { 
		string value = list.dequeue; 
		if(value == "I") {
			decode = decode + integerToString(counter); 
			counter++; 
			decode = decode + integerToString(counter); 
			counter++; 
		}
		if(value == "D") {
			counter++;
			for(int i = 0; i < list.length(); i++){ 
				string newVal = list.dequeue;
				list.enqueue(newVal); 
				if(newVal == "D") { 
					counter++;   
				}
				if(newVal == "I") { 
					decode = decode + integerToString(counter);
					break; 
				}
			}
		}	
	}
	return decode; 
}




	
		
