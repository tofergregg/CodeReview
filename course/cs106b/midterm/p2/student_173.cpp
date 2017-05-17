string decode(string seq) {
	string output = "";
	Stack<int> a;
	Queue<int> b;
	Vector <int> numbers;
	for(int i=0; i< seq.size()+1; i++){
		numbers.add(i);
	}
	for(int i=1; i<=seq.size()+1; i++){
		b.enqueue(i);
	}
	printFirstNum(seq, output, numbers);
	for(int i=1; i<seq.size(); i++){
		char current = seq[i];
		if(current == 'I'){
			string nextinc = integerToString(b.dequeue());
			output += nextinc;
		}else if(current == 'D')
			while(!b.isEmpty){
				int num = b.dequeue();
				a.push(num);
			}
			string nextdec = integerToString(a.pop());
			output += nextdec;
		}
	} 
	return output;
}
		
void printFirstNum(string seq, string &output, Vector<int>&numbers){
	if(seq[0]=='I'){
		output += integerToString(1);
	} else if(seq[0] == 'D'){
		output += integerToString(numbers[numbers.size()- //number of I's in sequence]);
	}
}
	
	
