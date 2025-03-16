package leetcode

func setZeroes(matrix [][]int)  {
    // zeroRows := []bool{};
    // zeroCols := []bool{};

    // for i:=0; i<len(matrix); i++ {
    //     zeroRows = append(zeroRows, false);
    // }

    // for i:=0; i<len(matrix[0]); i++ {
    //     zeroCols = append(zeroCols, false);
    // }

    // for i:=0; i<len(matrix); i++ {
    //     for j:=0; j<len(matrix[i]); j++ {
    //         if matrix[i][j] == 0 {
    //             zeroRows[i] = true;
    //             zeroCols[j] = true;
    //         }
    //     }
    // }

    // for i:=0; i<len(matrix); i++ {
    //     for j:=0; j<len(matrix[i]); j++ {
    //         if zeroRows[i] || zeroCols[j] {
    //             matrix[i][j] = 0;
    //         }
    //     }
    // }

    isRow := false;
    isCol := false;

    for i:=0; i<len(matrix); i++ {
        for j:=0; j<len(matrix[i]); j++ {
            if matrix[i][j] == 0 {
                matrix[i][0] = 0;
                matrix[0][j] = 0;

                if i == 0 {
                    isRow = true;
                }
                if j == 0 {
                    isCol = true;
                }
            }
        }
    }

    // fmt.Println(matrix)

    for i:=1; i<len(matrix); i++ {
        if matrix[i][0] == 0 {
            for j:=0; j<len(matrix[0]); j++ {
                matrix[i][j] = 0;
            }
        }
    }

    for j:=1; j<len(matrix[0]); j++ {
        if matrix[0][j] == 0 {
            for i:=0; i<len(matrix); i++ {
                matrix[i][j] = 0;
            }
        }
    }

    if matrix[0][0] == 0 {
        if isCol {
            for i:=0; i<len(matrix); i++ {
                matrix[i][0] = 0;
            }
        }
        if isRow {
            for j:=0; j<len(matrix[0]); j++ {
                matrix[0][j] = 0;
            }
        }
    }
}

/**
0  0  3  0
0  0  7  8
0  10 11 12
0 14 15 0

*/
