string decode(string seq) {
	Stack<int> nums;
	string toRet = "";
	
	for(int i = 1; i <= seq.length + 1; i++) {
		nums.push(i);	
	}
	
	
	for(int i = 0; i < seq.length; i++) {
		if(seq[i] == 'I') {
			Stack<int> s;
			int temp;
			
			for(int j = 0; j < i + 1; j++) {
				s.add(nums.pop());	
			}
			
			temp = nums.pop();
			
			for(int j = 0: j < s.size(); j++) {
				nums.push(s.push());
			}
			
			nums.push(temp);
		} 
	}
	
	
	while(!nums.isEmpty()) {
		int last = nums.pop()	
		
		toRet += integerToString(last);
	}
	
	
	return toRet;
}
	