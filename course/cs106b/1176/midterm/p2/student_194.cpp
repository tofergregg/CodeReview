// D = first in last out
/*  when I see D, push number onto stack
    when I see I, put it in result

*/


string decode(string seq) {
	
	Queue<string> nums; 
	Stack<string> toAddS;
	string result;
	
	for (int i = 1; i<10; i++) {
		nums.enqueue(integerToString(i);	
	}
	
	for (int i=0; i<seq.length(); i++) {
		string cmd = seq[0];
		
		if (cmd == "D") {
			toAddS.push(nums.dequeue());
		} else if (cmd == "I"){
			result = result + nums.dequeue();
			while ( !toAddS.isEmpty()){
				result = result + toAddS.pop();	
			}
		}
	}
					 
    while ( !stack.isEmpty()) {
		result = result + toAddS.pop();	
	}
					 
	if (result.length() < seq.length()+1){
		result = result + nums.dequeue();	
	}
	
}
