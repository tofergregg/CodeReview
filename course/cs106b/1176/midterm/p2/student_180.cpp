string decode(string seq) {
	int n = seq.size();
	
	Queue<char> code;
	Queue<int> nums;
	String numbers = "";
	
	//Populate code Queue
	for(int i = 0; i < n; i++){
		code.enqueue(seq[i]);
	}
	
	//Populate numbers Queue
	for(int i = 1; i <= n + 1; i++){
		nums.enqueue(i);
	}
	
	//Cycling through
	int lastNum;
	char firstChar = code.peek();
	if(firstChar == 'I'){
		lastNum = 0;
	} else {
		lastNum = n;
	}
	
	
	while(!code.isEmpty()){
		if(code.peek() == 'I' && nums.peek() > lastNum){
			numbers += integerToString(nums.dequeue());
			code.dequeue();
			
		} else if (code.peek() == 'D' && nums.peek() == lastNum - 1){
			numbers += integerToString(nums.dequeue());
			code.dequeue();
		}
		
		nums.enqueue(nums.dequeue());
	}
	
	numbers += integerToString(nums.dequeue());
	return numbers;
}