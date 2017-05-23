string decode(string seq) {
//take in the string 
//FIFO-queue
//queue.toString()
	//we need to some how generate random numbers between 1-9 such that they are not repeated
	//use a set? 
	//randomInteger[1,9]
	
	Stack<int>stack;
	Set<int> numStore;
	stack.push(randomInteger[1,9]); //to start the sequence
	numStore.add(stack.peek());
	//assuming tht only capital I and Ds are passed in
	for (int i=0; i<seq.length(); i++){
		if(seq[i]=="I"){
			int rand=randomInteger[1,9];
			int lastSeq=stack.peek();
			if (lastSeq==9){
				stack.pop();
				numStore.remove(9);
				rand=randomInteger[1,8];
			    while (rand<=lastSeq || numStore.contains(rand)){
				    rand=randomInteger[1,8];
				}
				numStore.add(lastSeq);
			    stack.push(lastSeq);
			}else (
				while (rand>=lastSeq || numStore.contains(rand)){
				rand=randomInteger[1,9];
			}
			numStore.add(lastSeq);
			stack.push(lastSeq);	
		}else if(seq[i]=="D"){
			int rand=randomInteger[1,9];
			int lastSeq=stack.peep();
			if (lastSeq==1){
				stack.pop();
				numStore.remove(1);
				rand=randomInteger[2,9];
			    while (rand<=lastSeq || numStore.contains(rand)){
				    rand=randomInteger[2,9];
				}
				numStore.add(lastSeq);
			    stack.push(lastSeq);
			}else{
				while (rand>=lastSeq || numStore.contains(rand)){
				rand=randomInteger[1,9];
				}
				numStore.add(lastSeq);
				queue.push(lastSeq);	
		     } 
	      }
		}
		Vector<int> vec;
				
		while(!stack.isEmpty()){
			vec.insert(vec.length-1, stack.pop);
		}
		return vec.toString();
	}

		
			
	      			  
			
