string decode(string seq) {
	Queue<char> seqQ;
	int count = 1;
	int total = 1;
	for(int i = 1; i <= seq.length(); i++) {
		seqQ.enqueue(seq[i]);
		total++;
	}
	while(total >= 1) {
		char currentTest = seqQ.dequeue();
		total--;
		if(currentTest == "D") {
			count++;
			if(seqQ.peek() == "D"){
				count++;
			}
		}else {
			cout << count++;
		}
		cout << count << count-1;
		total--;
	}
}			