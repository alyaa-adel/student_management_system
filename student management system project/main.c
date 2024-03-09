#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define max 100
#include <stdbool.h>
int contains_space(const char *name)
{
    return strchr(name, ' ') != NULL;
}

typedef struct
{
    char name[200];
    int ID;
    char gender;
    int academic_year;
    float GPA;
} student;
student students[max] = {
    {"shahd elhussieny", 2004623, 'f', 4, 3.1},
    {"alyaa adel", 2045627, 'f', 4, 3},
    {"yassmina nader", 2047835, 'f', 4, 2.9},
    {"mohamed ahmed", 2077368, 'm', 3, 2.5},
    {"seif mostafa", 2036798, 'm', 4, 2.5}};

void add_student()
{
    int c, y;
    char newname1[50], newname2[50];
    for (c = 0; c <= max; c++)
    {

        if (students[c].ID == 0)
        {
            y = c;
            c = 100;
        }
    }
    printf("Enter your first name: ");
    /* scanf("%s",newname1)*/
    fflush(stdin);
    fgets(newname1, sizeof(newname1), stdin);

    if (contains_space(newname1))
    {
        printf("Error: Name contains spaces.\n");
        return; /* Return an error code indicating failure*/
    }
    else
    {
        newname1[strcspn(newname1, "\n")] = 0;
        strcpy(students[y].name, newname1);
        fflush(stdin);
        printf("Enter your last name: ");
        fgets(newname2, sizeof(newname2), stdin);

        if (contains_space(newname2))
        {
            printf("Error: Name contains spaces.\n");
            return; /*Return an error code indicating failure*/
        }
        else
        {
            newname2[strcspn(newname2, "\n")] = 0;
            strcat(students[y].name, " ");
            strcat(students[y].name, newname2);
            printf("Name: %s\n", students[y].name);
        }
    }
    int i, id;
    printf("enter the student's ID (must be 7-digit number)\n");
    scanf("%d", &id);
    int x = floor(log10(id)) + 1;
    for (i = 0; i <= max; i++)
    {

        if (students[i].ID == id)
        {
            printf("this id is already taken, please enter another one with 7 digits");
            i = 103;
            return;
        }
    }
    if (x == 7)
    {
        printf("ID is valid\n");
        students[y].ID = id;
        i = 103;
    }
    else
    {
        printf("ID is invalid, please enter another ID with 7 digits\n");
        i = 100;
        return;
    }

    printf("enter student gender (write m or M for male and F or f for female)\n");
    char new_gender;
    scanf(" %c", &new_gender);
    if (new_gender == 'M' || new_gender == 'm' || new_gender == 'F' || new_gender == 'f')
    {
        printf("valid gender\n");
        students[y].gender = new_gender;
    }
    else
    {
        printf("gender is invalid please enter another input\n");
    }

    int newyear;
    printf("enter student academic year (must be from 1 to 5)\n");
    scanf("%d", &newyear);
    if (newyear >= 1 && newyear <= 5)
    {
        printf("valid input for the academic year\n");
        students[y].academic_year = newyear;
    }
    else
    {
        printf("invalid input, please enter another one\n");
        return;
    }

    float newgpa;
    printf("enter student GPA (must be from 0.0 to 4.0)\n");
    scanf("%f", &newgpa);
    if (newgpa >= 0.0 && newgpa <= 4.0)
    {
        printf("valid input for the GPA\n");
        students[y].GPA = newgpa;
    }
    else
    {
        printf("please enter another input fot your GPA\n");
        return;
    }

    printf("student added successfully\n");
}

void remove_student()
{
    int found = -1;
    int m, T, id, x = max;
    printf("enter the student's ID (must be 7-digit number)\n");
    scanf("%d", &id);
int i;
    for ( i = 0; i < max; i++)
    {
        if (students[i].ID == id)
        {
            found = i;
            i = max + 1;
        }
    }

    if (found == -1)
    {
        printf("ID not found. No student with ID %d exists.\n", id);
        return;
    }
    for (m = found; m < max - 1; m++)
    {
        students[m] = students[m + 1];
    }
    printf("Operation Successful. Student with ID %d removed.\n", id);
}
int num_students = 10;

