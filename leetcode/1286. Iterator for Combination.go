package leetcode;

type CombinationIterator struct {
	currIndex    int
	combinations []string
}

func recurse(characters string, index int, leftover int, results []string, currCombination string) []string {
    if leftover == 0 {
        return append(results, currCombination);
    }

    if index >= len(characters) || leftover > len(characters) - index {
        return results;
    }

    // pick character
    results = recurse(characters, index+1, leftover-1, results, currCombination + string(characters[index]));
    // don't pick character
    results = recurse(characters, index+1, leftover, results, currCombination);

    return results;
}

func Constructor(characters string, combinationLength int) CombinationIterator {
	combinationIterator := CombinationIterator{}
	combinationIterator.combinations = recurse(characters, 0, combinationLength, []string{}, "");
    // fmt.Println(combinationIterator.combinations)
	return combinationIterator;
}

func (this *CombinationIterator) Next() string {
	combination := this.combinations[this.currIndex]
	this.currIndex++
	return combination
}

func (this *CombinationIterator) HasNext() bool {
	return this.currIndex < len(this.combinations)
}

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * obj := Constructor(characters, combinationLength);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */
