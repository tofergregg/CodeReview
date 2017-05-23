string decode(string seq) {
	Vec<int> unused;
	String output = "";
	for(int i = 0; i < seq.size(); i++) {
		used.add(i+1);
	}
	Queue<char> upOrDown;
	Stack<char> sequentialD;
	while(!seq.isEmpty()) {
		upOrDown.enqueue(seq[0]);
	}
	if(upOrDown.peek() == 'I') {
		output = output + unused[0];
	} else {
		output = output + unused[unused.size()-1];
	}
	while(!upOrDown.isEmpty()) {
		if(upOrDown.peek() == 'I') {
			upOrDown.dequeue();
			output = output + unused[0];
		} else {
			upOrDown.dequeue();
			output = output + unused[unused.size()-1]
		}
	}
}
		
