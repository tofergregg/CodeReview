string decode(string seq) {
	Queue<string> = numbersLeft;
	for(int num = 1; num<seq.length()+1; num++){
		numberLeft.enqueue(integerToString(num));
	}
	
	string decoded="";
	string current = numbersLeft.dequeue();
	Stack<string> decreasing;
	for(int i = 0; i<seq.length();seq++){
		if (seq[i]=='I'){
			decoded.append(current);
			current = numbersLeft.dequeue();
			while(!decreasing.isEmpty()){
				decoded.append(decreasing.pop());
			}
		}else{
			decreasing.push(current);
			current=numbersLeft.dequeue();
		}
	}
	decoded.append(current);
	while(!decresing.isEmpty()){
		decoded.append(decreasing.pop());
	}
	return decoded;					
}