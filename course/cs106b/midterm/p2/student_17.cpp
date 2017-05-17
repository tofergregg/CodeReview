string decode(string seq) {
	Queue<int> result;
	Set<int> availableInts;
	createAvailableInts(availableInts); //O(log(n))
	determineFirstChar(result, seq);
	for(int i = 1; i< seq.size(); i++){ //O(n)
		if(seq[i] == 'I'){
			result.enqueue(determineSmallestIncrease(availableInts, result.peek());
		} else {
			result.enqueue(determineSmallestIncrease(availableInts, result.peek());
		}
	}
	return queueToString(result);
}

string queueToString(Queue<int> &result){
	int size = result.size();
	for(int i = 0; i < size; i++){
		
}
						   
void createAvailableInts(Set<int> &availableInts){
	for(int i = 1; i<=9; i++){
		availableInts.add(i);
	}
}

int determineSmallestIncrease(Set<int> &availableInts, int initial){
	for(int i = 1; i <= 9-initial; i++){
		if(availableInts.contains(initial+i){
			return initial+i;
		}
	}
}
		   
int determineLargestDecrease(Set<int> &availableInts, int initial){		   
	for(int i = 9-initial; i >= 1; i--){
		if(availableInts.contains(initial-i){
			return initial-i;
		}
	}
}
void determineFirstChar(Queue<int> result, string seq){ // O(n)
	if(seq[0] == 'I'){
		result.enqueue(1);
		availableInts.remove(1);
	} else {
		int maxDescent = seq.find("I"); //finds Index of first I, O(n)
		if(maxDescent >= 1){
			result.enqueue(maxDescent + 1);
			availableInts.remove(maxDescent+1);
		}
	}
}