string decode(string seq) {
	Stack<int> output;
	Set<int> numLeft;
	fillSet(numLeft);
	int currNum;
	int increase;
	int decrease;
	for(int i = 0; i < seq.size(); i ++) {
		if(seq[i] == "I") {
			increase ++;
		} else {
			decrease ++;
		}
	}
	if(s[0] == "I") {
		currNum = 1;
		increase --;
		numLeft.remove(currNum);
	} else {
		currNum = Math.abs(decrease - increase) + 1;
		decrease --;
		numLeft.remove(currNum);
	}
	for(int i = 0; i < seq.size(); i++) {
		if(seq[i] == "I") {
			currNum ++;
			increase --;
			while(!set.contain(currNum)){
			output.push(currNum);
				currNum ++;
			}
		} else {
			if(output.size() >1) {
				stack.pop();
				stack.push(math.abs(decrease-increase);
						   }
						   //add set value that decreases by 1.

	
void fillSet(Set<int> &numLeft) {
	for(int i = 1; i < 10;i++){
		set.add(i);
	}