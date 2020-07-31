# What you should know
- Best is Omega, Average is Theta, Worst is big-Oh
- Sum of GP. Finite increasing sum.
- Other serieses and their Sum.
- Square root is greater than log
- differentiate to know the growth fn.
- Compare functions by:
    - taking out commons
    - substituting large values like 2^200 etc.

## Recursive functions
- Backsubstitution (LONG and SLOW)
- Recursion Tree Method (BEST)
- Master's theorem
    - T(n) = aT(n/b) + Theta(n^k (log^p(n)))
    - then conditions on a,b,k, p belongs to R.
    - conditions on a related to b^k
        - conditons on p wrt 1
- Be careful with quetions using memo tables. Like those of DP. As they reduce the no of subpproblems.

## Amortised Analysis
some well determined worst case. Like that of dynamic arrays.
- Aggregate Method: Dynamic Arrays
- Accounting Method: Never Read
- Potential Mehtod: defines a potential function, takes change in potential. Ex: Red Black Tree. Never Read in detail



