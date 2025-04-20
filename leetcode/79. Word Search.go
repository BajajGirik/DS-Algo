package leetcode;

import "strconv";

func search(board [][]byte, word string, i, j, wordI int, alreadyVisited map[string]bool) bool {
    if wordI >= len(word) {
        return true;
    }

    if i < 0 || i >= len(board) || j < 0 || j >= len(board[0]) {
        return false;
    }

    if (board[i][j] != word[wordI]) {
        return false;
    }
    
    key := strconv.Itoa(i) + "_" + strconv.Itoa(j);
    
    val, ok := alreadyVisited[key];

    if (ok && val) {
        return false;
    }

    alreadyVisited[key] = true;

    nextWordI := wordI + 1;
    
    result := search(board, word, i+1, j, nextWordI, alreadyVisited) ||
        search(board, word, i-1, j, nextWordI, alreadyVisited) ||
        search(board, word, i, j-1, nextWordI, alreadyVisited) ||
        search(board, word, i, j+1, nextWordI, alreadyVisited);
    
    alreadyVisited[key] = false;

    return result;
}


func exist(board [][]byte, word string) bool {
    alreadyVisited := map[string]bool{};

    for i:=0; i<len(board); i++ {
        for j:=0; j<len(board[i]); j++ {
            result := search(board, word, i, j, 0, alreadyVisited);
            if result {
                return result;
            }
        }
    }

    return false;
}
