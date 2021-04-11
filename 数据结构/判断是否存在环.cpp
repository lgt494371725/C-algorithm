#include<stdio.h>
int hasLoop(LinkList p)
{
	LinkList cur1=L;
	int pos1=0;
	while(cur1)
	{
		LinkList cur2=L;
		int pos2=0;
		while(cur2)
		{
			if(cur2==cur1)
			{
				if(pos1==pos2)
				break;
				else
				return 1;	
			}	
			cur2=cur2->next;
			pos2++;
		}	
		cur1=cur1->next;
		pos1++;
	}	
	return 0; 
} 
