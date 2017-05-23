string decode(string seq) {
	string output = "";
	Stack<int> helperStack;
	for(int i = 1,; i <= seq.length()+1; i++){
		if(i > seq.length() || seq[i-1] == 'I'){
			output += integerToString(i);
			while(!helperStack.isEmpty()){
				output += integerToString(helperStack.pop());
			}
		}else{
			helperStack.push(i);
		}
	}
	return output;
}
