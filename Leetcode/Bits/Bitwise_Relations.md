### Figuring Out Sum of 2 Numbers using AND, OR and XOR values

We can figure out the sum of two numbers using just their **AND, OR and XOR** values! 
Suppose we know their **XOR values**, we can use the following property:

$` a + b = 2 \cdot (a \& b) + a \oplus b `$

The proof is as follows:

$a \oplus b$ is essentially just $a + b$ in base $2$ but we never carry over to the next bit. Recall a bit in $a \oplus b$ is $1$ only if the bit in $a$ is different from the bit in $b$, thus one of them must be a $1$. However, when we add two $1$ bits, we yield a $0$, but we do not carry that $1$ to the next bit. 
This is where $`a \& b`$ comes in.

$`a \& b`$ is just the carry bits themselves, since a bit is $1$ only if it's a $1$ in both $a$ and $b$, which is exactly what we need. We multiply this by $2$ to shift all the bits to the left by one, so every value carries over to the next bit.

**To acquire the XOR values of the two numbers, we can use the following:**

$`a \oplus b = \lnot(a \& b) \& (a | b)`$

The proof is as follows:

A bit in $`a \oplus b`$ is $1$ only if the bit in $a$ is different from the bit in $b$. 
By negating $`a \& b`$, the bits that are left on are in the following format:

- If it's $1$ in $a$ and $0$ in $b$
- If it's $0$ in $a$ and $1$ in $b$
- If it's $0$ in $a$ and $0$ in $b$

So , we can acquire the sum of any two numbers in two queries, we can easily solve the problem now. We can find the values of the first three numbers of the array using a system of equations involving their sum (note $n \geq 3$). Once we have acquired their independent values, we can loop through the rest of the array.
