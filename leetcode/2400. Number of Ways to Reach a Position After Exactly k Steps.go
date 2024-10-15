package leetcode;

const (
    modVal = 1000000007
);

func primeFactorization(num int, factorMap map[int]int, mul int) map[int]int {
    count := 0;
    initial := num;

    for num % 2 == 0 {
        num /= 2;
        count++;
    }

    if count > 0 {
        factorMap[2] += count * mul;
    }

    for i:=3; i <= initial; i+=2 {
        count = 0;

        for num % i == 0 {
            num /= i;
            count++;
        }

        factorMap[i] += count * mul;

        if num == 1 {
            break;
        }
    }

    return factorMap;
}

func factorial(num int, factorMap map[int]int, mul int) map[int]int {
    for i:=2; i<=num; i++ {
        factorMap = primeFactorization(i, factorMap, mul);
    }

    return factorMap;
}

func ways(startPos, endPos int, k int) (noOfWays int) {
    if endPos - startPos > k || (k == 0 && startPos != endPos) {
        return 0;
    }

    if endPos - startPos == k || k == 0 {
        return 1;
    }

    return ways(startPos + 1, endPos, k - 1) + ways(startPos - 1, endPos, k - 1);
}

func numberOfWays(startPos int, endPos int, k int) int {
    // return ways(startPos, endPos, k);
    moves:= mod(endPos - startPos);
    remaining := k - moves;

    if remaining < 0 || remaining % 2 == 1 {
        return 0;
    }

    factorMap := factorial(k, map[int]int{}, 1);
    factorMap = factorial(remaining / 2, factorMap, -1);
    factorMap = factorial(moves + remaining / 2, factorMap, -1);

    ans := 1;

    for key, val := range factorMap {
        if val == 0 {
            continue;
        }

        ans *= pow(key, val);
        ans %= modVal;
    }

    return ans;
}

func mod(a int) int {
    if a >= 0 {
        return a;
    }

    return -1 * a;
}

func pow(num, p int) int {
    result := 1;

    for i:=0; i<p; i++ {
        result *= num;
        result %= modVal;
    }

    return result;
}