void retrieve_student()
{
    int choice;
    int num_students = 5; /* Assuming 5 students initially*/
    printf("Choose how to retrieve\n");
    printf("Type 1 to retrieve by name\n");
    printf("Type 2 to retrieve by ID\n");
    scanf("%d", &choice);
    getchar(); /*Consume newline character*/

    if (choice == 1)
    {int r;
        char name[200];
        printf("Enter the student's name to retrieve (first last):\n");
        scanf(" %[^\n]", name); /* Read the name with spaces*/
        bool found = false;
        for ( r = 0; r < num_students; r++)
        {
            if (strcmp(students[r].name, name) == 0)
            {
                printf("Operation Successful\n");
                printf("Name: %s\nID: %d\nGender: %c\nAcademic Year: %d\nGPA: %.2f\n", students[r].name, students[r].ID, students[r].gender, students[r].academic_year, students[r].GPA);
                found = true;
                break;
            }
        }
        if (!found)
        {
            printf("Student not found\n");
        }
    }
    else if (choice == 2)
    { int i;
        int ID;
        printf("Enter the student's ID to retrieve\n");
        scanf("%d", &ID);
        getchar(); /*Consume newline character*/
        bool found = false;
        for ( i = 0; i < num_students; i++)
        {
            if (students[i].ID == ID)
            {
                found = true;
                printf("Operation Successful\n");
                printf("Name: %s\nID: %d\nGender: %c\nAcademic Year: %d\nGPA: %.2f\n", students[i].name, students[i].ID, students[i].gender, students[i].academic_year, students[i].GPA);
                break;
            }
        }
        if (!found)
        {
            printf("Student not found\n");
        }
    }
    else
    {
        printf("Invalid option\n");
    }
}

/*Function to update student's academic year*/
void update_academic_year(int id)
{
    int newyear;
    printf("please enter your updated academic year ");
    scanf("%d", &newyear);
    int i;
    for (i = 0; i < num_students; i++)
    {
        if (students[i].ID == id)
        {
            if (newyear >= 1 && newyear <= 5)
            {
                students[i].academic_year = newyear;
                printf("Academic year is updated successfully.\n");
                return;
            }
            else
            {
                printf("Error! Invalid Year. Please enter a value between 1 and 5\n");
                return;
            }
        }
    }

    printf("Invalid id /n", id);
}

void update_gpa(int id)
{
    float newgpa;

    printf("please enter your updated gpa: ");
    scanf("%f", &newgpa);
int i;
    for ( i = 0; i < num_students; i++)
    {
        if (students[i].ID == id)
        {
            if (newgpa >= 0 && newgpa <= 4)
            {
                students[i].GPA = newgpa;
                printf("GPA is updated successfully \n");
                return;
            }
            else
            {
                printf("Error! Invalid GPA. Please enter a value between 0 and 4\n");
                return;
            }
        }
    }

    printf("Invalid id \n", id);
}

void update_student_data()
{
    int id,i, choice;

    printf("the current data is :\n");
    for ( i = 0; i < max; i++)
    {
        if (students[i].ID != 0)
        {
            printf("Name: %s, ID: %d, Academic Year: %d, GPA: %.2f, gender: %c\n", students[i].name, students[i].ID, students[i].academic_year, students[i].GPA, students[i].gender);
        }
    }
    printf(" enter the id of the student you want to update ");
    scanf("%d", &id);
    bool found = false;
    for ( i = 0; i < num_students; i++)
    {
        if (students[i].ID == id)
        {
            found = true;

            printf(" choose which one you want to update \n");
            printf(" enter 1 to update Academic Year\n");
            printf(" enter 2 to Update GPA\n");
            scanf("%d", &choice);

            switch (choice)
            {
            case 1:
                update_academic_year(id);
                break;
            case 2:
                update_gpa(id);
                break;
            default:
                printf("Invalid choice, Please enter 1 or 2\n");
                break;
            }

            return;
        }
    }

    if (!found)
    {
        printf("Invalid ID. No student with ID %d exists.\n", id);
    }
}
int main()
{
    int i,choice;
    do
    {
        for ( i = 0; i < max; i++)
        {
            if (students[i].ID != 0)
                printf("%s: %d\n", students[i].name, students[i].ID);
        }
        printf("\nStudent Management System\n");
        printf("enter 1 to add student\n");
        printf("enter 2 to remove student\n");
        printf("enter 3 to retrieve student's data\n");
        printf("enter 4 to update student's data\n");
        printf("enter 5 to  exit\n");
        int validInput = 1;
        while (1)
        {
            validInput = scanf("%d", &choice);
            if (validInput != 1)
            {
                printf("Invalid input. Please enter a number from 1 to 5.\n");
                fflush(stdin); /*Clear the input buffer*/
            }
            else
                break;
        }

        switch (choice)
        {
        case 1:
            add_student();
            break;
        case 2:
            remove_student();
            break;
        case 3:
            retrieve_student();
            break;
        case 4:
            update_student_data();
            break;
        case 5:
            printf("thank you..");
            return 0;
        default:
            printf("invalid input. try entering numbers from 1 to 5\n");
        }
    } while (choice != 5);
}
