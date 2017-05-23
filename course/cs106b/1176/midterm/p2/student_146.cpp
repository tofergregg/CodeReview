string decode(string seq) {
	char curr = seq[0];
	Queue<string> queue;
	for (int i = 0; i < seq.length(); i++) {
		if (seq[i] != curr) {
			queue.enqueue(seq.substr(0, i));
			curr = seq[i];
			seq.erase(0, i);
		}
	}
	//this for loop splits the string up into strings with only I's and D's.
	//for example, it would split IIDDII into {"II", "DD", "II"}
	queue.enqueue(seq); //enqueueing the final sequence/if seq was all I or all D
	string result = "";
	int currentInt = 1;
	while(!queue.isEmpty()) {
		string sequence = queue.dequeue();
		int p = queue.isEmpty() ? 0 : -1;
		//the int p works like this:
		//if there's an increasing sequence with a decreasing bit after it, the final
		//increasing integer is covered by the (larger) first integer in the decreasing
		//part. thus, one fewer integers need to be added to the increasing part. if the 
		//queue is empty, though, then sequence.length() + 1 integers still need to be 
		//added, hence the ternary operator. i will note that i don't use p for 
		//decreasing sequences because due to this algorithm's need to make the smallest
		//number that meets the increasing and decreasing criteria, sequences of 
		//decreasing numbers always go as low as they can go so that higher numbers can
		//be later in the number for an overall smaller magnitude. it's like the 
		//fencepost problem: we put fenceposts at the beginning of each fence, not at 
		//both the beginning and end. 
		if (sequence[0] == 'I') {
			for (int i = 0; i <= sequence.length() + p; i++) {
				result += integerToString(i + currentInt);
			}
			currentInt += sequence.length() + p + 1;
		} else {
			for (int i = sequence.length(); i >= 0; i--) {
				result += integerToString(i + currentInt);
			}
			currentInt += sequence.length() + 1;
		}
	}
	return result;
}
	