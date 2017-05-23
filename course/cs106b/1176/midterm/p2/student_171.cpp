string decode(string seq) {
	if (seq == "") return "";
	string output = "";
	int length = seq.length()+1;
	string template;
	for (int i=1; i<=length; i++) {
		template += integerToString(i);
	}
	Stack<char> aux; 
	/* for any continuous D's in the input sequence, we invert
	the corresponding part of the sequence in the template string*/
	for (int i=0; i < template.length()-1; i++) {
		while(seq[i]=='D' || seq[i-1]=='D') {
			aux.push(template[i]);
			if (i == template.length()-2) { // edge case
				if (seq[i-1]=='D') {
					aux.push(template[i]);
				}
			}
			i++;
		}
		while(!aux.isEmpty()){
			output += aux.pop();
		}		
		output += template[i];
	}
	return output;
}