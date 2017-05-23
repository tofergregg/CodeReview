string decode(string seq) {
	Queue<char> queue;
	Stack<char> stack;
	Set<int> numsUsed;
	int next = 1;
	for(int i = 0; i < seq.length(); i ++){
		queue.enqueue(seq[i]);
	}
	if(queue.peek() == 'I'){
		seq = integerToString(1);;
	} else{
		int num = 1;
		while(!queue.isEmpty){
			char ch = queue.dequeue();
			if(ch == 'D'){
				while(ch == queue.peek()){
					num++;
					queue.dequeue();
				}
				int counter = nums;
				for(int i = 0; i< counter; i++){
					if(i == 0){
						while(numsUsed.contains(seq[seq.length()-1]+nums){	
							nums++;	
						}
					}
							  seq+=integerToString(stringToInteger(seq[seq.length()-1])+ nums);
					
//In the code above I'm trying to make it so that for every D in a sequence, the next number added starts a number higher than the previous number while making sure I dont reuse numbers.	
							  
				 //I ran out of tie but for each I I was going to just start at the lowest number available
			} else{
				while(ch == queue.peek()){
					
// out of time :(
				}						  
	return seq;
}
							  					
				
				
			
		