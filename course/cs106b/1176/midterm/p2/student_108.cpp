string decode(string seq) {
	
	
	int stringSize = seq.size();
	int newStart = 1;
	int newStart = findMostNegatives(seq);
	newStart = 1 + newStart;
	string result = newStart;
	Queue<string> queueSeq;
	for(int i = 0; i < stringSize; i++){
		queueSeq.enqueue(seq[i])
	}
	Set<int> numsLeft;
	for(int i = 0; i < 10; i++){
		numsLeft.add(i);
	}
			
	
string recursion(Queue<string> queueSeq,Set<int>numsLeft,string code,int previousNum){
	if(numsLeft.isEmpty()){
		return stringCode;
	}
	else{
		if(queueSeq.dequeue()=="D"){
			if(previousNum == 1){
				if(numsLeft(
			
		string num = integerToString(numsLef
	
	
	
	
	
	
int findNewStart(string seq){
	int stringSize = seq.size();
	int mostDCounter = 0;
	int iCounter = 0;
	for(int i = 0; i < stringSize; i++){
		if(seq[i] == "D"){
			mostDCounter++;
		}else if(seq[i] == "I"){
			iCounter++;
		}
	}
	return mostDCounter-iCounter;
}
