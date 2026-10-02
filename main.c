#include <stdio.h>
struct Student{
    int rollNo;
    char name[50];
    int age;
    char branch[50];
    float marks;
};
void addStudent(struct Student student[], int *studentCount)
{
    int i = *studentCount;
    printf("\nEnter Roll of student %d: ", i + 1);
    scanf("%d",&student[i].rollNo);
    getchar();
    printf("\nEnter Name of student %d: ", i + 1);
    fgets(student[i].name,50,stdin);
    printf("\nEnter Age of student %d: ", i + 1);
    scanf("%d", &student[i].age);
    getchar();
    printf("\nEnter Branch of student %d: ", i + 1);
    fgets(student[i].branch, 50, stdin);
    printf("\nEnter Marks of student %d: ", i + 1);
    scanf("%f", &student[i].marks);
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
        //searchStudent();
        break;
        case 4:
        return 0;
        default:
        printf("\nInvalid choice");
        }
    }
}