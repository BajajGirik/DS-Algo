class Solution {
    int[][] results;
    int resultIndex = 0;

    private void customAppend(int[] item) {
        results[resultIndex] = item;
        ++resultIndex;
    }

    public int[][] insertComplex(int[][] intervals, int[] newInterval) {
        results = new int[intervals.length + 1][2];
        boolean isProcessed = false;

        for (int i=0; i<intervals.length; ++i) {
            int[] currInterval = intervals[i];
            boolean notReached = newInterval[0] > currInterval[1];
            boolean liesWithin = currInterval[0] <= newInterval[0] && currInterval[1] >= newInterval[1];

            if (isProcessed || notReached || liesWithin) {
                customAppend(currInterval);
                isProcessed = isProcessed || liesWithin;
                continue;
            }

            if (newInterval[1] < currInterval[0]) {
                customAppend(newInterval);
                customAppend(currInterval);
                isProcessed = true;
            } else if (newInterval[0] < currInterval[0] && newInterval[1] < currInterval[1]) {
                customAppend(new int[] {newInterval[0], currInterval[1]});
                isProcessed = true;
            } else if (newInterval[1] > currInterval[1]) {
                int start = Math.min(currInterval[0], newInterval[0]);
                ++i;
                while (i < intervals.length) {
                    int[] nextInterval = intervals[i];
                    if (newInterval[1] < nextInterval[0]) {
                        customAppend(new int[] {start, newInterval[1]});
                        isProcessed = true;
                        break;
                    } else if (newInterval[1] <= nextInterval[1]) {
                        customAppend(new int[] {start, nextInterval[1]});
                        ++i;
                        isProcessed = true;
                        break;
                    }
                    ++i;
                }
                if (!isProcessed) {
                    customAppend(new int[] {start, newInterval[1]});
                    isProcessed = true;
                }
                --i;
            } else if (newInterval[0] > currInterval[0]) {
                customAppend(newInterval);
                isProcessed = true;
            }
        }

        if (!isProcessed) {
            customAppend(newInterval);
            isProcessed = true;
        }

        int[][] finalResult = new int[resultIndex][2];
        for (int i=0; i<resultIndex; ++i) {
            finalResult[i] = results[i];
        }

        return finalResult;
    }

    public int[][] insert(int[][] intervals, int[] newInterval) {
        int[][] results = new int[intervals.length + 1][2];
        int i=0;

        while(i < intervals.length) {
            int[] currInterval = intervals[i];
            if (currInterval[1] >= newInterval[0]) {
                break;
            }
            results[i] = currInterval;
            ++i;
        }

        int start = i < intervals.length ? Math.min(intervals[i][0], newInterval[0]) : newInterval[0];
        int last = newInterval[1];
        int resultIndex = i;

        while (i < intervals.length) {
            int[] currInterval = intervals[i];
            if (newInterval[1] > currInterval[1]) {
                ++i;
                continue;
            }

            if (newInterval[1] >= currInterval[0]) {
                last = currInterval[1];
                ++i;
            }
            break;
        }

        results[resultIndex++] = new int[] {start, last};

        while (i < intervals.length) {
            results[resultIndex++] = intervals[i];
            ++i;
        }

        int[][] finalResults = new int[resultIndex][2];
        for (i=0; i<resultIndex; ++i) {
            finalResults[i] = results[i];
        }

        return finalResults;
    }
}
