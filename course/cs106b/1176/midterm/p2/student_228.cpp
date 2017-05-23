string decode(string seq) {
	length = seq.length();
	Stack<int> s;
	Vector<int> vec;
	for (int i = 1; i <= length + 1; i++) {
		vec.add(i);
	}
	
	string result = "";
	
	for (int i = 0; i < length; i++) {
		if (seq[i] = 'I') {
			while (!s.isEmpty()) {			
				result.append(integerToString(vec[i]);
				result.append(integerToString(s.pop()));
			}
		}
		
		else if (seq[i] == 'D') {
			s.push(vec[i]);
		}
	}
							  
	result.append(intergerToString(vec[length]);
	while (!s.isEmpty()) {
		result.append(integerToString(s.pop()));
	}				
		
