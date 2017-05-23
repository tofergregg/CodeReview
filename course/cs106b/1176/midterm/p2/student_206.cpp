string decodeHelper(string seq, Vector<int> allPossibleNumbers, Queue<int> &output);
	if (output.size() == seq.size()+1) {
		string finalresult = "";
		while (!output.isEmpty()) {
			string result = "";
			result += output.dequeue();
		}
		if (stringToInteger(result) < stringToInteger(finalresult)) {
			finalresult = result;
		}
	}
	
	for (int i = 0; i < allPossibleNumbers.size(); i++) {
		int num = allPossibleNumbers[i];
		if (!usedNumbers.contains(i)) {
			output.enqueue(i);
			usedNumbers.add(i);
			decodeHelper(seq,output);
		}
	}
	return finalresult;
}



string decode(string seq) {
	string finalresult = "";
	Queue<int> output;
	Vector<int> allPossibleNumbers;
	Set<int> usedNumbers;
	decopeHelper(seq, allPossibleNumbers, output);
	return finalresult;
}


	
	
			   
						   
						   
			
			
		
		
		
