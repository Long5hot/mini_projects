#include"header.h"

DLL * headptr = NULL;

int main(int argc, char const *argv[])
{
	int op, count, node;
	int true = 1;
	while (true)
	{	
		printf("\n**-------------------------------------------------------------**\n");
		printf("Enter your choice..\n"); 
		printf("1)Add_begin  2)Add_middle  3)Add_end  4)Print_records  5)Count_records\n6)Save_from_scratch_to_database.txt  7)Read_data_from_database.txt \n8)Delete_all_nodes  9)Print_records_using_recursion\n10)sort_data  11)Print_records_reverse_order  12)Print_Records_in_reverse_order_using_recursion\n13)Delete_a_rollno  14)Delete_a_pos  15)Reverse_data  16)Reverse_links\n17) Search_a_record 18)EXIT\n");
		scanf("%d",&op);
		switch (op)
		{
			case  1: add_begin();
				 break;
			case  2: add_middle();
				 break;
			case  3: add_end();
				 break; 
			case  4: print_records();
				 break; 
			case  5: {
					count = count_nodes();
					printf("\nThere are %d records..\n",count);
				}
				break;
			case  6: save_file();
				 break;
			case  7: read_file();
				 break;
			case  8: delete_all();
				 break;
			case  9: print_recursion(headptr);
				 break;
			case 10: sort_data();
				 break;
			case 11: reverse_print_loop();
				 break;
			case 12: reverse_print_recursion(headptr);
				 break;
			case 13: delete_node();
				 break;
			case 14: delete_pos();
				 break;
			case 15: reverse_data();
				 break;
			case 16: reverse_links();
				 break;
			case 17: { 	int num;
					scanf("%d",&num);
				 	node = search_node(num);
				 	if(node!=0)
				 		printf("Record is present..\n");
				 	else {
				 		printf("Record is not present..\n");
				 	}
				 	break;
				}
			case 18: exit(0);
			default: printf("Wrong choice has been enterd...\n");
				 break;
		}
	}

}

void sort_data(void) {
	DLL *last = headptr, *start = headptr;
	DLL temp;
	int count = count_nodes();
	
	for(int i=1; i<=count-1; i++) {
		last = start->next;
		for(int j=i+1; j<=count; j++) {
			if((start->marks) < (last->marks)) {
				temp.no = start->no;
				strcpy(temp.name,start->name);
				temp.marks = start->marks;
		
				start->no = last->no;
				strcpy(start->name, last->name);
				start->marks = last->marks;
		
				last->no = temp.no;
				strcpy(last->name, temp.name);
				last->marks = temp.marks;
			}
			if(last->next)
				last = last->next;
		}
		start = start->next;
	}
}

void reverse_data() {
	DLL *last,*start;
	last = headptr;
	start = headptr;
	int count = count_nodes();
	DLL temp;
	
	while(last->next)
		last = last->next;
	
	for(int i=1; i<=(count/2); i++) {
		temp.no = start->no;
		strcpy(temp.name,start->name);
		temp.marks = start->marks;
		
		start->no = last->no;
		strcpy(start->name, last->name);
		start->marks = last->marks;
		
		last->no = temp.no;
		strcpy(last->name, temp.name);
		last->marks = temp.marks;
	
		start = start->next;
		last = last->prev;
	}

}

void reverse_links() {
	DLL *current = headptr;
	DLL *temp = NULL;
	
	while(current != NULL) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
	}
	
	if(temp!=NULL)
		headptr = temp->prev;
}

int search_node(int num) {
	if(headptr == NULL) {
		return 0;
	}
	DLL *ptr = headptr;
	while(ptr) {
		if(ptr->no == num) {
			return 1;
		}
		ptr = ptr->next;
	}
	return 0;
}

void add_begin() {
	DLL *new;
	new = (DLL *)malloc(sizeof(DLL));
	printf("\nEnter the Details\n");
	printf("Roll_no Name and Marks...\n");
	scanf("%d %s %f",&new->no,new->name,&new->marks);

	new->prev = 0;
	new->next = headptr;
	if(headptr!=0)
		headptr->prev = new;
	headptr = new;
	printf("\n");
}
void print_records() {

	if(headptr == NULL) {
		printf("NO RECORDS FOUND...\n");
		return;
	}
	printf("\n**-----------------------------**\n");
	DLL * temp = headptr;

	while(temp){
		printf("%4d %15s %3.2f\n",temp->no,temp->name,temp->marks);
		temp = temp->next;
	}
	printf("**-----------------------------**\n\n");
}

void add_end() {
	DLL * new,*last;
	new = (DLL *)malloc(sizeof(DLL));
	new->next = 0;
	
	printf("\nRoll_no Name Marks..\n");
	scanf("%d %s %f",&new->no,new->name,&new->marks);
	printf("\n");
	if(headptr == NULL){	
		headptr = new;
		new->prev = 0;
	}
	else
	{
		last = headptr;
		while(last->next)
			last = last->next;
		new->prev = last;
		last->next = new;
	}
	
}

