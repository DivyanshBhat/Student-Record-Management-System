#include <stdio.h>
struct Student{
    int rollNo;
    char name[50];
    int age;
    char branch[50];
    float marks;
};
int main(){
    struct Student student[100];
    int studentCount=0;
    printf("Student Record Management System");
    return 0;
}