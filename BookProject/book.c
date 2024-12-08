#include<string.h>
#include<stdio.h>
#include<stdlib.h>

typedef struct Book{
	int bId;
	char bName[50];
	float price;
	float rating;
	char author[50];
	char category[50];
	
}Book;

Book* isFull(Book*,int);

int idx=0;
int size=1;



void main(){

	int ch;
	
	Book* brr = (Book*)malloc(sizeof(Book) * size);
		
	do{
		ch=choice();
		
		
	switch(ch){
		case 1:
			addB(brr);	
			break;
			
		case 2:
			disp(brr);
			break;
		
		case 3:
			search(brr);
			break;
		case 4:
			update(brr);
			break;
		case 5:
			removeB(brr);
			break;
		case 6:
			sort(brr);
			break;
		case 7:
			top3Books(brr);
			break;
			
		}
		
		

		
	}while(ch!=8);
	
	printf("\nExited!!!!!!!!!!!!!!");
}


//Menu on Console
int choice(){
    int ch = 0;

    printf("\n=====================================");
    printf("\n|            BOOK MANAGER           |");
    printf("\n=====================================");
    printf("\n|           MAIN MENU               |");
    printf("\n-------------------------------------");
    printf("\n| 1. Add Book                       |");
    printf("\n| 2. Display All Books              |");
    printf("\n| 3. Search Book (ID, Name, Author) |");
    printf("\n| 4. Update Book                    |");
    printf("\n| 5. Remove Book                    |");
    printf("\n| 6. Sort Books                     |");
    printf("\n| 7. Show Top 3 Books               |");
    printf("\n| 8. Exit                           |");
    printf("\n-------------------------------------");
    printf("\nPlease select an option (1-8): ");
    scanf("%d", &ch);

    return ch;
}



//Add books
void addB(Book* b)
{
	int usize;
	printf("\nHow many books you want to store : ");
	scanf("%d",&usize);
	
		
	
		if(size<usize || size<(idx+usize)){
			b=isFull(b,usize);
		}
	
	int i=0;
	for(;i<usize;idx++,i++){
		printf("\n----------------------------------------");
 		printf("\nEnter The Book id : ");
 		scanf("%d",&b[idx].bId);	
 
		fflush(stdin);
 		printf("\nEnter the book name : ");
 		gets(b[idx].bName);
 
 		printf("\nenter the book price : ");
 		scanf("%f",&b[idx].price);
 
 		printf("\nenter the book rating : ");
 		scanf("%f",&b[idx].rating);
 		fflush(stdin);
 		printf("\nenter the book author : ");
 		gets(b[idx].author);
 		
 		fflush(stdin);
 		printf("\nenter the book category : ");
 		gets(b[idx].category);
 
 }

 
}

//Display All Books
void disp(Book* b) {

    if (idx == 0) {
        printf("\nNo books available to display.\n");
        return;
    }

    // Header
    printf("\n==============================================================");
    printf("\n| %-5s | %-20s | %-10s | %-10s | %-15s |", "ID", "Name", "Price", "Rating", "Author");
    printf("\n==============================================================");

    // Book details in tabular format
    int i = 0;
    for (; i < idx; i++) {
        printf("\n| %-5d | %-20s | %-10.2f | %-10.2f | %-15s |", 
                b[i].bId, b[i].bName, b[i].price, b[i].rating, b[i].author);
    }

    // Footer
    printf("\n==============================================================");
    printf("\nTotal Books: %d\n", idx);
}


//For searching Books
void search(Book* b){
	
	int ch;
	
	
	printf("\nChoose among the options for search:");
	printf("\n1)ID\n2)Name\n3)author : ");
	scanf("%d",&ch);
	
	int flag=0;
	if(ch==1){
		int id;
		printf("\nEnter Book ID");
		scanf("%d",	&id);	
		int i=0;
		for(;i<idx;i++){
			if(b[i].bId==id){
				dispB(b,i);
				flag++;
			
			}
			
		}
		
		
	}else if(ch==2){
			char nm[50];
			fflush(stdin);
		printf("\nEnter Book name : ");
		gets(nm);	
		int i=0;
		for(;i<idx;i++){
			if(strcmp(nm,b[i].bName)==0){
				dispB(b,i);
				flag++;
			
			}
			
		}
		
	}else if(ch==3){
		char nm[50];
		fflush(stdin);
		printf("\nEnter Book author : ");
		gets(nm);	
		int i=0;
		for(;i<idx;i++){
			if(strcmp(nm,b[i].author)==0){
				dispB(b,i);
				flag++;
			
			}
			
		}
		
		
	}
	
	if(flag==0){
		printf("\nBook Not Found!!!");
	}
	

	
}


