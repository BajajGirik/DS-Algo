func minimumSubarrayLength(nums []int, k int) int {
    minLength := -1;

    for i := 0; i < len(nums); i++ {
        result := 0;
        for j := i; j < len(nums); j++ {
            result = result | nums[j];
            if result < k {
                continue;
            }
            
            currLength := j - i + 1;
            if minLength == -1 || minLength > currLength {
                minLength = currLength;
            }
            break;
        }
    }

    return minLength;
}
