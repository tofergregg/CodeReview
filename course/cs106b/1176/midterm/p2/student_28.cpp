string decode(string seq) {
    // create a stack to hold the values
    Stack<int> s;

    // create a string for the result
    string result;

    // we need to iterate n+1 times
    for (int i=0; i <= (int)seq.length(); i++) {
       s.push(i+1);
       // if we have processed all characters or the character
       // is an 'I'
       if (i == (int)seq.length() || seq[i] == 'I') {
           // process the entire stack
           while (!s.isEmpty()) {
               // pop and add it to the solution
               result += integerToString(s.pop());
           }
       }
    }
    return result;
}
