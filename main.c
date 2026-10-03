#include <stdio.h>
struct Student{
    int rollNo;
    char name[50];
    int age;
    char branch[50];
    float marks;
};
//validation checks
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
int duplicateRollCheck(int studentCount, int rollNo, struct Student student[]){
    for(int i=0;i<studentCount;i++){
        if (rollNo==student[i].rollNo)
        {
            printf("\nStudent already exists.");
            return 1;
        }
    }
    return 0;
}
//CRUD operations
void addStudent(struct Student student[], int *studentCount)
{
    int i = *studentCount;
    int checkrollNo=1, checkage=1, checkmarks=1, duplicateRoll=1;
    while(checkrollNo||duplicateRoll){
        printf("\nEnter Roll of student %d: ",i+1);
        scanf("%d",&student[i].rollNo);
        getchar();
        checkrollNo=checkRoll(&student[i].rollNo); // avoids negative roll no
        duplicateRoll=duplicateRollCheck(*studentCount,student[i].rollNo,student);
    }
    printf("\nEnter Name of student %d: ",i+1);
    fgets(student[i].name,50,stdin);
    while(checkage){
        printf("\nEnter Age of student %d: ",i+1);
        scanf("%d", &student[i].age);
        getchar();
        checkage=checkAge(&student[i].age); //avoids negative age
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
    if (studentCount==0){
        printf("\nNo student to search.");
        return;
    }
    for (int i = 0; i < studentCount; i++){
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
int findStudent(struct Student student[], int studentCount, int rollNo){
    for (int i = 0; i < studentCount; i++){
        if (student[i].rollNo == rollNo){
            return i;
        }
    }

    return -1;
}
void displayOneStudent(struct Student student){
    printf("\nRoll no: %d", student.rollNo);
    printf("\nName: %s", student.name);
    printf("\nAge: %d", student.age);
    printf("\nBranch: %s", student.branch);
    printf("\nMarks: %f", student.marks);
}
void updateStudent(struct Student student[], int studentCount){
    int rollNo;
    if (studentCount == 0){
        printf("\nNo student to update.");
        return;
    }
    printf("\nEnter Roll No. of student to update: ");
    scanf("%d", &rollNo);
    int index = findStudent(student, studentCount, rollNo);
    if (index == -1){
        printf("\nStudent not found.");
        return;
    }
    printf("\nCurrent Student Details:");
    displayOneStudent(student[index]);
    while (1){
        int choice;
        printf("\n\nWhat do you want to update?");
        printf("\n1. Roll No");
        printf("\n2. Name");
        printf("\n3. Age");
        printf("\n4. Branch");
        printf("\n5. Marks");
        printf("\n6. All");
        printf("\n7. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar();
        switch (choice){
        case 1:{
            int checkrollNo = 1;
            int duplicateRoll = 1;
            while (checkrollNo || duplicateRoll){
                printf("\nEnter new Roll No: ");
                scanf("%d", &student[index].rollNo);
                getchar();
                checkrollNo = checkRoll(&student[index].rollNo);
                if (student[index].rollNo == rollNo){
                    duplicateRoll = 0;
                }
                else{
                    duplicateRoll = duplicateRollCheck(
                        studentCount,
                        student[index].rollNo,
                        student
                    );
                }
            }
            rollNo = student[index].rollNo;
            break;
        }
        case 2:
            printf("\nEnter new Name: ");
            fgets(student[index].name, 50, stdin);
            break;
        case 3:{
            int checkage = 1;
            while (checkage){
                printf("\nEnter new Age: ");
                scanf("%d", &student[index].age);
                getchar();
                checkage = checkAge(&student[index].age);
            }
            break;
        }
        case 4:
            printf("\nEnter new Branch: ");
            fgets(student[index].branch, 50, stdin);
            break;
        case 5:{
            int checkmarks = 1;
            while (checkmarks){
                printf("\nEnter new Marks: ");
                scanf("%f", &student[index].marks);
                checkmarks = checkMarks(&student[index].marks);
            }
            break;
        }
        case 6:{
            int checkrollNo = 1;
            int duplicateRoll = 1;
            int checkage = 1;
            int checkmarks = 1;
            while (checkrollNo || duplicateRoll){
                printf("\nEnter new Roll No: ");
                scanf("%d", &student[index].rollNo);
                getchar();
                checkrollNo = checkRoll(&student[index].rollNo);
                if (student[index].rollNo == rollNo){
                    duplicateRoll = 0;
                }
                else{
                    duplicateRoll = duplicateRollCheck(
                        studentCount,
                        student[index].rollNo,
                        student
                    );
                }
            }
            printf("\nEnter new Name: ");
            fgets(student[index].name, 50, stdin);
            while (checkage){
                printf("\nEnter new Age: ");
                scanf("%d", &student[index].age);
                getchar();
                checkage = checkAge(&student[index].age);
            }
            printf("\nEnter new Branch: ");
            fgets(student[index].branch, 50, stdin);
            while (checkmarks){
                printf("\nEnter new Marks: ");
                scanf("%f", &student[index].marks);
                checkmarks = checkMarks(&student[index].marks);
            }
            rollNo = student[index].rollNo;
            break;
        }
        case 7:
            return;
        default:
            printf("\nInvalid choice.");
        }
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
        printf("\n4.Update Student");
        printf("\n5.Exit\n");
        scanf("%d",&choice);
        switch(choice){
        case 1:
        addStudent(student,&studentCount);
        break;
        case 2:
        displayStudent(student,studentCount);
        break;
        case 3:
        searchStudent(student,studentCount);
        break;
        case 4:
        updateStudent(student,studentCount);
        break;
        case 5:
        return 0;
        default:
        printf("\nInvalid choice");
        }
    }
}