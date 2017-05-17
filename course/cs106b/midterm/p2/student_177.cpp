string decode(string seq) {
	Queue<int> increase; //store all I values
	Queue<Stack<int>> decrease; //store all D values
	Stack<int> temp;
	int count = 1;	
	for (int i=0; i< seq.size(); i++){
		if (i==0){
			if (seq[i] == "I"){
				increase.enqueue(count);	
				count ++;
				increase.enqueue(count); //add an additional number 					
			} else {
				temp.push(count);
				count ++;
				temp.push(count); //add an additional number
			}				
		} else if(seq[i] == "I"){ // get a I input
			 increase.enqueue(count);
			 if (seq[i-1} == "D"){
				 decrease.enqueue(temp); // add the previous D series			
			 }	
		// get a D input			 
		} else if (seq[i-1] == "I"){
			temp.clear();
			temp.push(count);		
		} else {
			temp.push(count);						
		}
		count ++;
	}							  
	string output;	
    Stack<int> curr; // display the output
	for (int i=0; i< seq.size(); i++){	
		if(seq[i] == "I"){   //I
		output += increase.dequeue();
		} else {	//D	    
		   if (curr.isEmpty()){
			   curr = decrese.dequeue();
		   }
			output += curr.pop();			
		}	
	}					 
	if (seq[0] == "I"){ //add the last number
		output += increase.dequeue();		
	} else {
		  if (curr.isEmpty()){
			   curr = decrease.dequeue();
		   }
			output += curr.pop();		
	}	
	return output;				 
}
	
