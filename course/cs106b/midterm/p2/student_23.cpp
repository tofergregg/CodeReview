string decode(string seq) {
	string output;
	Queue<char> seqQ;
	for(int i = 0; i < seq.size() - 1; i++) {
		seqQ.enqueue(seq[i]);
	}
	int iCounter;
	int dCounter;
	while(!seqQ.isEmpty()){
		char indicator = seqQ.peek();
		if(indicator == 'D') {
			dcounter++;
		{ 	else {
			iCounter++;
			{
	while(!seqQ.isEmpty()) {
		char sequenceIndicator = seqQ.dequeue();
		int firstOutPut = 1;
		if(sequenceIndicator == 'I') {
			int iOutputToAdd = randomReal(firstOutPut, 9 - iCounter);
			string newIOutPut = integerToString(outputToAdd);
			output += newIOutPut;
			firstoutput = outputToAdd;
			{
		if(sequenceIndicator == 'D' && firstOutPut != 1) {
			int dOutputToAdd = randomReal(0 + dCounter, firstOutPut);
			string newDOutPut = integerToString(dOutputToAdd);
			output += newDOutPut;
			firstoutput = dOutputToAdd;
			{
	return output;
{
	