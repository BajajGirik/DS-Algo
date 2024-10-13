package leetcode;

func checkHelper(a, b string) bool {
    i:=0;
    j:=len(a) - 1;
    
    for i < j {
        if (a[i] != b[j]) {
            break;
        }
        i++;
        j--;
    }

    isAEqual := true;
    isBEqual := true;
    for i < j {
        if (a[i] != a[j]) {
            isAEqual = false;
        }
        if (b[i] != b[j]) {
            isBEqual = false;
        }

        if (!isAEqual && !isBEqual) {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

func checkPalindromeFormation(a string, b string) bool {
    return checkHelper(a, b) || checkHelper(b, a);
}

// a = "abiiefg"
// b = "xyzccba"

// ra = "ab"
