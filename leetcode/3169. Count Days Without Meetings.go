package leetcode;

func countDays(days int, meetings [][]int) int {
    sort.Slice(meetings, func (a, b int) bool {
        m1 := meetings[a];
        m2 := meetings[b];

        if m1[0] != m2[0] {
            return m1[0] < m2[0];
        }

        return m1[1] < m2[1];
    });

    // fmt.Println(meetings)

    count := 0;
    maxMeetingEnd := 0;

    for i:=0; i<len(meetings); i++ {
        curr := meetings[i];

        if curr[0] > maxMeetingEnd {
            count += curr[0] - maxMeetingEnd - 1;
        }

        maxMeetingEnd = max(maxMeetingEnd, curr[1]);
    }

    if days > maxMeetingEnd {
        count += days - maxMeetingEnd;
    }

    return count;
}

func max(a, b int) int {
    if a > b {
        return a;
    }

    return b;
}
