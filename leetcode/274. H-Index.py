from typing import List

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        citations.sort(reverse=True)

        count = 0

        for citation in citations:
            if citation < count + 1:
                break

            count += 1

        return count
