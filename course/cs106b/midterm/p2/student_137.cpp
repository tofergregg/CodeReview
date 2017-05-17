/** Method : decode (string)
* this method will run througha  string and add in corresponding values into a stack
* where D signalsa decrease and I signals an increase
* after settign the first two numbers independently from a loop
* the loop handles all consecutive numbers by peeking then increasing using the top variable
*/
string decode(string seq) {
	Stack <int> sta;
	// Handle first letter
	if (seq[0] == 'D'){		// if we get decreasing at first, push in a 2 then 1
		sta.push(2);
		sta.push(1);
	} else {				// we got an increasing, push a 1, then 2
		sta.push(1);
		sta.push(2);
	}
	// error check for if only 1 letter, the seq[1] function will return an error  
	if(seq.size()!= 1){
	// now loop through the rest of string and push in the corresponding letters
		for (int i = 1; i < seq.size(); i++){		// O(N)
			int top = sta.peek();
			if (seq[i]== 'D'){
				if (top - 1 < 0){				// error check
					cout << "Error, invalid way to go because this program can only use number 0 - 9" << endl;
				} else {
					top = top--;		// decrease the number
					sta.push(top);		
				}
			}else {						
				top = top++;
				sta.push(top);		// increase the number
			}
		}
	}
	// Once we have the string, we construct the string using another the toString function where the top element is the far right one
	return sta.toString(); 		// O(N)
}
