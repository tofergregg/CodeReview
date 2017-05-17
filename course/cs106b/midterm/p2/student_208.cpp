string decode(string seq) {
	Queue<int> out;
	Queue<int> hold;
	for(int j = 1; j < seq.length()+1; j++) {
		out.enqueue(j);
	}
	for(int i = 0; i < seq.length(); i++) {
		char curr = seq[i];
		if (curr == 'D') {
			for(int k = 0; k < seq.length()-i; k++) {
				hold.enqueue(out.dequeue());
			}
			