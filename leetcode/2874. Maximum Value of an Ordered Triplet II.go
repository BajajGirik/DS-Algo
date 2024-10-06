package leetcode;

func maximumTripletValue(nums []int) int64 {
  end := len(nums) - 1;

  prefixes := make([]int, len(nums));
  maxValue := nums[0];

  for i:=0; i<=end; i++ {
    if (nums[i] > maxValue) {
      maxValue = nums[i];
    }
    prefixes[i] = maxValue;
  }

  suffixes := make([]int, len(nums));
  maxValue = nums[end];

  for i := end; i >= 0; i-- {
    if nums[i] > maxValue {
      maxValue = nums[i];
    }

    suffixes[i] = maxValue;
  }

  result := int64(0);
  for i:=1; i<len(nums)-1; i++ {
    prefixMaxValue := prefixes[i-1];
    suffixMaxValue := suffixes[i+1];

    temp := int64(prefixMaxValue - nums[i]) * int64(suffixMaxValue);

    if temp > result {
      result = temp;
    }
  }

  return result;
}
