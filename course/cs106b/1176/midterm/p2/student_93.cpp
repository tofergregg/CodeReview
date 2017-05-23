string decode(string seq) {
	string min = "";
	Stack<int> numberSequence;
	Set<int> usedNumbers;
	for(int n=1; n<=seq.length()+1;n++){
		usedNumbers.add(n);
	
	for(int i=0; i<=seq.length();i++){
		int lowestPossible =0;
		if(seq[i]=="I"){
	
			
	/*Pseudocode:
	Begins with an empty stack.
	Then cycles through each element of the seq string to see if an I or a D.
	we peek in the stack to see if we are allowed to increase or decrease and by what amount.(by looking at the number that has preceeded this one)
	Then we look to see what numbets have been used and pick the lowest one that fits
	with the instructions.
	
		
