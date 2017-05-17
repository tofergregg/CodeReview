string decode(string seq) {
	int num = 1;
	Queue<int> q;
	bool canDo == false;
	while(! canDo) {
		for(int i = 0; i < seq.size(); i++){
			char ch = seq[i];
			checkLetter(ch, num, q);
		}
		int size = q.size();
		for(int j = 0; j < size; j++){
			int num2 = q.dequeue();
			if(num2 > 0 && num2 < 10) {
				q.enqueue(num2);
			}
		}
		if(size == q.size()) {
			canDo = true;
		} else {
			canDo = false;
		}
	}
	string final = q.toString();
	return final;
}
					
	
void checkLetter(char ch, int &num, Queue<int> &q) {
	if(ch == 'D') {
		num--;
		for(int j = 0; j < q.size(); j++) {
			int num2 = q.dequeue();
			if(num == num2) {
				num--;
			}
			q.enqueue(num2);
		}
		q.enqueue(num);
	}
	
	if(ch == 'I') {
		num++;
		for(int j = 0; j < q.size(); j++) {
			int num2 = q.dequeue();
			if(num == num2) {
				num++;
			}
			q.enqueue(num2);
		}
		q.enqueue(num);
	}
}
				