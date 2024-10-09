type indWithVal struct {
    ind int;
    val int;
}

func findScore(nums []int) int64 {
    indicesWithValues := make([]indWithVal, len(nums));


    for i:=0; i<len(nums); i++ {
        indicesWithValues[i].ind = i;
        indicesWithValues[i].val = nums[i]
    }

    marked := make([]bool, len(nums));

    // fmt.Println(marked);

    sort.SliceStable(indicesWithValues, func (a, b int) bool {
        return indicesWithValues[a].val < indicesWithValues[b].val;
    });

    result := int64(0);

    for i:=0; i<len(indicesWithValues); i++ {
        ind := indicesWithValues[i].ind;
        if (marked[ind]) {
            continue;
        }

        marked[ind] = true;
        if (ind - 1 >= 0) {
            marked[ind-1] = true;
        }
        if (ind + 1 < len(nums)) {
            marked[ind + 1] = true;
        }
        
        result += int64(nums[ind]);
    }

    return result;
}
