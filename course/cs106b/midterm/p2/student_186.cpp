string decode(string seq) {
	Stack<int> s;
	Set<int> used;
	int inARow = 0;
	s.push(1);
	used.add(1);
	for (int i = 0; i<seq.length(); i++){
		if (seq[i]=="I"){
			s.push(i+2);
			used.add(i+2);
		}else{
			s.pop();
			s.push(i+3);
			s.push(i+2);
		}
	}
	String answer;
	while (!s.isEmpty){
		answer.insert(0,s.pop());
	}
	return answer;	
}


//Start with {1,2}
//Repeat steps below"
//if increasing, add next lowest non used {3}
//if decreasing, delete previous stored {2}, increase to next lowest nonused {3}, store that {3}, and enter after the former value {2}
	//{1,3,2}

//"
//On subsequent decreasings, you have to go all the way back to last increasing and increase that number further. 

//Keep track of used numbers somewhere in order to make sure nonrepeating.
