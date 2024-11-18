package leetcode;

func sumOddLengthSubarrays(arr []int) int {
    totalSum := 0;

    for subArrayLen:=1; subArrayLen <= len(arr); subArrayLen+=2 {
        subArraySum := 0;

        for i:=0; i<subArrayLen; i++ {
            subArraySum += arr[i];
        }

        totalSum += subArraySum;

        for i:=subArrayLen; i<len(arr); i++ {
            subArraySum += arr[i] - arr[i - subArrayLen];
            totalSum += subArraySum;
        }
    }

    return totalSum;
}
