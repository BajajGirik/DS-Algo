package leetcode

import "sort"

func maxNumberOfFamilies(n int, reservedSeats [][]int) int {
	sort.Slice(reservedSeats, func(a, b int) bool {
		ra := reservedSeats[a]
		rb := reservedSeats[b]

		if ra[0] != rb[0] {
			return ra[0] < rb[0]
		}

		return ra[1] < rb[1]
	})

	// fmt.Println(reservedSeats);

	count := 0
	last := 0

	for i := 0; i < len(reservedSeats); i++ {
		r := reservedSeats[i]

		count += (r[0] - last - 1) * 2

		j := i
		left, mid, right := true, true, true

		for ; j < len(reservedSeats) && r[0] == reservedSeats[j][0]; j++ {
			rj := reservedSeats[j][1]

			if rj == 2 || rj == 3 {
				left = false
			} else if rj == 4 || rj == 5 {
				left = false
				mid = false
			} else if rj == 6 || rj == 7 {
				mid = false
				right = false
			} else if rj == 8 || rj == 9 {
				right = false
			}
		}

		if left || right {
			count += boolToInt(left) + boolToInt(right)
		} else if mid {
			count++
		}

		i = j - 1
		last = r[0]
	}

	count += (n - last) * 2

	return count
}

func boolToInt(b bool) int {
	if b {
		return 1
	}

	return 0
}
