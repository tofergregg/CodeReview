string helper (string seq, string output, int j, int min, int max){
string decode(string seq) {
	string output = seq;
	int min = 1;
	int max = 9;
	helper(seq, output, 0, min, max)
			
	}
}	

string helper (string seq, string output, int j, int min, int max){
	for(int x = j; x<seq.length(); x++){
		for(int i = min; i<=max; i++){	//digits 1 - 9 to begin
			if(previous == null && seq[j] == 'I'){
				output+="1"
			}
			//previous and next should only be declared if their indeces are in range
			int previous = stringToInteger(string seq[x-1]);
			int next = stringToInteger(string seq[x+1]);
			if(seq[j] == 'I' && min!=max){
				//internal base case for if the next index is out of range (this means we are done and need to add one more number)
				if(seq[x+1]==null && seq[x]=='I'){
					output+=(previous+1);
					return output;
				}
				//internal base case for if the next index is out of range (this means we are done and need to add one more number)
				if(seq[x+1]==null && seq[x]=='D'){
					output+=(previous-1);
					return output;
				}
				//skipping those two base cases, we reach the recurisve case. if we are increasing, the min is the previous number plus 1
			   helper(seq, output, j+1, previous+1, max);
				
			}
				//if min==max, this means we have recursively found a number that appropriately fits in that index of the output corresponding with the correct index of the sequence given
				if(min == max){
					output += integerToString(int min);
				}
				
				
			
			if(seq[j] == 'D'&& min!= max){
				//if we are decreasing, the max is the previous number minus 1
				helper(seq, output, j+1, 0, previous-1);
			}
				if(min == max){
					output+=integerToString(int min);
				}
		}
			
	}
	return output;
}
