string decode(string seq) {
	Queue<int> queueSeq;
	string number;
	Queue<int> queueNum;
	int num;
	int start;
	for (int i=0; i<seq.length(); i++){
		queueSeq.enqueue(seq[i]);
	}
	num = queueSeq.size();
	//int random = randomInt(1, num+1);
	if (queueSeq.peek() == "I"){
			start = 1;
	}else{
		//begin with queue size + 1 
		start = num+1;
		
	}
	queueNum.enqueue(start);
	while(!queueSeq.isEmpty()){
		number = queueSeq.dequeue();
		if (number == "I"){
				queue.add(addIncNumber(num,queueNum );
		}else if (number == "D"){
				queue.add(addDecNumber(num, queueNum);
		}		  
	}
	return queueNum.toString();
}
				  
				  
				  
bool queueContainsNum (Queue<int> &queue, int num){
	for (int i=0; i<vec.size; i++){
		if (vec[i]==num){
			return true;
			break;
		}else{
			return false;
		}
	}
	
int addIncNumber(int &num, Queue<int> &queueNum){
	random = randomInt (1, num+1);
	if (!queueContainsNum(queueNum,random)&& random > queueNum.peek()){
		return(random);
	}else{
	return addIncNumber(num, queueNum);
	}
}
	
	int addDecNumber(int &num, Queue<int> &queueNum){
	random = randomInt (1, num+1);
	if (!queueContainsNum(queueNum,random)&& random < queueNum.peek()){
		return(random);
	}else{
	return addDecNumber(num, queueNum);
	}
}

		
			