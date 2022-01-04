#include <bits/stdc++.h>
using namespace std;

#define alphabet 256 //possible alphabet characters

void search(char pat[], char txt[], int q)
{
	int pattern_length = strlen(pat);
	int text_lenght = strlen(txt);
	int i, j;
	int pattern_hash = 0;
	int text_hash = 0; 
	int h = 1;


	for (i = 0; i < pattern_length - 1; i++)
		h = (h * alphabet) % q;  

	for (i = 0; i < pattern_length; i++)     //hash the pattern and the text
	{
		pattern_hash = (alphabet * pattern_hash + pat[i]) % q;
		text_hash = (alphabet * text_hash + txt[i]) % q;
	}

	for (i = 0; i <= text_lenght - pattern_length; i++)  //the searching mechanism
	{
		if ( pattern_hash == text_hash )
		{
			bool flag = true;
			for (j = 0; j < pattern_length; j++)
			{
				if (txt[i+j] != pat[j])
				{
				flag = false;
				break;
				}
				
			}

			if (j == pattern_length)
				cout<<"Pattern found at index "<< i<<endl;
		}

		if ( i < text_lenght-pattern_length )
		{
			text_hash = (alphabet*(text_hash - txt[i]*h) + txt[i+pattern_length])%q;

			if (text_hash < 0)
			text_hash = (text_hash + q);
		}
	}
}

int main()
{
	char txt[] = "is this a test and you should panik";
	char pat[] = "is";
		
	int hashing_number = 101; //prime int for hashing
                 //the bigger the number the less colisions you will get, but the computation will get more complex
	search(pat, txt, hashing_number);
	return 0;
}