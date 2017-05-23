string decode(string seq) {
	int i = 0, c = 0;
	string ans = "1";
	while (i < seq.size()) {
		while (seq[i++] == 'I') {
			   c++;
			   ans += integerToString(c);
		}
		if (i >= seq.size()) break;
		
		// here must be some D left
		int numToReverse = 1; 
		while (seq[i++] == 'D') {
			 c++;
			 ans += integerToString(c);
			 numToReverse++;
		}
		reverse(ans, numToReverse);
	}
	return ans;
}

void reverse(string & ans,int numToReverse){
	Stack<char> s;
	int startPos = ans.size() - numToReverse;
	string sub = ans.substr(startPos);
	for (char c : sub){
		s.psuh(s);
	}
	while (!s.isEmpty()) ans += s.pop();
	
}



/* 

string helper (string p) {
	Stack<int>
	if (char  add
	if (char D
}

		
		string s;
	for (auto c : seq) {
		int c = 0;
		while (c == 'I') {
			
		} else {
			
		}
	}
	
	// parse IIDD to 2I2D*/