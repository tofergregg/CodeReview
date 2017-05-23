string decode(string seq) {
	//if decreasing, check how many more decreaseing are next and 
	//add the lowest one that will still allow decreasing numbers
	//(find the new index to use by counting number of decreasing)
	//if increasing, add the next available lowest number
	
	
	//create a vector with all the numbers to use
	//in order from 1 --> highest number
	Vector<int> numbersLeft;
	for(int i = 1; i <= seq.length() + 1; i++) {
		numbersLeft += i;
	}
	//create a queue to keep track of the decoded number
	Queue<int> decodedNumber;
	
	//decode the string
	for(int i = 0; i < seq.length(); i++) {
		if(seq[i] == "I") {
			decodedNumber.enqueue(numbersLeft[0]);
			numbersLeft.remove(0);
		} else {
			int decreasingInARow = 0;
			int index = i;
			while(seq[index] == "D") {
				decreasingInARow += 1;
				index += 1;
			}
			int newNumIndex = decreasingInARow;
			decodedNumber.enqueue(numbersLeft[newNumIndex]);
			numbersLeft.remove(newNumIndex);
		}
	}
	//add the one number that's left
	decodedNumber.enqueue(0);
	
	//output the decoded number
	for(int i = 0; i < decodedNumber.size(); i++) {
		cout << decodedNumber.dequeue();
	}