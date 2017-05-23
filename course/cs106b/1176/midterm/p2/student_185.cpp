bool vecContains(Vector<int> &vec, int k);

string decode(string seq) {
	
	// initialise a queue for which possible so far will be stored
	Queue<Vector<int>> q;
	
	// first digit can be 1-9 so storee in this order in queue
	for (int i=1; i<=9; i++) {
		Vector<int> v = Vector(i);
		q.enqueue(v);
	}
	
	// iterate over the given sequence
	// add new, valid solutions to the queue in inc. order
	for (int i=0;i<seq.size();i++) {
		// get current letter
		string curLet = seq[i];
		// get number of solutions in queue so that we can dequeue n times
		int qSize = q.size();
		for (int j=0; j<qSize; j++) {
			// get next solution found so far (in order)
			Vector<int> sol = q.dequeue();
			// now expand this sol with the next element
			for (int k=1; k<=9; k++) {
				// try to see if adding k to sol is allowed
				if (curLet=="I" and k > sol[sol.size()-1] and
				   (!vecContains(sol,k))) { // increment
					Vector<int> solNew = sol;
					solNew.add(k);
					q.enqueue(solNew);
				}
				if (curLet=="D" and k < sol[sol.size()-1] and
					(!vecContains(sol,k))) { // decrement
					Vector<int> solNew = sol;
					solNew.add(k);
					q.enqueue(solNew);
				}
					
			}
		}
	}
	
	// If done right, the first sol in queue is the solution
	// so return this one
	// If queue is empty return empty string
	string output;
	if (!q.isempty()) {
		Vector<int> solBest = q.dequeue();
		for (i=0;i<solBest.size();i++) {
			output += integerToString(solBest[i]);
		}
	}
	
	return output;
}

bool vecContains(Vector<int> & vec, int k) {
	for (int i=0; i<vec.size(); i++) {
		if (k==vec[i]) return true;
	}
	return false;
}
