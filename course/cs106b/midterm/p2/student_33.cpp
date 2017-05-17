string decode(string seq) {
	stack<int> output;
	
	//Will hold the values of the last two ints pushed onto stack.
	int var1;
	int var2;
	
	//Every stack begins with 1
	output.push(1);
	
	//Iterates through seq to create the stack
	for (int i = 0; i < seq.size(); i++) {
		//Adds ints to stack in consecutive order with no repeats
		output.push(i+2);
		
		//Gets the relationship from string seq
		char rel = seq[i];
		
		//Var1 will be the last int on the stack i.e. 2
		//Var is the next int on the stack i.e. 1
		var1 = output.pop();
		var2 = output.pop();
		
		//If increasing, will put ints back in original order. i.e. 1, 2
		if (rel == I) {
			output.push(var2);
			output.push(var1);
		//If decreasing, will put ints back onto stack in reverse order. i.e. 2, 1
		} else if (rel == D) {
			output.push(var1);
			output.push(var2);
		}
	}
	
	//Outputs contents of stack as string!
	cout << output.toString(); << endl;
}