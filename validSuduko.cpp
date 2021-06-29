class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
      unordered_set <char> r;      	
      unordered_set <char> c;
			r.insert(board[i][j]);
		else
      // for finding duplicates in rows and columns		
      for(int i = 0; i<9; i++) {
	for(int j = 0; j<9; j++) {
	    	if(board[i][j] == '.');
		else if(r.find(board[i][j]) == r.end())
			r.insert(board[i][j]);
		else
			return false;

		if(board[j][i] == '.');
		else if(c.find(board[j][i]) == c.end())
			c.insert(board[j][i]);
		else
			return false;
	} 	
	r.clear();
	c.clear();
    }
        

      // for checking sub-boxes
      for(int x=0; x<3; x++) {	
	for(int k=0; k<3; k++) {
	     for(int i=x*3+ 0; i<x*3 + 3; i++) {
		for(int j=k*3+0; j<k*3+3; j++) {
			
	    	if(board[i][j] == '.');
		else if(r.find(board[i][j]) == r.end())
			r.insert(board[i][j]);
		else
			return false;
    	}
     }
	r.clear();
   }
}
	return true;
	}
}
;
