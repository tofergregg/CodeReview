string decode(string seq) {
	string answer = "";
	Vector<int> vals;
	for(int i= 0; i< 10; i++){
		vals.add(i);
	}
	Queue<int> nums;
	if(seq.length()>8) return answer;
	
	for(int i= 0; i< seq.length(); i++){
		if(seq[i] == 'I'){
			nums.enqueue(vals[0]);
			vals.remove[0];
		}else{
			int l = vals.size() - 1;
			nums.enqueue(vals[l];
			nums.remove[l];
		}
	}
	if(seq[length()-1] == 'I'){
			nums.enqueue(vals[0]);
			vals.remove[0];
		}else{
			int l = vals.size() - 1;
			nums.enqueue(vals[l];
			vals.remove[l];
		}
						 
	int l = nums.size();
	for(int i= 0; i< l;; i++){
		cout<<nums.dequeue();
	}
}