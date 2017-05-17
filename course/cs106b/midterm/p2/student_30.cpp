string decode(string seq) {
	string toReturn;
	Stack<int> chosen; 
	Set<int> keepTrack;
	string lengthOfToReturn = seq.size()+1;
	chosen.push(1);
	for(int i=0; i<seq.size;i++) {
		if(seq[i]=='I') {
			int toAdd = chosen.peek()+1;
			while(keepTrack.contains(toAdd) && toAdd<10){
				toAdd++;
			}
			chosen.push(toAdd);
			keepTrack.add(toAdd);
		}else {
			int toAdd = chosen.peek()-1;
			while(keepTrack.contains(toAdd) && toAdd>0){
				toAdd--;
			}
			chosen.push(toAdd);
			keepTrack.add(toAdd);
		}
	}
	Stack<int> mirror;
	for(int j=0;j<lengthOfToReturn;j++) {
		mirror.push(chosen.pop());
	}
	for(int k=0;k<lengthOfToReturn;k++) {
		toReturn.append(integerToString(mirror.pop());
	}
	return toReturn;
}