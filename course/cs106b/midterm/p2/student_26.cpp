string decode(string seq) {
	Queue<int> sequence; //1,2,3,4,5,6,7,8,9
	Stack<int> output;
	Stack<int> temp;
	
	
	for(int i=0; i<seq.length(); i++) {
		sequence.enqueue(i);
	}
	
	output.push(sequence.dequeue(0);//1
				//2,3,4,5,6,7,8,9
	
	for(int n=0; n<sequence.length(); n++){
		int num = sequence.dequeue();
		if(seq[n]=='I') {
			output.push(num);
		} else{
			while(num != output.peek()+1){
				temp.push(output.pop());
			}
			temp.push(output.pop());//this is so ugly i know
			output.push(num);//i'm so sorry i am out of time
			while(!temp.isEmpty()){
				output.push(temp.pop());
			}
		}
	}				
	temp.clear();
	for(int n : output) {
		temp.push(output.pop());
	}			
	string answer;
	for(int n=0; n<temp.size(); n++){
		answer += integerToString(temp.pop());
	}
	return answer;
	
				
				
}