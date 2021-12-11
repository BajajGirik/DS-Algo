#include<iostream>
#include<vector>
#include<string>

using namespace std;

string decrypt(string passphrase)
{
	string num="";
	int i = 0;
	for(;i<passphrase.size();i++)
	{
		if (!isdigit(passphrase[i]))
			break;
		
		num += passphrase[i];
	}

	int size = num.size()-1;
	string original = "";

	for(;i<passphrase.size()-2;i++)
	{
		if(passphrase[i]=='0')
			original += num[size--];

		else if(isupper(passphrase[i]) && islower(passphrase[i+1]) && passphrase[i+2]=='*')
		{
			original += passphrase[i+1];
			original += passphrase[i];
			i += 2;
		}

		else
			original += passphrase[i];

	}

	for(;i<passphrase.size();i++)
		original += passphrase[i];

	original += '\n';
	return original;
}

int main() {

    string passphrase;
    passphrase = "43Ah*ck0rr0nk";
    
    cout << decrypt(passphrase);

    return 0;
}
