### Gosper's Trick for Subset Iteration

Gosper’s Hack* is famous.  Written by and named after Ralph William Gosper, Jr., it comes up any time someone on a public forum asks for people to share their favorite programming tricks or hacks.
But for as often as I’ve seen it come up, I have not seen any adequate explanation of how it works.  When someone mentions it, everyone else expresses some equivalent of “Yeah, wow” – and moves on.  So for all of you that have wondered how Gosper’s Hack works (all three of you.  You know who you are), here it is:

The Code
Here is Gosper’s Hack, written as a C function:
```cpp
void GospersHack(int k, int n)
{
    int set = (1 << k) - 1;
    int limit = (1 << n);
    while (set < limit)
    {
        DoStuff(set);

        // Gosper's hack:
        int c = set & - set;
        int r = set + c;
        set = (((r ^ set) >> 2) / c) | r;
    }
}
```
**DoStuff()** is meant to be replaced with a function that processes each different value that set takes.

#### What It Does
**Gosper’s Hack** iterates through all n-bit values that have k bits set to 1, from lowest to highest.  Given k = 3 and n = 6, it will produce the following values, in order from least to greatest:
000111b (7d)
011001b (25d)
101010b (42d)
001011b (11d)
011010b (26d)
101100b (44d)
001101b (13d)
011100b (28d)
110001b (49d)
001110b (14d)
100011b (35d)
110010b (50d)
010011b (19d)
100101b (37d)
110100b (52d)
010101b (21d)
100110b (38d)
111000b (56d)
010110b (22d)
101001b (41d)




