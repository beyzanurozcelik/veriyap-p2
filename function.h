struct nodeClass
{
	int classID;
	double classMidtermAverage;
	struct nodeClass *next;
	struct nodeStudent *studentPtr;
};

struct nodeStudent
{
	int studentID;
	int midterm;
	struct nodeStudent *next;
};

void insert(struct nodeClass **head, int id, int midterm1) {
	if (*head == NULL) {
		struct nodeClass *newnode1;
		newnode1 = malloc(sizeof(struct nodeClass));
		newnode1 -> classID = 1;

		struct nodeClass *newnode2;
		newnode2 = malloc(sizeof(struct nodeClass));
		newnode2 -> classID = 2;
		
		struct nodeClass *newnode3;
		newnode3 = malloc(sizeof(struct nodeClass));
		newnode3 -> classID = 3;
		
		struct nodeClass *newnode4;
		newnode4 = malloc(sizeof(struct nodeClass));
		newnode4 -> classID = 4;
		
		newnode1->next = newnode2;
		newnode2->next = newnode3;
		newnode3->next = newnode4;
		newnode4->next = NULL;
		
		newnode1->studentPtr = NULL;
		newnode2->studentPtr = NULL;
		newnode3->studentPtr = NULL;
		newnode4->studentPtr = NULL;
		
		struct nodeStudent *newstudent;
		newstudent = malloc(sizeof(struct nodeStudent));
		
		if (id >= 66000 && id < 77000) {
			newnode1 -> studentPtr = newstudent;
			newstudent -> studentID = id;
			newstudent -> midterm = midterm1;
			newstudent -> next = NULL;	
		}
		else if (id >= 77000 && id < 88000) {
			newnode2 -> studentPtr = newstudent;
			newstudent -> studentID = id;
			newstudent -> midterm = midterm1;
			newstudent -> next = NULL;
		}
		else if (id >= 88000 && id < 99000) {
			newnode3 -> studentPtr = newstudent;
			newstudent -> studentID = id;
			newstudent -> midterm = midterm1;
			newstudent -> next = NULL;
		}
		else if (id >= 99000 && id < 100000) {
			newnode4 -> studentPtr = newstudent;
			newstudent -> studentID = id;
			newstudent -> midterm = midterm1;
			newstudent -> next = NULL;
		}
		*head = newnode1;
	
	}
	else {
		struct nodeStudent *newstudent;
		newstudent = malloc(sizeof(struct nodeStudent));
		
		struct nodeClass *temp;
		temp = *head;
		
		int c;
		
		if (id >= 66000 && id < 77000) {
			c = 1;
		}
		else if (id >= 77000 && id < 88000) {
			c = 2;
		}
		else if (id >= 88000 && id < 99000) {
			c = 3;
		}
		else if (id >= 99000 && id < 100000) {
			c = 4;
		}
		switch(c) {
			case 1 :
				while (temp->classID != 1) {
					temp = temp->next;
				}
				if (temp -> studentPtr == NULL) {
					temp -> studentPtr = newstudent;
					newstudent -> studentID = id;
					newstudent -> midterm = midterm1;
					newstudent -> next = NULL;
				}
				else {
					struct nodeStudent *temp2; 
					temp2 = temp -> studentPtr;
					
					while (temp2->next != NULL) {
						temp2 = temp2->next;
					}
					temp2 -> next = newstudent;
					newstudent -> studentID = id;
					newstudent -> midterm = midterm1;
					newstudent -> next = NULL;
				}
				break;
			
			case 2 :
				while (temp->classID != 2) {
					temp = temp->next;
				}
				if (temp -> studentPtr == NULL) {
					temp -> studentPtr = newstudent;
					newstudent -> studentID = id;
					newstudent -> midterm = midterm1;
					newstudent -> next = NULL;
				}
				else {
					struct nodeStudent *temp2; 
					temp2 = temp -> studentPtr;
					
					while (temp2->next != NULL) {
						temp2 = temp2->next;
					}
					temp2 -> next = newstudent;
					newstudent -> studentID = id;
					newstudent -> midterm = midterm1;
					newstudent -> next = NULL;
				}
				break;
		
			case 3 :
				while (temp->classID != 3) {
					temp = temp->next;
				}
				if (temp -> studentPtr == NULL) {
					temp -> studentPtr = newstudent;
					newstudent -> studentID = id;
					newstudent -> midterm = midterm1;
					newstudent -> next = NULL;
				}
				else {
					struct nodeStudent *temp2; 
					temp2 = temp -> studentPtr;
					
					while (temp2->next != NULL) {
						temp2 = temp2->next;
					}
					temp2 -> next = newstudent;
					newstudent -> studentID = id;
					newstudent -> midterm = midterm1;
					newstudent -> next = NULL;
				}
				break;
		
			case 4 :
				while (temp->classID != 4) {
					temp = temp->next;
				}
				if (temp -> studentPtr == NULL) {
					temp -> studentPtr = newstudent;
					newstudent -> studentID = id;
					newstudent -> midterm = midterm1;
					newstudent -> next = NULL;
				}
				else {
					struct nodeStudent *temp2; 
					temp2 = temp -> studentPtr;
					
					while (temp2->next != NULL) {
						temp2 = temp2->next;
					}
					temp2 -> next = newstudent;
					newstudent -> studentID = id;
					newstudent -> midterm = midterm1;
					newstudent -> next = NULL;
				}
				break;
		}
	}
}

void sort(struct nodeClass *head) {
	struct nodeStudent *temp,*temp2;
	temp = head -> studentPtr;
	
	int hold1,hold2;
	
	while (temp != NULL) {
		temp2 = temp->next;
		while (temp2 != NULL) {
			if (temp->midterm < temp2->midterm) {
				hold1 = temp->midterm;
				hold2 = temp->studentID;
				temp -> midterm = temp2 -> midterm;
				temp -> studentID = temp2 -> studentID;
				temp2 -> midterm = hold1;
				temp2 -> studentID = hold2;
			}
			else if (temp->midterm == temp2->midterm) {
				if (temp->studentID > temp2->studentID) {
					hold2 = temp->studentID;
					temp -> studentID = temp2 -> studentID;
					temp2 -> studentID = hold2;
				}
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}

void computeClassAverage(struct nodeClass *head) {
	struct nodeClass *temp1=head;
	struct nodeStudent *temp2;
	int c=0,sum=0,mid;
	double average=0;
	
	while (temp1 != NULL) {
		temp2 = temp1->studentPtr;
		sort(temp1);
		
		while (temp2 != NULL) {
			c++;
			mid = temp2->midterm;
			sum = sum + mid;
			temp2 = temp2->next;
		}
		average = (double)sum / c;
		temp1 -> classMidtermAverage = average;
		
		c = 0;
		sum = 0;
		average = 0;
		
		temp1 = temp1->next;
	}
}

void printAll(struct nodeClass *head) {
	struct nodeClass *temp1=head;
	struct nodeStudent *temp2;
	
	while (temp1 != NULL) {
		printf("%d %.2f\n",temp1->classID,temp1->classMidtermAverage);
		
		temp2 = temp1->studentPtr;
		
		while (temp2 != NULL) {
			printf("%d %d\n",temp2->studentID,temp2->midterm);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
}












































// You must write all the function definitions to be used in this lab into this file.
// You may also write other functions that may be called from our functions.
// Do not make any changes to the main.c file.
// Upload function.h file to the system as StudentNumber.h.



