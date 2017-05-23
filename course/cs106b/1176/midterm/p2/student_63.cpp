//if "D", next number in output is 1 less 

/

string decode(string seq) { 
	Stack<string> stack;
	Queue<string> queue;
	string answer = "";
	for (int i = 0; i<seq.size(); i++){
		stack.push(seq[i]);
	}
	for (int i = 0; i<seq.size(); i++){
		queue.enqeueue(seq[i]);
	}
	if (seq.size()==1){
		if (seq[0] == "I"){
			return "12"
		}
		else{
			return "21";
		}
	}
	int Dcounter = 0;
	string index = "";
	int currentnum;
	index = queue.dequeue();
	if (index == "I"){
		answer+="1";
		currentnum=1;
		while(!queue.isEmpty()){
			index = queue.dequeue();
			if (index == "I" && queue.peek() == "I"){
				currentnum++;
				answer += integerToString(currentnum);
			}
			else if(index == "I" && queue.peek() =="D"){
				int count = 0;
				//acounting for multiple D's in sequence
				while (queue.peek()=="D"){
					count++;
					queue.dequeue();
				}
				Dcounter = count;
				currentnum = currentnum + count + 1;
				answer+= integerToString(currentnum);
				for (int i = 0; i<count; i++){
					currentnum--;
					answer += integerToString(currentnum);
				}
			}
			else if(index == "D" && queue.peek() == "I"){
				currentnum += Dcounter+2;
			}
			else if (index == "D" ** queue.peek() == "D"){
				while (queue.peek()=="D"){
					count++;
					queue.dequeue();
				}
				Dcounter = count;
				currentnum = currentnum + count + 1;
				answer+= integerToString(currentnum);
				for (int i = 0; i<count; i++){
					currentnum--;
					answer += integerToString(currentnum);
				}
		}
	}
	return answer;
}