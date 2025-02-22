class Solution:
    def fullJustify(self, words: List[str], maxWidth: int) -> List[str]:
        i = 0
        lines = []

        while i < len(words):
            selected_words_count = 0
            j = i
            line_len = 0

            for _i in range(i, len(words)):
                word = words[_i]

                counter = 1 if selected_words_count > 0 else 0

                word_len = len(word)
                
                if line_len + word_len + counter > maxWidth:
                    j = _i
                    break
                
                selected_words_count += 1
                line_len += word_len + counter
            else:
                j = len(words)
            

            leftover_spaces = maxWidth - line_len

            if j == len(words):
                curr_line = " ".join(words[i:j])
                curr_line += " " * leftover_spaces
                lines.append(curr_line)
                break

            divisor = selected_words_count - 1 if selected_words_count > 1 else 1

            extra_space_count = leftover_spaces // divisor
            extras = leftover_spaces % divisor

            curr_line = words[i]

            if selected_words_count == 1:
                curr_line += " " * extra_space_count

            for _i in range(i+1, j):
                e = 1 if extras > 0 else 0
                spaces = " " * (extra_space_count + 1 + e)
                
                if extras > 0:
                    extras -= 1
        
                curr_line += spaces + words[_i]

            lines.append(curr_line)
            i = j

        return lines
