// Sequence Decode

#include <iostream>
//#include "console.h"
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector
#include "stack.h"
#include "queue.h"
#include "map.h"
#include "set.h"
#include "hashset.h"
#include "hashmap.h"
#include "grid.h"

using namespace std;

string decode(string seq);

int main() {
    //Vector<string> sequences = {"IIDDIDID","IDIDII","DDDD","IIII","I","D"};
    Map<string,string> sequences;
    sequences.put("IIDDIDID","125437698");
    sequences.put("IDIDII","1325467");
    sequences.put("DDDD","54321");
    sequences.put("IIII","12345");
    sequences.put("I","12");
    sequences.put("D","21");
    bool allCorrect = true;

    for (string seq : sequences) {
        string student_answer = decode(seq);
        if (student_answer != sequences[seq]) {
                cout << "INCORRECT sequence for: " << seq << endl;
                cout << "\texpected:'" << sequences[seq] << "', got:'"
                        << student_answer << "'" << endl;
                allCorrect = false;
        } else {
                cout << "correct: " << seq << " : " << student_answer << endl;
        }
    }
    if (allCorrect) {
            cout << "ALL CORRECT" << endl;
    } else {
            cout << "SOME INCORRECT SEQUENCES" << endl;
    }
    return 0;
}

//string decode(string seq) {
//    // create a stack to hold the values
//    Stack<int> s;
//
//    // create a string for the result
//    string result;
//
//    // we need to iterate n+1 times
//    for (int i=0; i <= (int)seq.length(); i++) {
//       s.push(i+1);
//       // if we have processed all characters or the character
//       // is an 'I'
//       if (i == (int)seq.length() || seq[i] == 'I') {
//           // process the entire stack
//           while (!s.isEmpty()) {
//               // pop and add it to the solution
//               result += integerToString(s.pop());
//           }
//       }
//    }
//    return result;
//}
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
