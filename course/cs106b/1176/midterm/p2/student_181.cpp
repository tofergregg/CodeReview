string decode(string seq) {
	string digits; 
	Set<int> usedIntegers; 
	Stack <int> increasingValues = initializeStack(seq); 
	Queue <int> decreasingValues = initializeQueue(seq); 
		if (minOrMax(seq[0]) {
			digits += integerToString(increasingValues.pop()); 
		} else {
			digits += integerToString(decreasingValues.dequeue()); 
		} //Initialize string with the first value in the sequence so it will be n-1 in length 
	for (int i =0; i<seq.size(); i++) {

		if (minOrMax(seq[i] && !usedIntegers.contains(seq[i]))) {
			digits+= integerToString(increasingValues.pop()); 
		} else if  (!minOrMax(seq[i] && !usedIntegers.contains(seq[i])) {
			digits+= integerToString(decreasingValues.dequeue()); 
		} 
		return digits; 
	} 
	
Stack<int> initializeStack(string seq) {
	Stack<int> increasingValues; 
	for (int i = seq.size(); i>=0; i--) {
		increasingValues.push(i); 
	} 
	return increasingValues; 
} 
		
Queue<int> initializeQueue(string seq) {
	Queue<int> decreasingValues; 
	for (int i =0; i<=seq.size() +1; i++) {//Ensures that we have n-1 values 
		decreasingValues.enqueue(i); 
	} 
} 
		
void minOrMax(char c) {
	if (c == I) {
		return true; 
	} else {
		return false; 
	} 
} 


		
		
		
		
		
		
		//Pseudocode: We can use a stack and create min/max values to loop 
	//through the string and determine the appropriate sequence of numbers. //Helper bool method to determine if max sequence or is min sequence. Declare a set with used values so no value is repeated. Must concatenate final value @ end. Stack to hold increasing values queue to hold decreasing values (remove first one added (lowest values) and remove first one from stack, highest values. No nest for loops, so it runs in O(n) time 