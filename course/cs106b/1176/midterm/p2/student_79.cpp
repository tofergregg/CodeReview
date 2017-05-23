string decode(string seq) {
	string final;
	Stack <int> sequence;
	sequence.push(1);
	Set<int> options;
	Queue<int> endNum;
	for(int j =0; j<10; j++){ 
		options.add(j);
	}
	int temp; 
	
	for (int i = 0; i < seq.length()-1; i++) {
		char order = seq[i];
		temp = sequence.peek();
	
		if (order == "I") {
			temp++;
			if(options.contains(temp)) { 
				sequence.push(temp);
				options.remove(temp);
			}
			else {
				while(!options.contains(temp)) { 
					temp++;
				}
				sequence.push(temp);
				options.remove(temp);
			}
		}
		
		else {
			temp--;
			if(options.contains(temp)) { 
				sequence.push(temp);
				options.remove(temp);
			}
			else { 
				while(!options.contains(temp)) {
					temp--; 
					if(temp <=0) {
						// pop stack into a queue until first decreasing number, and then add to all decreasing numbers. puts original numbers back into options, pushes new numbers into stack.
						int add = stack.pop();
						while(!options.contains(add){
							add++;
						}
					}
					sequence.push(temp);
				}
		}
	}
	while(!sequence.isEmpty()){
		int num = sequence.pop;
		endNum.enqueue(num); 
	}
	string decodeFinal;
	while(!endNum.isEmpty()){
		decodeFinal+= integerToString(endNum.dequeue());
	}
	return decodeFinal;
}
