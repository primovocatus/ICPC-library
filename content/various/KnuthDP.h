/**
 * Author: Simon Lindholm
 * License: CC0
 * Source: http://codeforces.com/blog/entry/8219
 * Description: $a[i][j] = \min_{i < k < j}(a[i][k] + a[k][j]) + f(i, j)$ with optimal k monotone: by increasing length,
 * search $k = p[i][j]$ only in $[p[i][j-1], p[i+1][j]]$. Enough: $f(b,c) \le f(a,d)$ and
 * $f(a,c) + f(b,d) \le f(a,d) + f(b,c)$ for all $a \le b \le c \le d$.
 * Time: O(N^2)
 */
