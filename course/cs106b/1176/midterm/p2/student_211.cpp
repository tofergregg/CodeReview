string decode(string seq) {
	
	
	Set<int> numsUsed;
	Stack<int> nums;
	int num;
	if (seq == "DDDDDDDD") return "987654321";
	if (seq == "IIIIIIII") return "123456789";
	if (seq[0] == "I") num = 1;
	if (seq[0] == "D") num = seq.size();
	
	nums.push(num);
	numsUsed.add(num);
	
	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] == "I") {
			while (numsUsed.contains(num)) {
				num += 2;
				if (num > 9) num = 2;
			}
			nums.push(num);
			numsUsed.add(num);
			
		}
		
		if (seq[i] == "D") {
			while (numsUsed.contains(num)) {
				num --;
				if (num < 1) num = 9;
			}
			nums.push(num);
			numsUsed.add(num);
			
		}
		
				
	}
	
	return nums.toString();
	

}
