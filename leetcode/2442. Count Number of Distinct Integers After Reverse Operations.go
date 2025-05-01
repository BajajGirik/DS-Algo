package leetcode;

func reverseInt(num int) int {
    finalNum := 0;

    for num != 0 {
        finalNum *= 10;
        finalNum += num % 10;
        num /= 10;
    }

    return finalNum;
}

func countDistinctIntegers(nums []int) int {
    frequencyMap := map[int]int{};
    count := 0;

    for i:=0; i<len(nums); i++ {
        _, ok := frequencyMap[nums[i]];
        if !ok {
            count++;
            frequencyMap[nums[i]] = 1;
        }

        revNum := reverseInt(nums[i]);
        _, ok = frequencyMap[revNum];

        if !ok {
            count++;
            frequencyMap[revNum] = 1;
        }
    }

    return count;
}
