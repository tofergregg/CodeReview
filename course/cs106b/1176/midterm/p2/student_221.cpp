

string decode(string seq) {
	
	Stack<int> Number;
	Stack<int> D;
	string output;
	for(int i=seq.length;i>=1;i--){
		Number.push(i);
	}
	for(int i=0;i<seq.length;i++){
		if(seq[i]=="I"){
			while(!D.isEmpty()){
				ouput.append(integerToString(D.pop()));
			}
			ouput.append(integerToString(Number.pop()));
		} else {
			D.push(Number.pop);
		}
	
	}
	
	
	
	return output;
		
}

