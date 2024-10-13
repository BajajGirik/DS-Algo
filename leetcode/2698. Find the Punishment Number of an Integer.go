package leetcode;

import (
  "strconv"
  "fmt"
);

func canMatch(num string, target int, i int, curr string, total int) bool {
	if i >= len(num) {
		currInt, _ := strconv.Atoi(curr)
		total += currInt
		return total == target
	}

	ch := string(num[i])
	result := canMatch(num, target, i+1, curr+ch, total)
	if result {
		return true
	}

	currInt, _ := strconv.Atoi(curr)
	total += currInt
	return canMatch(num, target, i+1, ch, total)
}

func hasDigitSum(num int, target int) bool {
	numString := strconv.Itoa(num)
	return canMatch(numString, target, 0, "", 0)
}

func getPunishmentNumbers(num int) {
	for i := 1; i <= num; i++ {
		if hasDigitSum(i*i, i) {
			fmt.Println(i, ",")
		}
	}
}

func punishmentNumber(n int) int {
	// getPunishmentNumbers(1000);
	punishmentNumbers := []int{
		1,
		9,
		10,
		36,
		45,
		55,
		82,
		91,
		99,
		100,
		235,
		297,
		369,
		370,
		379,
		414,
		657,
		675,
		703,
		756,
		792,
		909,
		918,
		945,
		964,
		990,
		991,
		999,
		1000,
	}

    total := 0;

    for i:=0; i<len(punishmentNumbers); i++ {
        if (punishmentNumbers[i] > n) {
            break;
        }

        total += punishmentNumbers[i] * punishmentNumbers[i];
    }

	return total;
}
