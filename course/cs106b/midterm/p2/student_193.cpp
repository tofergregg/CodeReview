// Helper
int getNumDs(string seq);


// Figured this one out (I think) with too little time to spare...it's the last 3 minutes as I write this. I want to create a queue "A" from numDs + 1 to seq.length() + 1, and then a queue "B" from 1 to  seq.length() - numDs() + 1. Then I want to iterate through seq. If I hit "I" I will dequeue from queue B and add that value to my string. Otherwise (i.e. I hit "D" I will dequeue from queue A and that that to my string.

// Doing what I can in my last seconds...
string decode(string seq) {
	string output;
	Queue<int> queueA;
	Queue<int> queueB;
	string directive;
	// Gets the number of "D"s in the sequence
	int numDs = getNumDs(seq);
	for (int i = 0; i < numDs; i++) {
		queueA.enqueue(i);
	}
	for (int i = 1; i < seq.length() - numDs + 1; i++) {
		queueB.enqueue(i);
	}
	// The rest of what I said above :/

// Returns the number of "D"s in the sequence
int getNumDs(seq) {
	int numDs;
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] == "D") {
			numDs++;
		}
	}
	return numDs;
}
			


