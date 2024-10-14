package leetcode;

func updateDirection(currDirection int, input int) int {
    if input == -1 && currDirection < 3 {
        return currDirection + 1;
    }
    if input == -1 {
        return 0;
    }

    if input == -2 && currDirection == 0 {
        return 3;
    }
    if input == -2 {
        return currDirection - 1;
    }

    return currDirection;
}

func binarySearch(nums []int, start int, end int, shouldNeglectOrigin bool) (finalPostition int, found bool) {
    i := 0;
    j := len(nums) - 1;

    for i <= j {
        mid := i + (j-i) / 2;
        midVal := nums[mid];

        if (midVal < start) {
            i = mid + 1;
        } else if (midVal > end) {
            j = mid - 1;
        } else if (shouldNeglectOrigin && midVal == 0) {
            i = mid + 1;
        } else {
            return midVal, true;
        }
    }

    return end, false;
}

func insertionSort(nums []int, x int) []int {
    nums = append(nums, x);

    for i:=len(nums)-2; i>=0; i-- {
        if nums[i] <= nums[i+1] {
            break;
        }

        temp := nums[i+1];
        nums[i+1] = nums[i];
        nums[i] = temp;
    }

    return nums;
}

func robotSim(commands []int, obstacles [][]int) int {
    xObstacles := map[int][]int{};
    yObstacles := map[int][]int{};

    for i:=0; i<len(obstacles); i++ {
        obstacle := obstacles[i];
        x, y := obstacle[0], obstacle[1];

        xObstacles[y] = insertionSort(xObstacles[y], x);
        yObstacles[x] = insertionSort(yObstacles[x], y);
    }

    // fmt.Println("xObstacles", xObstacles);
    // fmt.Println("yObstacles", yObstacles);

    direction := 0;
    currX := 0;
    currY := 0;
    maxVal := 0;
    isFirstMove := true;

    for i:=0; i<len(commands); i++ {
        command := commands[i];

        if command == -1 || command == -2 {
            direction = updateDirection(direction, command);
            continue;
        }

        // fmt.Println(direction, currX, currY)
        if direction == 0 {
            val, found := binarySearch(yObstacles[currX], currY, currY + command, isFirstMove);
            if (found) {
                currY = val - 1;
            } else {
                currY = currY + command;
            }
        } else if direction == 1 {
            val, found := binarySearch(xObstacles[currY], currX, currX + command, isFirstMove);
            if (found) {
                currX = val - 1;
            } else {
                currX = currX + command;
            }
        } else if direction == 2 {
            val, found := binarySearch(yObstacles[currX], currY - command, currY, isFirstMove);
            if (found) {
                currY = val + 1;
            } else {
                currY = currY - command;
            }
        } else {
            val, found := binarySearch(xObstacles[currY], currX - command, currX, isFirstMove);
            if (found) {
                currX = val + 1;
            } else {
                currX = currX - command;
            }
        }

        currVal := currX * currX + currY * currY;
        if currVal > maxVal {
            maxVal = currVal;
        }
        isFirstMove = false;
    }

    // fmt.Println(currX, currY);

    return maxVal;
}
