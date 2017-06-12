# Push_Swap

### What is Push_Swap?
The aim of this program is to sort the stack ('a' with one helper stack ('b').
However, only the following operations are permitted.
1. ra (rotate the 'a' stack)
2. rb (rotate the 'b' stack)
3. rr (rotate both stacks)
4. pa (push the top element of stack 'b' to stack 'a')
5. pb (push the top element of stack 'a' to stack 'b')
6. sa (swap the top two elements of the stack 'a')
7. sb (swap the top two elements of the stack 'b')
8. ss (swap the top two elements of both stacks)
9. rra (reverse rotate the 'a' stack)
10. rrb (reverse rotate the 'b' stack)
11. rrr (reverse rotate both stacks)
Furthermore, the numbers given have to be unique and between INT_MIN and INT_MAX

### Input Format
Format:
./push_swap [unique numbers]
Example:
```
elee% ./push_swap 5 8 1 7
```

### Output Format
Format:
Operations needed to sort the stack. One operation per line
Example:
```
rra
sa
rra
```

### Verifying the result of Push_Swap
Checker program is accompanied with Push_Swap program to validate the stack is indeed sorted after the given operations.
<br>
To check, simply run
```
./push_swap 5 8 1 7 | ./checker
```
If the instructions are indeed correct, it will print out OK, KO otherwise.
