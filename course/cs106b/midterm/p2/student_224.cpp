string decode(string seq) {
int iCount =0;
int dCount=0;
Queue <int> q;
	for (int i=0; i<seq.length(),i++){
		if (seq[i]=='I'){
			q.enqeue(1);
			iCount++;
		}
		if(seq[i]=='D'){
			q.enqueue(-1);
			dCount++;
			
		}
	}
	
	string res="";
	int prevVal;
	int lastVal;
	
	if (seq[0]=='D'){
		prevVal=dCount+1;
		
	}
	res+=integerToString(prevVal);
	for(int i=0; i<seq.length(); i++){
		int inc =q.dequeue();
		prevVal+=inc;
		res+=integerToString(prevVal);
	}
	cout<<endl;
}