string decode(string seq) {
	string output;
	for (int i = 0; i < seq.length+1; i++){
		Queue<int> increasing;
		if(seq[i] == "I") {
			increasing.enque[i];
			if(seq[i+1] == "D"){
			   while (!increasing.isEmpty()){
				   int value = increasing.deque();
				   string svalue = integerToString(value);
				   output.append(value);
			   }
			}
		}
		Stack <int> decreasing;
		if(seq[i] == "D") {
			decreasing.push[i];
			if(seq[i+1] == "I"){
				while (decreasing.isEmpty()) {
					int value = decreasing.pop();
					string svalue = integertoString(value);
					output.append(value);
				}
			}
		}
	}
			
		