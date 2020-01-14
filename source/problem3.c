#include <stdio.h>
#include <stdlib.h> 

int lengthOfLongestSubstring(char * s){
	int longestLength = 1;
	int i = 0, j = 1;
	
	if (s == NULL || *s == '\0')
        return 0;
     
    while (s[j] != '\0') {
        // check if s[j] is in substring
        int k = i;
        while (k < j) {
            if(s[k] == s[j])
                break;
            k++;
        }
        // if we found a duplicate letter at index k
        if (k != j) {
            // we reached the end of the substring
            longestLength = j-i > longestLength ? j-i : longestLength;
            // next substring start at k+1
            // and is one character long
            i = k+1;
            j = i;
        }
        else {
        	longestLength = j - i + 1 > longestLength ? j - i + 1 : longestLength ; 
		}
        j++;
    }
    return longestLength;
}

int main(void) 
{
	int l;
	char* s = "pwwkew";
	
	l = lengthOfLongestSubstring(s);
	
	printf("最长子串长度为：%d\n", l); 
	return 0;	
} 
