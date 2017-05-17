string decode(string seq) {
int seqSize = seq.size();
string minNum;
	
if (seqSize == 1) {
	if (seq[0] == "I") {
		minNum = "12";
	}
	if (seq[0] == "D") {
		minNum = "21";
	}
}
	
if (seqSize > 1) {
	Queue<char> seqQ;
	for (int i = 0; i < seq.size; i++) {
		seqQ.enqueue(seq[i]);
	}
	for (int i = 0; i < seqQ.size(); i++) {
		char letter = seqQ.dequeue;
		for (int j = 0; j < seqQ.size(); j++) {
			char currentLetterOnTop = seqQ.peek();
			

}
	
	

	
// if the first letter is I, add a one to the string