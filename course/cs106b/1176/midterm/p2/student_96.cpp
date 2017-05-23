//I notice that there is a pattern, I is always +1+number of uninterrupted D's
//so the logic here is whenever there is a series of unbroken I's, add 1
// when I encounter an I and D, addumber of proceeding D's and I to sequence.
string decode(string seq) {
	int number = 0;
	int counter = 0;
	Queue<int>q; 
	seqLength = seq.length();
	while(seq.length() != 0;){
		if(seq.at(0) == 'I'){
			number++;
			q.enqueue(number);
			seq.erase(0,1);
		}else if(seq.at(1) == 'I'){
				number +=2
					q.enqueue(number);
			seq.erase(0,1);
		}
		else if(seq.at(2) == 'I'){
				number +=3
					q.enqueue(number);
			seq.erase(0,1);
		}
		else if(seq.at(3) == 'I'){
				number +=4
					q.enqueue(number);
			seq.erase(0,1);
		}
		else if(seq.at(4) == 'I'){
				number +=5
					q.enqueue(number);
			seq.erase(0,1);
		}
		else if(seq.at(5) == 'I'){
				number +=6
					q.enqueue(number);
			seq.erase(0,1);
		}
		else if(seq.at(6) == 'I'){
				number +=7
					q.enqueue(number);
			seq.erase(0,1);
		}
		else if(seq.at(7) == 'I'){
				number +=8
					q.enqueue(number);
			seq.erase(0,1);
		}
		else if(seq.at(8) == 'I'){
				number +=9
					q.enqueue(number);
			seq.erase(0,1);
		}
	}
	cout<<q<< endl;
}