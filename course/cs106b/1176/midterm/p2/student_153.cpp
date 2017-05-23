string decode(string seq) {
	Stack<int> s;
	int I;
	int D;
	//count how many I and D in teh seq
	for(int i=0;i<seq.size();i++){
		if(seq[i]=="I") I++;
		if(seq[i]=="D") D++;
	}
	
	int add = randomInteger(1,9-I);
	int minus = randomInteger(1,9-D);
	
	//deal with the fisrt two int
	if(seq[0]=="I"){
			s.push(1);
			s.push(1+add);

	}else if(seq[0]=="D"){
			int first = randomInteger(D,9);
			s.push(first);
			s.push(first-1);
	}
	
	//loop through the seq
	for(int i=1;i<seq.size();i++){
		if(seq[i]=="I"){
			s.push(s.peek()+ add);//larger than teh previous int
		}
		if(seq[i]=="D"){
			s.push(s.peek()- minus);//smaller than the previous int
		}
	}
	
	//print the stack in the right order
	string print="";
	for(int i=0;i<s.size();i++){
		print = integerTostring(s.pop())+print;
	}
	cout << print << endl;
}
	