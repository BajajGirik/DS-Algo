package leetcode;

func countBits(n int) []int {
    result := []int{0};

    lastPowOfTwo := 0
    nextPowOfTwo := 1

    for i:=1; i<=n; i++ {
        if i == nextPowOfTwo {
            result = append(result, 1);
            lastPowOfTwo = nextPowOfTwo;
            nextPowOfTwo *= 2;
        } else {
            result = append(result, result[lastPowOfTwo] + result[i - lastPowOfTwo])
        }
    }

    return result;
}

/**
0,1,2,3,4,5,6,7,8,9,10

1 -> 01
2 -> 10 -> 1

3 -> 11
4 -> 100
5 -> 101
6 -> 110
7 -> 111

8 -> 1000
9 -> 1001


3 -> 11  -> 2
4 -> 100  -> 1
5 -> 101
6 -> 110
7 -> 111
8 -> 1000
9 -> 1001
10 -> 1010
11 -> 1011 -> 3
12 -> 1100
13 -> 1101
14 -> 1110
15 -> 1111
16 -> 10000
...
15 ->
16 -> 10000


110

*/
