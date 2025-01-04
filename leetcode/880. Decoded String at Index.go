package leetcode;

import "strconv"
import "strings"

func decodeAtIndexUnoptimised(s string, k int) string {
	tapeStr := ""

	for i := 0; i < len(s); i++ {
		ch := string(s[i])

		if ch >= "0" && ch <= "9" {
			repeatCount, _ := strconv.Atoi(ch)
			tapeStr = strings.Repeat(tapeStr, repeatCount)
		} else {
			tapeStr += ch
		}

		if k-1 < len(tapeStr) {
			break
		}
	}

	return string(tapeStr[k-1])
}

func decodeAtIndex(s string, k int) string {
	res := ""

	for res == "" {
		totalLen := 0
        lastChar := ""


        // fmt.Println("Starting")
        // fmt.Println("k: ", k);

		for i := 0; i < len(s); i++ {
			ch := string(s[i])

			if ch >= "0" && ch <= "9" {
				repeatCount, _ := strconv.Atoi(ch)
				lenToTraverse := totalLen * (repeatCount - 1)
                if k-lenToTraverse == 0 {
                    res = lastChar;
                    k = 0;
                    break;
                } else if k-lenToTraverse > 0 {
					k -= lenToTraverse
				} else {
					k = k % totalLen
                    if k == 0 {
                        res = lastChar
                    }
					break
				}

				totalLen *= repeatCount
			} else {
				totalLen++
				k--
                lastChar = ch;
			}

            // fmt.Println("***********")
            // fmt.Println("k: ", k);
            // fmt.Println("totalLen: ", totalLen);
            // fmt.Println("***********")

			if k == 0 {
				res = ch
				break
			}
		}
	}

    return res;
}

// leetleetcodeleetleetcodeleetleetcode
// k = 17
// totalLen = 0, k = 6
// totalLen = 1, k = 5
// totalLen = 2, k = 4
