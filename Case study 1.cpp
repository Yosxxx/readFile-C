#include <stdio.h>
#include <string.h>

void convert(char word[], int length){
	for(int i=0;i<length;i++){
		if(word[i] >= 'a' && word[i] <= 'z'){
			word[i]-=32;
		}else if(word[i] >= 'A' && word[i] <= 'Z'){
			word[i]+=32;
		}
	}	
}

void reverse(char word[], int length){
	for(int i=length-1;i>=0;i--){
		printf("%c",word[i]);
	}	
}

int main(){
	//Declaring word 100 bytes + adding 1 byte for null terminator '\0'
	char word[101];
	scanf("%s",word);
	
	//length of string
	int length = strlen(word);
	
	//function for lowercase to uppercase vice versa
	convert(word,length);
	
	//print string in a reversed order
	reverse(word,length);
	
	//Space after output
	//Just a habit because SOCS always force's it :')
	puts("");

	return 0;
}

