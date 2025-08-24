package leetcode;

func avoidFlood(rains []int) []int {
   filledLakes := map[int]int{};
   ans := []int{};

   leftOverIndices := []int{};
   currentLeftOverIndices := 0;

   for i:=0; i<len(rains); i++ {
    lake := rains[i];

    if lake > 0 {
        filledIndex, ok := filledLakes[lake]

        if ok {
            cIndex := currentLeftOverIndices;
            for cIndex < len(leftOverIndices) {
                if (leftOverIndices[cIndex] < filledIndex) {
                    cIndex++;
                    continue;
                }

                if (ans[leftOverIndices[cIndex]] != -1) {
                    cIndex++;
                    continue;
                }

                break;
            }

            if cIndex >= len(leftOverIndices) {
                return []int{};
            }

            ans[leftOverIndices[cIndex]] = lake;

            if cIndex == currentLeftOverIndices {
                currentLeftOverIndices += 1;
            }
        }

        filledLakes[lake] = i;
    } else {
        leftOverIndices = append(leftOverIndices, i);
    }

    ans = append(ans, -1);
   }

   for i:=currentLeftOverIndices; i < len(leftOverIndices); i++ {
    if ans[leftOverIndices[i]] == -1 {
        ans[leftOverIndices[i]] = 1;
    }
   }

   return ans;
}
