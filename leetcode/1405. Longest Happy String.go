package leetcode;

func longestDiverseString(a int, b int, c int) string {
    locks := []bool{false, false, false}
    items := []int{a, b, c}

    result := ""

    for true {
        i := findMaxIndexAndLock(items, locks)
        maxVal := items[i]

        if maxVal == 0 {
            break
        }

        maxVal2 := findMax(items, locks)
        ch := string(i + 'a')

        if maxVal == 1 || maxVal2 > maxVal {
            result += ch
            items[i] -= 1
            continue
        }

        result += ch + ch;
        items[i] -= 2
    }

    return result
}

func findMaxIndexAndLock(a []int, locks []bool) int {
    index := -1

    for i:=0; i<len(a); i++ {
        if locks[i] {
            locks[i] = false
            continue
        }

        if index == -1 || a[index] < a[i] {
            index = i
        }
    }

    locks[index] = true
    return index;
}

func findMax(a []int, locks []bool) int {
    index := -1

    for i:=0; i<len(a); i++ {
        if locks[i] {
            continue
        }

        if index == -1 || a[index] < a[i] {
            index = i
        }
    }

    return a[index];
}

/**
a = 1, b = 6, c = 7
cc -> a = 1, b = 6, c = 5 X
ccbb -> a = 1, b = 4 X, c = 5
ccbbcc -> a = 1, b = 4, c = 3 X
ccbbccbb -> a = 1, b = 2 X, c = 3
ccbbccbbcc -> a = 1, b = 2, c = 1 X
ccbbccbbccbb -> a = 1, b = 0 X, c = 1
ccbbccbbccbbac -> a = 0, b = 0, c = 0

a = 1, b = 3, c = 15
cc -> a = 1, b = 3, c = 13 X
ccb -> a = 1, b = 2 X, c = 13
ccbcc -> a = 1, b = 2, c = 11 X
ccbccb -> a = 1, b = 1 X, c = 11
ccbccbcc -> a = 1, b = 1, c = 9 X
ccbccbccb -> a = 1, b = 0 X, c = 9
ccbccbccbcc -> a = 1, b = 0, c = 7 X
ccbccbccbcca -> a = 0 X, b = 0, c = 7
ccbccbccbccacc -> a = 0, b = 0, c = 5
*/
