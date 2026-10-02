#include <stdio.h>
struct Student{
    int rollNo;
    char name[50];
    int age;
    char branch[50];
    float marks;
};
int checkRoll(int *rollNo){
    if(*rollNo<0){
        printf("\nRoll number cannot be negative");
        return 1;
    }
    else if(*rollNo==0){
        printf("\nRoll number cannot be 0");
        return 1;
    }
    else
    return 0;
}
int checkAge(int *age){
    if(*age<0){
        printf("\nAge cannot be negative");
        return 1;
    }
    else if(*age==0){
        printf("\nAge cannot be 0");
        return 1;
    }
    else
    return 0;
}
int checkMarks(float *marks){
    if(*marks<0){
        printf("\nMarks cannot be negative");
        return 1;
    }
    else if(*marks>100){
        printf("\nMarks cannot be greater than 100");
        return 1;
    }
    else
    return 0;
}
void addStudent(struct Student student[], int *studentCount)
{
    int i = *studentCount;
    int checkrollNo=1, checkage=1, checkmarks=1;
    while(checkrollNo){
        printf("\nEnter Roll of student %d: ",i+1);
        scanf("%d",&student[i].rollNo);
        getchar();
        checkrollNo=checkRoll(&student[i].rollNo);
    }
    printf("\nEnter Name of student %d: ",i+1);
    fgets(student[i].name,50,stdin);
    while(checkage){
        printf("\nEnter Age of student %d: ",i+1);
        scanf("%d", &student[i].age);
        getchar();
        checkage=checkAge(&student[i].age);
    }
    printf("\nEnter Branch of student %d: ",i+1);
    fgets(student[i].branch, 50, stdin);
    while(checkmarks){
        printf("\nEnter Marks of student %d: ",i+1);
        scanf("%f", &student[i].marks);
        checkmarks=checkMarks(&student[i].marks);
    }
    (*studentCount)++;
}
void displayStudent(struct Student student[],int studentCount){
    if(studentCount==0){
        printf("\nNo students to display");
        return;
    }
    for ( int i = 0; i < studentCount; i++)
        {
            printf("\nStudent %d: ",i+1);
            printf("\nRoll no: %d",student[i].rollNo);
            printf("\nName: %s",student[i].name);
            printf("\nAge: %d",student[i].age);
            printf("\nBranch: %s",student[i].branch);
            printf("\nMarks: %f",student[i].marks);
        }
}
void searchStudent(struct Student student[], int studentCount){
    int roll;
    printf("\nEnter Roll No. of student: ");
    scanf("%d",&roll);
    for (int i = 0; i < studentCount; i++)
    {
        if(student[i].rollNo==roll){
            printf("\nStudent %d: ",i+1);
            printf("\nRoll no: %d",student[i].rollNo);
            printf("\nName: %s",student[i].name);
            printf("\nAge: %d",student[i].age);
            printf("\nBranch: %s",student[i].branch);
            printf("\nMarks: %f",student[i].marks);
            return;
        }
    }
        printf("\nStudent not found");
}
int main(){
    struct Student student[100];
    int choice;
    int studentCount=0;
    printf("Student Record Management System");
    while(1){
        printf("\nSelect: ");
        printf("\n1.Add Student");
        printf("\n2.Display Student");
        printf("\n3.Search Student");
        printf("\n4.Exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        addStudent(student,&studentCount);
        break;
        case 2:
        displayStudent(student,studentCount);
        break;
        case 3:
        searchStudent(student, studentCount);
        break;
        case 4:
        return 0;
        default:
        printf("\nInvalid choice");
        }
    }
}