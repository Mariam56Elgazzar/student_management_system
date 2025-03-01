/*
 * studentManagementSystem.c
 *
 *  Created on: Aug 14, 2024
 *      Author: Maryem
 */


#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	    int id;
	    char name[50];
	    int age;
	    float gpa;
	};

	struct node {
	    struct student data;
	    struct node *next;
	};

	struct node*head = NULL;
	/*********************existance_function to check existance of student by its id*********************/
int existance(int sid,struct node*head){

	struct node*current=head;
	//while list stil contain students
	while(current!=NULL){
		if(current->data.id == sid){
			return 1;
		}
        current = current->next;
	}
	return 0;
}
/*********************add_function*********************/
void addStudent(const struct student *const ptr) {
	//if the user enter an id is already taken
    if (existance(ptr->id, head)) {
        printf("The entered ID %d is already taken.\n", ptr->id);
        return;
    }

    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    new_node->data = *ptr;
    new_node->next = NULL;
    //if linked list empty
    if (head == NULL) {
        head = new_node;
    } else {
        struct node* current = head;
        //to reach the end of linked list
        while (current->next != NULL) {
            current = current->next;
        }
        //adding to the end
        current->next = new_node;
    }

    printf("Student with ID %d added successfully.\n", ptr->id);
}
/*********************display_function*********************/
void displayStudents(void){
	struct node*current=head;
	if(head!=NULL){
		while(current!=NULL){
			//to display each student in each line
		printf("the student data: id is %d name is %s age is %d gpa is %f",
				current->data.id,current->data.name,current->data.age,current->data.gpa);
		current=current->next;
		printf("\n");
		}
			}
	else {
				printf("there is no student here .\n");
				}
}

         /*********************search_function*********************/
void searchStudentByID(int id){
	struct node*current=head;
	if(head!=NULL){
		while(current!=NULL){
			//compare id passed in func to each the id of each node
		if(current->data.id==id){
			printf("the student is found : id is %d name is %s age is %d gpa is %f",
					current->data.id,current->data.name[50],current->data.age,current->data.gpa);
		}
		current=current->next;
		}
		printf("the student is not found.\n");
	}
	//if the linked list is empty
	else{
	printf("there is no student here .\n");
        }
}
         /*********************update_function*********************/
void updateStudent(int id){
	struct node*current=head;
	if(head!=NULL){
		while(current!=NULL){
				if(current->data.id==id){
					   printf("Enter the student's new info:\n");
//updating info after finding the student by its id
					                printf("New ID: ");
					                scanf("%d", &current->data.id);

					                printf("New Name: ");
					                scanf("%s", current->data.name);

					                printf("New Age: ");
					                scanf("%d", &current->data.age);

					                printf("New GPA: ");
					                scanf("%f", &current->data.gpa);

					                printf("Student info updated successfully.\n");
				}
				current=current->next;
	}
		printf("the student is not found .\n");

	}
	else{
		printf("there is no student here .\n");
	}

}
/*********************calculateAverage_function*********************/
float calculateAverageGPA(void) {
    int studentNum = 0;
    float totalGPA = 0.0;
    struct node *current = head;
//if linked list is empty the situation is handled
    if (head == NULL) {
        return 0.0;
    }

    while (current != NULL) {
    	//to get total gpa of all students
        totalGPA += current->data.gpa;
        studentNum++;
        current = current->next;
    }
//to avoid any mathematical error like dividing by 0
    if (studentNum == 0) {
        return 0.0;
    }

    return totalGPA / studentNum;
}


/*********************highest_score_func*********************/
void searchHighestGPA(void) {
    struct node *current = head;
    struct node *max = NULL;
    float maxgpa = 0.0;

    if (head != NULL) {
        while (current != NULL) {
            if (current->data.gpa > maxgpa) {
                maxgpa = current->data.gpa;
            	//after finding the max gpa we put it into another node
                max = current;
            }
            current = current->next;  // move to the next node
        }

        if (max != NULL) {
        	printf("the student is found : id is %d name is %s age is %d gpa is %f ",
        					max->data.id,max->data.name,max->data.age,max->data.gpa);
            printf("\n");
        }
    } else {
        printf("There is no student here.\n");
    }
}
/*********************delete_student_func*********************/

void deleteStudent(int id){
	struct node*current=head;
	struct node*deleted=head;

	    if(head!=NULL){
	    	while(current!=NULL){
	    		if(current->data.id==id){
	    			deleted=current;
	    			free(deleted);
	    		}
	    		current=current->next;
	    	}
	    	printf("Student with ID %d has been deleted.\n", id);
	    }
	    else{
	        printf("There is no student here.\n");

	    }
}


int main(void){
   int choose_case=0;
   int id;
   while(1){
	   //to ask me again and again ...
   printf("choose from 1 to 7\n");
   fflush(stdout);
   printf("1-add student\n");
   fflush(stdout);

   printf("2-display all students\n");
   fflush(stdout);

   printf("3-search by id \n");
   fflush(stdout);

   printf("4-update student info\n");
   fflush(stdout);

   printf("5-calculate avarage gpa\n");
   fflush(stdout);

   printf("6-search highest gpa\n");
   fflush(stdout);

   printf("7-delete student\n");
   fflush(stdout);

   scanf("%d",&choose_case);
   // the user choose the number which he want to know more about
   switch(choose_case){
   case 1:
	   printf("1-add student\n");
	     fflush(stdout);
	   struct student st;
	   scanf("%d",&st.id);
	   scanf("%s",&st.name[50]);
	   scanf("%d",&st.age);
	   scanf("%f",&st.gpa);
	   addStudent(&st);
	   break;
   case 2:

	   printf("2-display all students\n");
	   fflush(stdout);
	   displayStudents();
	   break;

   case 3:
	   printf("3-search by id \n");
	      fflush(stdout);
	   printf("enter the id \n");
	   scanf("%d",&id);
	   searchStudentByID(id);
	   break;

   case 4:
       printf("4-update student info\n");
	   fflush(stdout);
	   printf("enter the id \n");
	      fflush(stdout);
	   scanf("%d",&id);
	   updateStudent(id);
	   break;

   case 5:
                printf("Calculating average GPA:\n");
                fflush(stdout);
                float avg = calculateAverageGPA();
                if (avg > 0.0 || head != NULL) {
                    printf("Average GPA is: %f\n", avg);
                } else {
                    printf("There are no students to calculate an average GPA.\n");
                }
                fflush(stdout);
                break;
   case 6:
	   printf("6-search highest gpa\n");
	      fflush(stdout);
	   searchHighestGPA();
	   break;

   case 7:
	   printf("7-delete student\n");
	   fflush(stdout);
	   printf("enter the id \n");
	   scanf("%d",&id);
	   deleteStudent(id);
	   break;

   }
   }
   return 0;
}
