//you need a queue of stacks 
//if you get an I you add next number to a new stack in queue
//if you get a D you stack on top of current stack
//at the end you dequeue stacks and pop each stacks

string decode(string seq) {
	Queue<stack<int>> output;
	int num = 1;
	Stack<int> s; //create initial stack with a 1
	s.push(num); 		
	for(int i = 0; i < seq.length(); i++){
		if (seq[i] == "I"){ //if an I 
			Stack<int> currentS; //create new stack
			num = num++;
			currentS.push(); 
		}
		while (seq[i+1] == "D") { //keep adding to curr stack
			num = num++;
			i = i++ //move over
			currentS.push(num); 	
		}
	}

	//make into string format
	string stringOutput = "";
	for (int h = 0; h < seq.length()+1; h++){
		//dequeu each stack
		Stack<int> tempStack = output.dequeue();
		int numInStack = tempStack.size(); 
		for (int j = 0; j < numInStack; j++){
			//pop every element out of given stack
			//and add to the output string
			stringOutput += tempStack.pop(); 
		}
	}
	
	return stringOutput; 
}
	
	
	

