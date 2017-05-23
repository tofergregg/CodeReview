string decode(string seq) {
	Stack<int> s;
	Set<int> used;
	int length = seq.length();
	for (int i = 0; i < length; i++) {
		if (seq[i] == 'D') {
			s.push(length + 1);
			used.add(length + 1);
		} else {
			s.push(1);
			used.add(1);
		}
		for (char ch : seq) {
			int current = s.peek();
			if (seq[i] == 'D') {
				int next = current - 1;
				while (used.contains(next) && next > 0) {
					next--;
				}
				s.push(next);
				used.add(next);
			} else {
				int next = current + 1;
				while (used.contains(next) && next < length + 1) {
					next++;
				}
				s.push(next);
				used.add(next);
			}
		}
	}
	string result = "";
	for (int j = 0; j < s.size(); j++) {
		int a = s.pop();
		string temp = integerToString(a);
		result.insert(0, temp);
	}
	return result;
}