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
        {1024, "С��", 100}, 
        {1026, "Сǿ", 60}, 
        {1028, "С����", 100}, 
        {1030, "С��", 60}
        };
    
    float score;
    
    score = search(stu, 4, 1024);
    printf("1024������˷�����%f", score);
    
    return 0;
}
