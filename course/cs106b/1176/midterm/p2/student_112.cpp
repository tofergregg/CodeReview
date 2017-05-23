string decode(string seq) {
	Set<int> prevNums;
	Queue<int> numSeq;
	int n =1;
	numSeq.enqueue(n);
	prevNums.add(n);
	for(int i = 0; i < seq.length(); i++){
		if(seq[i] == 'I'){
			n++;
			while(prevNums.contains(n)){
				n++;
			}
			numSeq.enqueue(n);
		}
		else{
			while(numSeq.peek() != n){
				int a = numSeq.dequeue();
				numSeq.enqueue(a);
			}
			n++;
			numSeq.enqueue(n);
			int b = numSeq.dequeue();
			numSeq.enqueue(b);
		}
	}
	while(!numSeq.isEmpty()){
		cout<<numSeq.dequeue();
	}
}
