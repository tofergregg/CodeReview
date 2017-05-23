string decode(string seq) {
	//highest number will always be seq.lenth()+1
	
	Queue<Stack<int>> queueOfLadders;
	HashSet<int> tracker;
	Ladder.push(1);
	tracker.add(1);
	queueOfLadders.enqueue(ladder);
	
	while(!queueOfLadder.empty()){
		Stack<int> ladder = queueOfLadder.dequeue();
		int topInt = tempLadder.peek();
		if (seq[0] == "I"){
			Stack<int> copyLadder = ladder;
			int nextInt += topInt;
			copyLadder.push(nextInt);
			queueOfLadder.enqueue(copyLadder);
			seq.erase(0,1);
		}
		if (seq[0] == "D"){
			Stack<int> copyLadder = ladder;
			int nextInt -= topInt;
			copyLadder.push(nextInt)
			queueOfLadder.enqueue(copyLadder);
			seq.erase(0,1);
		}
		if (seq[0] == ""){
			queueOfLadder.clear();
		}
	
	string answer;
	for (int i=copyLadder.size()-1; i=0; i--){
		 string num = integerToString(copyLadder.pop());
		 answer.insert(0,num);
	}
		
		cout << answer;
	}
		 
	
	//unable to finish. wanted to use the word ladder method to check all possible outputs.
	//also wanted to keep a set to avoid the same value.