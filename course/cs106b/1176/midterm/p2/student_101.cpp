string decode(string seq) {
	
	seq = seq.toUpperCase();
	for (int i = 0; i < seq.length(); i++){ //Test for valid input
		if (seq[i] != "I" | seq[i] != "D"){
			throw("String Exception Error: invalid seq input.You can only input I or D");
		}
	}
	
	Stack<int> hold;
	string output;
	Queue<int> nums;
	for (int i = 1; i < 10; i++) {
		nums.enqueue(i);
	}
	while (seq.length() > 1) {
		if (seq[0] == "I"){
			if (hold.isEmpty()){
				output += integerToString(nums.dequeue());
			} else {
				output += hold.pop();
		}
		if (seq[0] == "D" ){
		hold.push = nums.dequeue();
		seq = seq.substr(1);
		
	if (seq	
	if (seq.length() == 1){
		if (seq[0] == "I" ){
			output += integerToString(nums.dequeue());
		} else {
			
	
	