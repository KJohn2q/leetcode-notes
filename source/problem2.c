#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next; 
};

struct ListNode* assign(struct ListNode* l1, long int n) 
{
	struct ListNode* l3 = NULL;
	struct ListNode* tempCell = NULL;
	int i = 0;
	
	l1 = (struct ListNode *) malloc(sizeof(struct ListNode)); 
    l3 = l1;
	
    if (n < pow(10, i)) {
        // n = 0
         if (l1 == NULL) {
            l1 = (struct ListNode *) malloc(sizeof(struct ListNode)); 
        }
             
        l1->val = n;
        l1->next = NULL;
    }
    else {
        // n >= 0
        while (n >= pow(10, i)) {
            if (l1 == NULL) {
                l1 = (struct ListNode *) malloc(sizeof(struct ListNode)); 
            }

            l1->val = n % (long int)pow(10, i+1) / (long int)pow(10, i);
            l1->next = NULL;

            if (tempCell != NULL) {
                tempCell->next = l1;
            }
            tempCell = l1;
            l1 = l1->next;
            i++;
        }
    }
    
    return l3;
}

void traverse(struct ListNode* l) 
{
	struct ListNode* p = NULL;
	p = l;
    
    while (p != NULL) {
    	printf("%d ", p->val);
    	p = p->next;
	}
	
	printf("\n");
}

void visit(int *n) 
{
	while (n) {
		printf("%d ", *n);
	}
	
	printf("\n");
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
	int temp;  // 两数每位上数字之和 
    int decade = 0;  // 进位 
    struct ListNode* l3;
    struct ListNode* tempCell = NULL;
    
    l3 = l1;  // 指向l1的第一个结点 
	
	// 两数求和 
	while(l2) {
		if (l1) {
			// l1 l2均不为空 
			temp = l1->val + l2->val + decade;
			
			// 两数该位数字之和为两位数 
			if (temp >= 10) {
				l1->val = temp%10; // 该位的结果为除以10的余数 
				decade = 1;  // 向前一位进1 
			} 
			else {
				l1->val = temp;
				decade = 0;
			}	
		}
		else {
			// l1为空 l2不为空 
			l1 = (struct ListNode*) malloc(sizeof(struct ListNode));
			temp = l2->val + decade;  
			
			// 两数该位数字之和为两位数 
			if (temp >= 10) {
				l1->val = temp%10; // 该位的结果为除以10的余数 
				decade = 1;  // 向前一位进1 
			} 
			else {
				l1->val = temp;
				decade = 0;
			}
			
			l1->next = NULL;	
		}
		
		if (tempCell) {
			tempCell->next = l1;		
		}
		tempCell = l1;
		
		if (l1) {
			l1 = l1->next;
		}
		l2 = l2->next;
	}
	
	while (l1) {
		temp = l1->val + decade;
		
		// 两数该位数字之和为两位数 
		if (temp >= 10) {
			l1->val = temp%10; // 该位的结果为除以10的余数 
			decade = 1;  // 向前一位进1 
		} 
		else {
			l1->val = temp;
			decade = 0;
		}	
		
		if (tempCell) {
			tempCell->next = l1;		
		}
		tempCell = l1;
		
		l1 = l1->next;
	}
	
	// 当前进位为1  
	if (decade) {
		l1 = (struct ListNode*) malloc(sizeof(struct ListNode));
		
		l1->val = decade;  	
		l1->next = NULL;
		
		decade = 0;	
		
		if (tempCell) {
			tempCell->next = l1;		
		}
		tempCell = l1;
	}

    return l3;
}

int main(void) 
{
	struct ListNode* l1 = NULL;
	struct ListNode* l2 = NULL;
	struct ListNode* l3 = NULL; 
	
	
	struct ListNode* tempCell = NULL;
	
	long int n1 = 9;
	long int n2 = 99999991;
	
	l1 = assign(l1, n1);
	l2 = assign(l2, n2);
	
	l3 = addTwoNumbers(l1, l2);
	
	traverse(l3);

	return 0;
} 
