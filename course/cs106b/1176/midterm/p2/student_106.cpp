string decode(string seq) {
	Queue<char> increments;
	for(int i=0; i < seq.length(); i++){
		increments.enqueue(seq[i]):
	}
	
	Queue<int> numLeft;
	for(int a = 1; a < seq.length()+2; a++){
		numLeft.enqueue(a);
	}
	Queue<int> solutionQ;
	while(!increments.isEmpty()){
		char step = increments.dequeue();
		if(step == 'I'){
			solutionQ.enqueue(numLeft.dequeue());
		} else{
			Stack<int> temp;
			temp.push(numLeft.dequeue());
			while(step == 'D'){
				if(!increments.isEmpty(){
					step = increments.dequeue();
				} else{
					step = 'I';
				}
				temp.push(numLeft.dequeue());
			}
			while(!stack.isEmpty()){
				solutionQ.enqueue(temp.pop());
			}
		}
	}
	while(!numLeft.isEmpty()){
		solutionQ.enqueue(numLeft.dequeue());
	}
	string solution;
	while(!solutionQ.isEmpty()){
		
		solution += integerToString(solutionQ.dequeue());
	}
	return solution;
}
