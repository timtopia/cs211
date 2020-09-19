#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]){
	//prints vowels
	for(int i=1; i<argc; i++){
		for(int j = 0; argv[i][j] != '\0'; j++){
			char c = argv[i][j];
			int vowel = (c=='a'||c=='e'||c=='i'||c=='o'||c=='u'||
				c=='A'||c=='E'||c=='I'||c=='O'||c=='U');
			if(vowel != 0)
				printf("%c", c);	
		}
	}
	printf("\n");
}
