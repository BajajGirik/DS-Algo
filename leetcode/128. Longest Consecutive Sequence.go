package leetcode;

func fillTotalFromIndexMap(startIndexMap map[int]int, totalFromIndexMap map[int]int, index int, initialIndex int) (int, int) {
    hopIndex := startIndexMap[index];

    if hopIndex == -1000000001 {
        totalFromIndexMap[index] = initialIndex - index + 1;
        return totalFromIndexMap[index], index;
    }

    finalVal, finalIndex := fillTotalFromIndexMap(startIndexMap, totalFromIndexMap, hopIndex, initialIndex);
    startIndexMap[index] = finalIndex;
    totalFromIndexMap[index] = finalVal;

    return finalVal, finalIndex;
}

func longestConsecutiveOld(nums []int) int {
    maxVal := 0;
    startIndexMap := map[int]int{};
    totalFromIndexMap := map[int]int{};

    for i:=0; i<len(nums); i++ {
        _, ok := startIndexMap[nums[i]];

        if ok {
            continue;
        }

        _, prevOk := startIndexMap[nums[i] - 1];
        _, nextOk := startIndexMap[nums[i] + 1];

        if !prevOk && !nextOk {
            startIndexMap[nums[i]] = -1000000001;
        } else if prevOk && nextOk {
            startIndexMap[nums[i]] = nums[i] - 1;
            startIndexMap[nums[i] + 1] = nums[i];
        } else if prevOk {
            startIndexMap[nums[i]] = nums[i] - 1;
        } else if nextOk {
            startIndexMap[nums[i]] = -1000000001;
            startIndexMap[nums[i] + 1] = nums[i];
        }

        val := 0;
        if (nextOk) {
            nextHop := totalFromIndexMap[nums[i] + 1] + nums[i];
            val, _ = fillTotalFromIndexMap(startIndexMap, totalFromIndexMap, nextHop, nextHop);
        } else {
            val, _ = fillTotalFromIndexMap(startIndexMap, totalFromIndexMap, nums[i], nums[i]);
        }
        maxVal = max(val, maxVal);
    }


    return maxVal;
}

func max(a, b int) int {
    if a > b {
        return a;
    }
    return b;
}

func longestConsecutive(nums []int) int {
    numToFrequencyMap := map[int]int{};
    alreadyVisitedMap := map[int]bool{};

    for i:=0; i<len(nums); i++ {
        numToFrequencyMap[nums[i]]++;
    }

    maxVal := 0;
    for i:=0; i<len(nums); i++ {
        if alreadyVisitedMap[nums[i]] {
            continue;
        }

        left := nums[i];
        for numToFrequencyMap[left] > 0 {
            alreadyVisitedMap[left] = true;
            left--;
        }
        left++

        right := nums[i];
        for numToFrequencyMap[right] > 0 {
            alreadyVisitedMap[right] = true;
            right++;
        }
        right--;

        currVal := right - left + 1;
        if currVal > maxVal {
            maxVal = currVal;
        }
    }

    return maxVal;
}
