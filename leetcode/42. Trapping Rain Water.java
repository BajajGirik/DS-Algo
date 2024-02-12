class Solution {
    public int trap(int[] height) {
        if (height.length < 1) {
            return 0;
        }
        int area = 0;

        int[] rightMax = new int[height.length];
        int[] leftMax = new int[height.length];

        int lMax = height[0], rMax = height[height.length - 1];
        for (int i=1, j = height.length - 2;i<height.length; ++i,--j) {
            if (lMax < height[i]) {
                lMax = height[i];
            }
            leftMax[i] = lMax;

            if (rMax < height[j]) {
                rMax = height[j];
            }
            rightMax[j] = rMax;
        }

        for (int i=0; i<height.length; ++i) {
            lMax = leftMax[i];
            rMax = rightMax[i];
            int minH = Math.min(lMax, rMax);
            area += Math.max(minH - height[i], 0);
        }

        return area;
    }
}