void add_middle() {
	DLL * new;
	new = (DLL *)malloc(sizeof(DLL));
	printf("\nRoll_no Name Marks..\n");
	scanf("%d %s %f",&new->no,new->name,&new->marks);
	
	if((headptr==0)||((headptr->no) > new->no)) {
		new->next = headptr;
		new->prev = 0;
		if(headptr!=0)
			headptr->prev = new;
		headptr = new;
	}	
	else {
		DLL *last = headptr;
		
		while(((last->next)!=0)&&((last->next->no) < (new->no)))
			last = last->next;			
		new->next = last->next;
		if(last->next)
			last->next->prev = new;
		new->prev = last;
		last->next = new;
	}
	printf("\n");
}


int count_nodes(void) {
	if(headptr==NULL) {
		printf("No records found...\n");
		return 0;
	}
	DLL * node = headptr;
	int count =0;
	while(node) {
		count++;
		node = node->next;
	}
	return count;	
}

void reverse_print_loop(void) {
	if(headptr == NULL) {
		printf("NO RECORDS FOUND...\n");
		return;
	}
	DLL * last = headptr;
	while(last->next)
		last = last->next;
	printf("\n**-----------------------------**\n");
	while(last) {
		printf("%4d %15s %3.2f\n",last->no,last->name,last->marks);
		last = last->prev;
	}
	printf("**-----------------------------**\n\n");
}


void save_file() {
	if(headptr == NULL) {
		printf("\nNO RECORDS FOUND\n");
		return;
	}
	
	printf("WARNING : This will erase your data from database.txt and save new Records from scratch...\n");
	char ch;
	printf("Enter 'Y' if you wan to continue...:   ");
	scanf(" %c",&ch);
	ch = tolower(ch);
	if(ch!='y'){
		printf("Records are not saved and file 'database.txt' is not wiped out...\n");
		return;
	}
	
	DLL * temp = headptr;
	FILE * fp = fopen("database.txt","w");
	int count = 0;
	
	while(temp) {
		count++;
		fprintf(fp,"%4d %15s   %3.2f\n",temp->no,temp->name,temp->marks);
		temp = temp->next;
	}	
	sleep(1);
	printf("%d Record saved..\n",count);
	fclose(fp);
}

void read_file(void) {
	FILE * fp = fopen("database.txt","r");
	if(fp==0) {
		printf("NO file found..\n");
		return;
	}
	DLL *new,*last;
	
	while(1) {
		new = (DLL *)malloc(sizeof(DLL));
		
		if(fscanf(fp,"%d%s%f",&new->no,new->name,&new->marks)==EOF)
			break;
		new->next = 0;
		if(headptr == NULL){
			headptr  = new;
			new->prev = 0;
		}
		else {
			last = headptr;
			while(last->next)
				last = last->next;
			last->next = new;
			new->prev = last;
		}
	}
	fclose(fp);
	
}

void delete_all(void) {
	DLL * del;
	
	int count = count_nodes();
	if(headptr == NULL) {
		printf("No records found..\n");
		return;
	}
	del = headptr;
	
	while(del){
		headptr = del->next;
		free(del);
		del = headptr;	
	}
	sleep(1);
	printf("%d Records deleted..\n\n",count);
}

void print_recursion(DLL *ptr) {
	static int flag = 0;
	if((headptr == 0)&&(flag==0)) {
		printf("\nNo records found..\n");
		return;
	}
	
	
	if(ptr) {
		flag = 1;
		printf("%4d %15s %3.2f\n",(ptr)->no,(ptr)->name,(ptr)->marks);
		print_recursion((ptr)->next);
	}
}

void reverse_print_recursion(DLL *ptr) {
	static int flag = 0;
	if((headptr == 0)&&(flag==0)) {
		printf("\nNo records found..\n");
		return;
	}
	
	
	if(ptr) {
		flag = 1;
		reverse_print_recursion((ptr)->next);
		printf("%4d %15s %3.2f\n",(ptr)->no,(ptr)->name,(ptr)->marks);
	}
}


void delete_node(void) {
	if(headptr == NULL) {
		printf("No records found..\n");
		return;
	}
	int rollno;
	DLL *del = headptr, *last;
	printf("Enter a rollno which you want to delete..\n");
	scanf("%d",&rollno);
	
	while(del) {
		if((del->no)==rollno) {
			if(del->no == headptr->no) {
				headptr = headptr->next;
			}
			else {
				if(del->next)
					del->next->prev = last;
				last->next =del->next;
			}
			free(del);
			break;
		}
		last = del;
		del = del->next;
	}
	if(del==0)
		printf("%d has not found..\n",rollno);
}

void delete_pos(void) {
	if(headptr==0) {
		printf("NO RECORDS FOUND..\n");
		return;
	}
	int pos,count;
	DLL *del,*last;
	del = headptr;
	count = count_nodes();
	label:
	printf("Enter the position you want to delete...:   ");
	scanf("%d",&pos);
	if(pos>=1&&pos<=count) {
		for(int i=1;i<=count;i++) {
			if(i==pos) {
				if(pos==1) {
					headptr = headptr->next;
				}
				else {
					last->next = del->next;
					if(del->next)
						del->next->prev = last;	
				}
			}
			last = del;
			del = del->next;
		}
	}
	else {
		printf("Wrong position has been entered..\n");
		printf("Do you want to enter again..  :");
		char ch;
		scanf(" %c",&ch);
		if(ch == 'y' || ch=='Y')
			goto label;
		else {
			printf("You bloody bastard...\n");
			return;
		}
	}
	
}











































