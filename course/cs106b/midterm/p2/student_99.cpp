string decode(string seq) {
	Queue<int> q;
	int num = 1;
	while(!seq.empty()) {
		if (seq[0] == "I") {
			int count = 0;
			while(seq[0] == "I" && !seq.empty()) {
				count++
				seq = seq.subsrt(1);
			}
			for (int j = 0; j < count; j++) {
				q.enqueue(num);
				num++;
			}
		} else {
			int counter = 0;
			while(seq[0] == "D" && !seq.empty()) {
				counter++;
				num++;
				seq = seq.substr(1);
			}
			for (int i = 0; i <= counter; i++) {
				q.enqueue(num);
				num--;
			}
		}
	}
	string str = "";
	for (int j = 0; j < q.size(); j++) {
		str += integerToString(q.dequeue(j));
	}
	return str;
}