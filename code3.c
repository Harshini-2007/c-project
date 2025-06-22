#include <stdio.h>
#include<string.h>
#include<stdlib.h>
// Feedback structure
struct feedback {
    int food;
    int Service;
    int overallExperience;
    char*otherFeedback;
};

// Function declarations
void menu ();
void takingOrder(int quantity[13]);
void bill (int quantity[13],char allfood[][30],int allprice[13]);
void feedbackRating(struct feedback *f); 

int main() {
struct feedback f;
int  quantity[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};  
char allfood[13][30]={ "Idli", "Dosa", "Pongal", "Chapati",
    "Paneer Rice", "Mushroom Fried Rice", "Fried Rice", "Pulao", "Curd Rice", 
    "Ice Cream", "Milkshake", "Tea", "Coffee"};
int allprice[13]={30, 40, 35, 20, 110, 100, 90, 85, 60,50, 60, 10, 15};
int n=0;  
do{
printf("Taking order \n View the menu below\n");
menu();
takingOrder(quantity);
printf("If you want anything further then press 1 or press 0 and the bill will be generated \n");
scanf("%d",&n);
}while(n!=0);
bill(quantity,allfood,allprice);
int h=0;
printf("kindly press 1 to give feedback\n");
   scanf("%d",&h);
   feedbackRating(&f);
    return 0;
}

// Menu function
void menu() {
FILE * fp;
if (fp == NULL) {
        printf(" ERROR: Could not open feedbackhistory.txt for writing.\n");
        return;
    }
char line[100];
fp=fopen("Resturantmenu.txt","r");
while(fgets(line,sizeof(line),fp)!=NULL){
    printf("%s",line);
}
printf("\n");
fclose(fp);
     
}


//taking order
void takingOrder(int quantity[13]){ 
int n=0;
printf("Enter total number of items to order\n");
scanf("%d",&n);
int s=0;
for(int k=0;k<n;k++){
    int q=0;
     printf("Enter the serial number of item from menu\n");
     scanf("%d",&s);
     if(quantity[s-1]==0){
     printf("Enter the quantity of item\n");
     scanf("%d",&quantity[s-1]);}
     else{ printf("Enter the quantity of item\n");
          scanf("%d",&q);
          quantity[s-1]+=q;
}
}
printf("Order has been placed\n");
   } 

   //billing
   void bill (int quantity[13],char allfood[][30],int allprice[13]){
    int total= 0;
    printf ("Bill\n");
    printf("-----------\n");
  for(int a=0;a<13;a++){
    if(quantity[a]!=0){
        printf("%s: %d\n",allfood[a],allprice[a]*(quantity[a]));
        total+=allprice[a]*(quantity[a]);
    }
  }
  printf("Total bill:%d\n",total);
 
}
// Feedback function

   void feedbackRating(struct feedback *f) {
    // Open file in append mode
    FILE *f1 = fopen("feedbackhistory.txt", "a");
    if (f1 == NULL) {
        printf(" ERROR: Could not open feedbackhistory.txt for writing.\n");
        return;
    }
    // Take feedback ratings
    printf("Rate the food on a scale of 5: ");
    scanf("%d", &f->food);

    printf("Rate the service on a scale of 5: ");
    scanf("%d", &f->Service);

    printf("Rate the overall experience on a scale of 5: ");
    scanf("%d", &f->overallExperience);
   int o=0;
    // Optional comment
    printf("Do you want to give any other feedback? (1 = Yes / 0 = No): \n");
    scanf("%d", &o);
    while (getchar() != '\n'); 

    if (o == 1) {
        printf("Enter your feedback: \n");
        char user[100];

        fgets(user, sizeof(user), stdin);
        f->otherFeedback=(char*)calloc(strlen(user)+1,sizeof(char));
        strcpy(f->otherFeedback,user);
    }

    
    fprintf(f1, "\n--- FEEDBACK ENTRY ---\n");
    fprintf(f1, "Food: %d\n", f->food);
    fprintf(f1, "Service: %d\n", f->Service);
    fprintf(f1, "Experience: %d\n", f->overallExperience);
    if (o == 1) {
        fprintf(f1, "Other Comments: %s", f->otherFeedback); 
    }
    fprintf(f1, "------------------------\n");

    fclose(f1);
    printf(" Feedback saved successfully to feedbackhistory.txt\n");
    free(f->otherFeedback);
}




