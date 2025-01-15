package leetcode;

func scoreOfString(s string) int {
    sum := 0;

    for i:=0; i<len(s)-1; i++ {
        sum += abs(int(s[i+1]) - int(s[i]));
    }

    return sum;
}

func abs(a int) int {
    if a < 0 {
        return -1 * a;
    }

    return a;
}
