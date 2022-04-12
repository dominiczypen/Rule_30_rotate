# Rule_30_rotate
(Abstract.) Rule 30 cellular automaton with "wrapping at edges" (solved by rotation). Branchless and with bitwise op -> fast.

(More detailled.) Rule 30 is an elementary cellular automaton introduced by Steven Wolfram
 that produces chaotic  behaviour with a few elementary rules. 
 See https://en.wikipedia.org/wiki/Rule_30 .
 For every bit (call it 'center'), calculate
 (left) XOR ((center) OR (right)), where (left) denotes the bit left of 
 (center).
 The 'left' bit of the left-most bit is the right-most bit and vice versa
 --> can treat this with rotation.
