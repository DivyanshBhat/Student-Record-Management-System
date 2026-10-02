#include <stdio.h>
struct Student{
    int rollNo;
    char name[50];
    int age;
    char branch[50];
    float marks;
};
void addStudent(struct Student student[], int *studentCount){
    int i = *studentCount;
    printf("\nEnter Roll of student %d",i+1);
    scanf("%d",&student[i].rollNo);
    printf("\nEnter Name of student %d",i+1);
    scanf("%s",student[i].name);
    printf("\nEnter Age of student %d",i+1);
    scanf("%d",&student[i].age);
    printf("\nEnter Branch of student %d",i+1);
    scanf("%s",student[i].branch);
    printf("\nEnter Marks of student %d",i+1);
    scanf("%f",&student[i].marks);
    (*studentCount)++;
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
        printf("\n4.Exit");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        addStudent(student,&studentCount);
        break;
        case 2:
        displayStudents();
        break;
        case 3:
        searchStudent();
        break;
        case 4:
        return 0;
        default:
        printf("\nInvalid choice");
        }
    }
}