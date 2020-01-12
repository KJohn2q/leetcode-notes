#include <stdio.h>
#include <stdlib.h> 

int lengthOfLongestSubstring(char * s){
	int longestlength = 0;  // ��Ӵ��ĳ��� 
	int i = 0;
	char *temp; // �洢�Ӵ� 
	char *p;
	char *base;
	int nowsize = 0;
	
	temp = (char *)malloc(2*sizeof(char)); 
	
	*temp = *s; // *temp�洢s�ĵ�һ���ַ� 
	*(temp+1) = '\0';
	base = temp;
	nowsize = 2;
	
	if (*(s+1) == '\0') {
		longestlength = 1;
	}
	
	while(*++s != '\0') {
		p = base;
		while(*p != '\0') {
			if (*p == *s) {
				*temp = '\0';
				break;
			}
			p++;
		}
		if (*temp == '\0') {
			free(base);
			base = (char *)malloc(2*sizeof(char));
			temp = base;
			*temp = *s;
			*(temp+1) = '\0'; 
			i = 0;  // ���¼���
			nowsize = 2; 
		}
		else {
			base = (char *) realloc(base, (++nowsize)*sizeof(char));
			temp = base;
			*++temp = *s;
			*(temp+1) = '\0';
			++i;		
		} 	
		longestlength = i > longestlength ? i : longestlength;
	} 

	return longestlength;
}

int main(void) 
{
	int l;
	char* s = "abcabcbb";
	
	l = lengthOfLongestSubstring(s);
	
	printf("��Ӵ�����Ϊ��%d\n", l); 
	return 0;	
} 
