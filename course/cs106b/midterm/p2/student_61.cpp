string decode(string seq) {
	Queue<int> coded, temp;
	string output = "";
	for (int i = 1; i <= seq.length()+1; i++){
		coded.enqueue(i);
		if(seq[i] == 'I'){
			coded.enqueue(i++);
		} else if(seq[i] == 'D'){
			temp.enqueue(coded.dequeue());
			coded.enqueue(temp.peek()++);
			coded.enqueue(temp.dequeue);
		}
	}
	int x = coded.size();
	for(int i = 0; i < x; i++){
		output += integerToString(coded.dequeue);
	}
	return output;
}
			
		