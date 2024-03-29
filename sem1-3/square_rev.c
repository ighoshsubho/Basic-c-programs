  #include <stdio.h>

  /* find reverse of the given number */
  int reverse (int num) {
        int rev = 0, mod;
        while (num > 0) {
                mod = num % 10;
                rev = (rev * 10) + mod;
                num = num / 10;
        }
        return rev;
  }

  int main() {
        int n, i, num, rev, num_sq, rev_sq;
        printf("Result:\n");
        for (i = 10; i < 100; i++) {
                num = i;
                rev = reverse(num);
                num_sq = num * num;
                rev_sq = rev * rev;
                if (num_sq == reverse(rev_sq)) {
                        printf("\n%03d is the required number\n", num);
                        printf("square of %d is %d\n", num, num_sq);
                        printf("square of %d is %d\n", rev, rev_sq);
                }
        }
        return 0;
  }
