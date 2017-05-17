//TODO should have worked backwards on a stack so I don't have to reverse...
//ALSO i know none of this code works..

/*
I don't have time to code this I have one minute left.
but the right way is to go backwards through the sequence string
if you try to push a number out of bounds,
walk backwards through both the sequence and the stack until 
you find the same letter, add one and push all the way back
use a queue to store the popped ones. 




*/
string decode(string seq) {
	Stack<int> numStack;
	//o of larger than n if no backtracking... will use recursion...
	//IF you subtract and it goes down to 0, you have to go through and 
	//add one to every number! 
	if (seq[0] == 'I'){
		numStack.push(1);
	} else {
		numStack.push(seq.length-1); //not super useful...
	}
	for (int i = 0; i < seq.length(); i++){
		if (seq[i] == "I"){
			int nextVal = numStack.peek()+1;
			if (nextVal > 9) {
				numStack.pop(9);
				backFix(seq, i, numStack);
			} else {
				numStack.push(nextVal);
			}
			if (
		} else {
			int nextVal = numStack.peek()-1;
			if (nextVal < 9) {
				numStack.pop(1);
				backFix(seq, i, numStack);
			} else {
				numStack.push(nextVal);
			}
		}	
		
	}
	string finalString;
	while (!numStack.isEmpty()){
		//TODO reverse this
		finalString += integerToString(numStack.pop());
	}
	
	
}

				//I know this code doesn't work I'm freaking out
void backFix(string &seq, int seqIndex, Stack<int>& numStack){
	while (!numStack.isEmpty){
		int lastValue = numStack.pop()
		int previousValue = numStack.pop()//this will throw error when too small!!
		if (lastValue == previousValue){
			if (seq[seqIndex] == 'I'){
				numStack.push(previousValue-1);
				backFix(seq, seqIndex, numStack);
			} else {
				numStack.push(previousValue+1);
				backFix(seq, seqIndex, numStack);
			}
		}
	}
		
	

				
				//look at the step, and the previous number
				//at one/subtract one.
				//if out out bounds, get the previous number
				//and get previous letter
				
				
	
	///BACKWARDS:
/*	for (int i = seq.length()-1; i <= 0; i--){
		if (seq[i] == 'I"){
			//need to go down one, 
			numStack.push(numStack.peek()-1)
			//but I don't know if that's within bounds still!!
			//UUGH.....
			//need to keep popping until you can do the transistion. 
			//maybe just until another I? ***
			//if there's another I, you can just incrememnt
		}
		
		
	}
	*/
	