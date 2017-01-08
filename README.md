"# Negation-as-Failure-" 
# Negation-as-Failure-
You will be asked to type in the file name of the input file, which should be in the same folder as the program file. 
Be sure to include .txt at the end of the file name.

Text files must be written in the following format in order to be read correctly.

[p [q r1] [s]]  #comments 

I have only tested it on windows bash, but presumably it should work with Linux bash as well.

Alternatively, you may use the 411A2.cpp file to compile the program with some other C++ compilier. 

The program is written in C++ std 11

Unfortunately, the program does not run at O(n) time. It is more like O(n^2), but it seems to be correct. 


Results:

From 
[p [q] [r]] #comments
[p [s] []]
[q [] [s]]
[r [][t]]
[t [] [] ]
[s [w] []]

I got the following output: 
 { t q p not-w not-r not-s }

From
[a [b] []]
[b [] [h]]
[c [d e] []]
[e [] [] ]
[f [] [g h j]]
[f [j] []]
[g [] [j]]
[h [e] []]
[i [] [k]]
[k [] [i]]

I got the following output:
 { e g h not-d not-j not-f not-b not-c not-a }


From
[p [q] [r]]
[q [s] []]
[q [t] []]
[t [] []]
 { t q p not-r not-s }
