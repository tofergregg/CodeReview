string decode(string seq) {
	string result = "";
	int k = seq.length();
	k += 1;    //size of the result
	Stack<int> temp;
	if(seq[0] == 'I'){
		temp.push(1);
		for(int i = 0; i < k - 1; i++){
			if(seq[i] == 'I'){
				while(!temp.isEmpty()){
					result.push_back(temp.pop());
				}
				temp.push(i + 2);
			}else{
				temp.push(i + 2);
			}
		}
		while(!temp.isEmpty()){
			result.push_back(temp.pop());
		}
		return result;
	}else{
		temp.push(k);
		for(int i = 0; i < k - 1; i++){
			if(seq[i] == 'D'){
				while(!temp.isEmpty()){
					result.push_back(temp.pop());
				}
				temp.push(k - 1 - i);
			}else{
				temp.push(k - 1 - i);
			}
		}
		while(!temp.isEmpty()){
			result.push_back(temp.pop());
		}
		return result;
	}
}
	
	
	
