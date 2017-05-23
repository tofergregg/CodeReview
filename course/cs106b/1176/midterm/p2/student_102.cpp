string decode(string seq) {
	Stack dec;
	Queue inc;
	Vector<int> indicator;
	string ans="";
	for (int i=1; i<=8; i++){
		if (seq[i-1]=='I'){
			if (inc.size()==0){
				inc.enqueue(1);
				indicator[0]=0;
			}
			inc.enuque(i+1);
			indicator[i]=0;
		}
		if (seq[i-1]=='D'){
			if (dec.size()==0){
				dec.push(1);
				indicator[0]=1;
			}
			dec.push(i+1);
			indicator[i]=1;
		}
	}
	for (int i=0; i<==8; i++){
		if (indicator[i]=0){
			ans+=inc.dequeue();
		}
	    if (indicator[i]=1){
			ans+=dec.pop();
		}
	}
	return ans;
}
	
			
		
