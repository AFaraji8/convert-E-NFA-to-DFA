# By taking an input of a non-deterministic finite automata and a number of strings, determine the membership or non-membership of each string in the given automata language.




input :

The first line of the input will contain five integers that represent the number of automata states[q], the number of language alphabets[s], the number of acceptance states[a], the number of automata transitions[m], and
The number of stringa are in question.
By default, automata modes are named with numbers from 0 to 0 and are not included in the input.
In each subsequent lines(s lines) a symbol is given as a letter of the alphabet{Epsilon is not in alpgabets} ,
In the next line, the initial state [q0] ,
And in the next lines(a lines), the acceptance states are specified.
Then in each of the next line(m lines), the integer, symbol and integer are given separated by a space [q v q]
Finally, a string is given in each of the final lines(n lines).
example :
5 2 1 6 2
a
b
0
4
0 a 1
1 a 0
0 b 4
0 a 2
2 a 3
3 b 0
aaa
aab







