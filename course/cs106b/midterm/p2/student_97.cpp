string decode(string seq) {
	int length = seq.length() + 1;
	int maxNum
	stack <int> output;
						
//find max amount of decreases, so know max integer we can to use in the final output so as to make output the min # possible
	maxNum = seq.length();
	output.push(sequence.length());
	for (int i = 1; i > seq.length(); i++){ 
		if (seq[seq.length() - 1*i] == "I"){
			output.push(seq.length()+ 1 - 1*i);
		}else{
			output.push(seq.length() - 1 - 1*i);
		}
		string outputStr = integerToString(i);
	}
	return outputStr;
		 
						
						
						
						
//uhhh my try at this being recursive?
// base case
if (seq.length = 0){
	return outputStr;
}else{
	for (int i = seq.length() - 1; i > 0; i--){
		stack<int> output;
		if (seq[i] == "I"){
			output.push(i);
		}else{
			output.push(maxNum
// ... this is a seperate attempt: 	
						for (int i = 0; i < seq.length -1; i++){
		if (seq[i] == "D"){
			maxNum ++;
		}
	}	
	