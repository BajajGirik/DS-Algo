package leetcode;

func findWinningPlayer(skills []int, k int) int {
   highestSkillIndex := 0;
   consecutiveWins := 0;

   for i:=1; i<len(skills); i++ {
        if skills[highestSkillIndex] > skills[i] {
            consecutiveWins++;
        } else {
            highestSkillIndex = i;
            consecutiveWins = 1;
        }

        if consecutiveWins >= k {
            return highestSkillIndex;
        }
   }

   return highestSkillIndex;
}
