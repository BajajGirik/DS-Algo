#include <bits/stdc++.h>
using namespace std;


int main() {
	string str;
	int flag,count, n;
	printf("The grammar is: S->aS, S->Sb, S->ab\n");
	printf("Enter the string to be checked:\n");
	cin >> str;
	n = str.size();

	if(str[0]=='a') {
		flag=0;
		for(count=1;count <= n;count++) {
			if(str[count]=='b') {
				flag=1;
				continue;
			} else if((flag==1)&&(str[count]=='a')) {
				printf("The string does not belong to the specified grammar\n");
				break;
			} else if(str[count]=='a')
				continue; 
			else if((flag==1)&&(count == n)) {
				printf("String accepted…..!!!!\n");
				break;
			} else {
				printf("String not accepted\n");
			}
		}
	}

	return 0;
}