//Display specific Book
void dispB(Book* b,int i){
	
	printf("\n----------------------------------------");
		printf("\nBook Id - %d ",b[i].bId);
		printf("\nBook Name - %s ",b[i].bName);
		printf("\nBook Price - %f ",b[i].price);
		printf("\nBook rating - %f ",b[i].rating);
		printf("\nBook Author - %s ",b[i].author);
		printf("\nBook Category - %s ",b[i].category);
	
	
	
}

//Update Book
void update(Book* b){
	int ch;
	int id;
	printf("\n Enter the book ID for update : ");
	scanf("%d",&id);
	int i=0,j=-1;
		for(;i<idx;i++){
			if(b[i].bId==id){
				j=i;
			
			}
			
		}
		if(j==-1){
			printf("Invalid Book ID");
			return;
		}
	
	printf("\nwhat you want to update from following :");
	printf("\n1]price");
	printf("\n2]rating ");
	scanf("%d",&ch);
	float newp;
	float newrat;
	switch(ch){
		case 1:
			printf("preivous price : %f",b[j].price);
			printf("\nEnter new price : ");
			scanf("%f",&newp);
			b[j].price=newp;
			break;
		case 2:
			printf("preivous rating : %f",b[j].rating);
			printf("\nEnter new rating :");
			scanf("%f",&newrat);
			b[j].rating=newrat;
			break;
	}
	
	printf("\nBook Updated!!!!!!!!!!!!");
	
}

//Remove Book 
void removeB(Book* b){
	int id;
	printf("\n Enter the book ID for remove : ");
	scanf("%d",&id);
	int i=0,j=-1;
		for(;i<idx;i++){
			if(b[i].bId==id){
				j=i;
				break;
			
			}
			
		}
		if(j==-1){
			printf("Invalid Book ID!!!!!!!!!!!!!!!!!!!!");
			return ;
		}
		
		for(;j<idx;j++){
			b[j]=b[j+1];
		}
		printf("\nBook removed !!!!!!!!!!!!!!!!!!!!!");
		idx--;

}


//To resize the Structure Array
Book* isFull(Book*  b,int usize){
	Book* temp=NULL;

		size=size+(usize);

		temp=(Book*) realloc(b,sizeof(Book)*size);
		
		
	if(temp!=NULL){
		return temp;
	}
	else{
		printf("\n insufficent storage!!!!!!");
		return b;
	}
		
	
	
	return b;
	
	
	
}

//sort Books choices
void sort(Book* b){
	int ch;
	printf("\nChoose among the options for sorting books:");
	printf("\n1)Rating\n2)Price");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			sortByRating(b);
			printf("\nSuccsesfully Sorted by Rating !!!!!!!!!!!!!!!");
			break;
		case 2:
			sortByPrice(b);
			printf("\nSuccsesfully Sorted by Price !!!!!!!!!!!!!!!");
			break;
		default :
			printf("\n Invalid choice!!!!!!");
					
	}
	
	
}


//sort Books by rating
void sortByRating(Book* b){
	
	int i=0;
	for(;i<idx;i++){
		int j=i+1;
		for(;j<idx;j++){
			if(b[i].rating<b[j].rating){
				Book temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
			
		}
	}
}


//Sorting Books by price
void sortByPrice(Book* b){
	int i=0;
	for(;i<idx;i++){
		int j=i+1;
		for(;j<idx;j++){
			if(b[i].price>b[j].price){
				Book temp=b[i];
				b[i]=b[j];
				b[j]=temp;
			}
			
		}
	}
	
}


//Display Top 3 books
void top3Books(Book* b){
	int ch;
	printf("\nChoose among the options for filter top 3 books:");
	printf("\n1)By Rating\n2)By Price");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			sortByRating(b);
			break;
		case 2:
			sortByPrice(b);
			break;
					
	}
	
	int i=0;
	for(;i<3;i++){
		printf("\n----------------------------------------");
		printf("\nBook Id - %d",b[i].bId);
		printf("\nBook Name - %s",b[i].bName);
		printf("\nBook Price - %f",b[i].price);
		printf("\nBook Rating - %f",b[i].rating);
		printf("\nBook Author - %s",b[i].author);
		printf("\nBook Category - %s",b[i].category);
	
	}
	
	
	
}