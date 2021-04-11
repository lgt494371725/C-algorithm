#include <stdio.h>

typedef struct student
{
    int id;
    char name[10];
    float score;
}Student;

float search(Student stu[], int n, int key)
{
    int i;
    
    for( i=0; i < n; i++ )
    {
        if( stu[i].id == key )
        {
            return stu[i].score;
        }
    }
    
    return -1;
}

int main()
{
    Student stu[4] = {
        {1024, "小明", 100}, 
        {1026, "小强", 60}, 
        {1028, "小花", 100}, 
        {1030, "小林", 60}
        };
    
    float score;
    
    score = search(stu, 4, 1024);
    printf("1024代表的人分数是%f", score);
    
    return 0;
}
