string decode(string seq) {
	Queue<int> increases;
	increaes.enqueue(1);
	Stack<int> decreases;
	
	String result = "";
	for(int i = 1; i < seq.length+1; i++){
		if(seq[i-1] == "I"){
			increases.enqueue(i+1);
		}else{
			
			decreases.push(increases.dequeue());
		}
	}
	for(int i = 0; i < increases.size();i++){
		result += integerToString(increases.dequeue());
	}
	
	
	return result;
}