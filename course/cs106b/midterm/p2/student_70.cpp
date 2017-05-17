string decode(string seq) {
	int min = 1;
	while(seq.size()!=0) {
		if(seq[0]='I') {
			Queue<int> solution;
			solution.enqueue(min);
		} else {
			Stack<int> solution;
			solution.push(min);
		}
	}
}


I give up.
This problem is retardedly hard.
there is some obvious thing I am not seeing
i know 100% how stacks and queues work
but I still cant figure this out
I feel like a double-ended queue would help
but we don't have that
example: IIIIIIID should be 234567891
how am I supposed to know, when at the first I, that I need
to begin with a 2 instead of a 1.
Maybe I use a queue, and I pile up 1-8 for all the Is,
then when I see the D take the 1 from the front of the queue and use it. But then consider the example DDDDDDDI which should be 876543219. THe only way to maintain this is with a stack. i.e. I start with 1 and for every D keep adding to the top until I get to 8 and then use the remaining 9 for the I. It makes no sense to me I can either use a stack OR a queue but not both. I thought about this problem for 45 minutes and have no work to show except these thoughts. Maybe if I encounter an I I use a queue and if I encounter a D I use a stack and mantain each respective container until I run out of Is or Ds and switch to the other. But then I don't understand how to retroactively fix previously generated numbers in O(n) time. I think you have to use a stack or a queue depending on the first character, but I am literally out of time at this point and cannot implement a solution.