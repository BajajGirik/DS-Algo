package leetcode

func maxBottlesDrunk(numBottles int, numExchange int) int {
    count := numBottles;
    emptyBottles := numBottles;

    for emptyBottles >= numExchange {
        emptyBottles -= numExchange;
        emptyBottles++;
        count++;
        numExchange++;
    }

    // fmt.Println("EmptyBottles: ", emptyBottles)
    // fmt.Println("NumExchange: ", numExchange);
    return count;
}
