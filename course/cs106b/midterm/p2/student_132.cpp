string decode(string seq) {
	string s;
	Queue<Char> queue;
	Set<Int> set;
	for (int i = 0; i < seq.size(); i++) {
		queue.enqueue seq[i];
	}
	while (!queue.isEmpty()) {
		char i = 'I';
		char d = 'D';
		char curr = queue.dequeue();
		if (s.size()>0) {
			string previous = s.substr(s.size()-1);
			int prev = stringToInteger(previous);
			int new;
			if (curr == i) {
				new = prev++; 
				while (set.contains(new)) {
					new++;
				}
			} else {
				new = prev--;
				while (set.contains(new)) {
					new--;
				}
			}
		 	set.add(new);
			string new = integerToString(new);
			s.append(new);
		} else if (curr == i){
			s = "1";
			set.add(1);
		} else {
			s = "2";
			set.add(2);
		}
	}
}
		
			
			
	