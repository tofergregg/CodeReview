string decode(string seq) {
	string result = "";
	Queue<char> letters;
	for(int i = 0; i<seq.length(); i++){
		letters.enqueue(seq[i]);
	}
	char ch1 = '';
	char ch2 = '';
	if(letters.size() == 1){
		ch1 = letters.dequeue();
		if(ch1 == 'I'){
			result += "12";
		}else{
			result += "21";
		}
	else{
		int upCount = 1;
		int downCount = 1;
		ch1 = letters.dequeue();
		ch2 = letters.dequeue();
		while(!letters.isEmpty()){
			if(ch1 = 'I'){
				if(ch1 == ch2){
					upCount++;
				}else{
					for(int i = 0; i<upCount; i++){
						result += integerToString(i);
					}
					upCount++;
					downCount = upCount;
				}
			}else{
				if(ch1 == ch2){
					downCount++;
				}else{
					for(int i = downCount; i>=upCount; i--){
						result += integerToString(i);
					}
					downCount++;
					upCount = downCount;
				}
			}
			ch1 = ch2;
			ch2 = letters.dequeue();
		}
		return result;
	}
				
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
			
			