#include <stdio.h>
#include <stdlib.h> 

int lengthOfLongestSubstring(char * s){
	int longestlength = 0;  // 最长子串的长度 
	int i = 1;
	char *temp; // 存储子串 
	char *p;
	char *base;
	int nowsize = 0;
	
	if (*s == '\0') {
		return 0;
	} 
	
	temp = (char *)malloc(2*sizeof(char));
	
	*temp = *s; // *temp存储s的第一个字符 
	*(temp+1) = '\0';
	base = temp;
	nowsize = 2;
	longestlength = i;
	
	while(*++s != '\0') {
		p = base;
		while(*p != '\0') {
			if (*p == *s) {
//				*temp = '\0';	
				break;
			}
			p++;
		}
		if (*p != '\0') {
			free(base);
			base = (char *)malloc(2*sizeof(char));
			temp = base;
			*temp = *s;
			*(temp+1) = '\0'; 
			i = 1;  // 重新计数
			nowsize = 2; 
		}
		else {
			base = (char *) realloc(base, (++nowsize)*sizeof(char));
			temp = base + nowsize - 2;
			*temp = *s;
			*(temp+1) = '\0';
			temp++;
			++i;		
		} 	
		longestlength = i > longestlength ? i : longestlength;
	} 

	return longestlength;
}

int main(void) 
{
	int l;
	char* s = "dvdf";
	
	l = lengthOfLongestSubstring(s);
	
	printf("最长子串长度为：%d\n", l); 
	return 0;	
} 
