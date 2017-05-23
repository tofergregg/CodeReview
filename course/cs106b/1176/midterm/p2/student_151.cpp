string decode(string seq) {
		Stack<int> stack;
		stack.push(1);
		int track = 1;
		Queue<char> que;
		//creates queue
		for (int i =0; i < seq.length(); i++){
			char letter = seq.at(i);
			que.enqueue(letter);
		}
		while (!que.isEmpty())	{
			char curr = que.dequeue();
			if (curr=='I')	{
				stack.push(track+1);
				track++;
			}	else if	(curr=='D')	{
				int prev = stack.pop();
				stack.push(track+1);
				stack.push(track);
				track++;
			}
		}
		string output = "";
		while (!stack.isEmpty)	{
			output = stack.pop() + output;
		}
		return output;
}