string decode(string seq) {
	// count number of I and D
	string toReturn;
	int countI =0;
	int countD =0;
	for(int i =0; i<seq.length(); i++) {
		if (seq[i] == 'I') { 
			countI++;
		} else {
			countD++;
		}
    // seq is all Ds
		if (countI ==0) {
			countD++;
			while(countD >0)
				toReturn += integerToString(countD);
				countD--;
			}
		}
	// seq is all Is
		if (countD ==0) {
			int j =1;
			while(j <countI +2)
				toReturn += integerToString(j);
			}
		}


	// missing when seq is mixture of Is and Ds


	return toReturn;
}
    
    