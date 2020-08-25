#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
struct menu{
int quantity,items;
};
struct newAccount{
char accName[20];
int accNumber;
float balance;
};
struct accLogin
{
    char userID[20];
    char userName[20],p[20];
    float balance;
};
struct order {
		long int transactionID;
    	char userID[20];
    	char userName[20];
    	int orderedItems[12];
    	float total;
    	
	};
void displayMenuList();
void orderFood(struct accLogin);
void displayOrder(struct order);
void writeOrder(struct order );
void adminLogin(struct accLogin );
void newAccount(void);
void displayAccount(void);
int i,found;
void accountPay();
void payBill();
void customerLogin(struct accLogin);
void balanceUpdate(float , char[20]);
void viewSpecificOrder(long int );
long int getTransactionID();
	float *currentBalance;
	long int ID;


void main()
{
	struct accLogin login;
    FILE *ptr;
	ptr=fopen("userName.txt","rb");
	char userID[20],pwrd[20],p1[20],c;
	int i,j=0;
	while(1){
	system("cls");
	printf("Enter User ID : ");
	scanf("%[^\n]",&userID);
	printf("Enter Password : ");
	fflush(stdin);
	for(i=0;i<8;i++)
    {
        c=getch();
        pwrd[i]=c;
        c='*';
        printf("%c",c);
    }
    pwrd[i]='\0';
    getch();
    found=0;
    //char a[20]={"55300"};
	while((fread(&login,sizeof(login),1,ptr))==1){
	if(((strcmp(login.userID,userID)==0))&&strcmp(pwrd,login.p)==0){
		if(!strcmp(login.userID,"55300")){
			adminLogin(login);
		}else{
		customerLogin(login);
	}
		found=1;
		break;
	}
	}
	if(found!=1){
		printf("\nInvalid User ID or Password ");
		getch();
	}
	printf("\nDo you want to exit ?(y/n))");
	//c=getch();
	while(1){
	c=getch();	
	if(c=='y'){
		break;
	}else if(c=='n'){
		break;
	}
}if(c=='y') break;

	//getch();
	//printf("rewind");
	rewind(ptr);
	fflush(stdin);
}
	fclose(ptr);

}

void adminLogin(struct accLogin login){
while(1){
	system("cls");
	printf("\n\t\t\t Welcome Admin ");
	char log;
	printf("\n1.CREATE NEW ACCOUNT");
	printf("\n2.DISPLAY EXISTING ACCOUNT");
	printf("\n3.LOAD BALANCE ");
	printf("\n4.VIEW ALL TRANSACTIONS ");
	printf("\n5.VIEW SPECIFIC TRANSACTION ");
	printf("\n6.LOG OUT");
	printf("\nEnter number:");
fflush(stdin);
log=getch();
	if(log=='1'){
		newAccount();	
	}else if(log=='6'){
		printf("\nSuccessfully Logged Out !!");
		break;
	}else if(log=='4'){
		FILE *f;
	int i=1;
	struct order order1;
	f=fopen("recOrder.txt","rb");
	while(fread(&order1,sizeof(order1),1,f)==1){
		printf(" \n %d %li \t %s \t %s\t Rs:%f ",i,order1.transactionID,order1.userID,order1.userName,order1.total);
		i++;	
}
getch();
fclose(f);
		
	}
	else if (log=='5'){
	printf("\nEnter transaction ID : ");
	scanf("%li",&ID);
	viewSpecificOrder(ID);
	getch();
}
	else if(log=='2'){
		displayAccount();
	}else if(log=='3'){
		float a;
		char name[20];
		printf("Enter the user ID :");
		fflush(stdin);
		gets(name);
		printf("Enter balance you want to load:");
		scanf("%f",&a);
		balanceUpdate(a,name);
		printf("Balance sucessfully updated ");
		getch();
	}
	//getch();
}
}

void customerLogin(struct accLogin login)
{

	currentBalance=&login.balance;
	
while(1){	
	system("cls");
    printf(" \n\t\t\t Welcome  %s",login.userName);
    printf("\t\t Current Balance : %.2f",login.balance);
    char log;
printf("\n1.ORDER FOOD");
printf("\n2.VIEW All YOUR ORDERS");
printf("\n3.VIEW SPECIFIC ORDER");
printf("\n4.LOG OUT");
printf("\nEnter number:");
//scanf("%d",&log);

log=getch();

if(log=='1')
{ system("cls");
orderFood(login);

}else if(log=='2'){
	FILE *f;
	struct order order1;
	f=fopen("recOrder.txt","rb");
	while(fread(&order1,sizeof(order1),1,f)==1){
		if((strcmp(login.userID,order1.userID)==0)){
		printf(" \n %d %li \t %s \t %s\t Rs:%f ",i,order1.transactionID,order1.userID,order1.userName,order1.total);
	
	}
}
getch();
fclose(f);
}else if(log=='3'){
	printf("\nEnter transaction ID : ");
	scanf("%li",&ID);
	viewSpecificOrder(ID);
	getch();
}
else if(log=='4'){
	printf("\n Successfully logged out !!");
	break;
}
else
{
 //readOrder();
}
}
//getch();
}

void displayAccount(){
	system("cls");
	struct accLogin login;
	int a=1;
    FILE *ptr;
	ptr=fopen("userName.txt","rb");
	while((fread(&login,sizeof(login),1,ptr))==1){
	printf("\n%d. \t%s\t%s\t%s\t%f",a,login.userID,login.userName,login.p,login.balance);
	a++;

	}
getch();	
}

void balanceUpdate(float a, char userID[20]){
	struct accLogin login1;
    FILE *ptr;
    // FILE *ptr1;
	ptr=fopen("userName.txt","rb+");
	//ptr1=fopen("userName1.txt","wb");
	//rewind(ptr);
	while((fread(&login1,sizeof(login1),1,ptr))==1){
	//	printf("\n %s %s ",login1.userID,userID);
	//	getch();
		if(strcmp(login1.userID,userID)==0){
			fseek ( ptr, -sizeof(login1), SEEK_CUR ) ;
			login1.balance=login1.balance+a;
			fwrite(&login1,sizeof(login1),1,ptr);
			//printf("flag ");
			break;
		//	fseek ( ptr, 2*sizeof(login1), SEEK_CUR ) ;
		
		}
		//else{
		
		//fwrite(&login1,sizeof(login1),1,ptr);
		//}	
			//getch();
		
}
fclose(ptr);//fclose(ptr1);
//rename("userName1.txt","userName.txt");
}

void newAccount()
{ long int c,d,e;
	struct accLogin login;
    char ch;
    FILE *f;
    f=fopen("userName.txt","ab");
    fflush(stdin);
    system("cls");
    printf("\n\t\t\t Add new account \n");
    do
    {
        printf("Enter id :");
        scanf("%[^\n]",login.userID);
        printf("Enter name : ");
        scanf(" %[^\n]",login.userName);
        printf("Enter pewd ");
        scanf(" %[^\n]",login.p);
        printf("balance ");
        scanf(" %f",&login.balance);
        fwrite(&login,sizeof(login),1,f);
        fflush(stdin);
        printf("\n Account Successfully Added ... \n Do you want to add more accounts(y/n) ");
        ch=getch();
    }while(ch=='y');
     fclose(f);
}


void viewSpecificOrder(long int a){
	FILE *f;
	struct order order1;
	f=fopen("recOrder.txt","rb");
	while(fread(&order1,sizeof(order1),1,f)==1){
		if(order1.transactionID==a){
		displayOrder(order1);
		//break;	
	}	
}
	fclose(f);
}


void orderFood(struct accLogin login)
{
    int num ,buf,i,j,priceList[12]={70,75,110,120,210,60,45,80,300,50,25,30};
    char c,confirm;
    float total=0;
    struct order order1;
    strcpy(order1.userID,login.userID);
    strcpy(order1.userName,login.userName);
    for(i=0;i<12;i++){
    		order1.orderedItems[i]=0;
	}
	displayMenuList();
	printf("\nEnter number of product you want to order:");
    scanf("%d",&num);
	for(j=0;j<num;j++){
	printf("\nEnter the product number from menu:");
    scanf("%d",&i);
     printf("Enter the quantity:");
    scanf("%d",&buf);
    order1.orderedItems[i-1]=buf+order1.orderedItems[i-1];
}

	system("cls");
    displayMenuList();
   displayOrder(order1);
   for(i=0;i<12;i++){
    		total=total+priceList[i]*order1.orderedItems[i];
	}
	order1.total=0.9*total;
   // printf("%.2f",order1.total);
   order1.transactionID=getTransactionID();
    //getch();
   if((*currentBalance)>order1.total) {
     printf("\nDo you want to confirm your order:y/n:");
   scanf(" %c",&confirm);
   if(confirm=='y')
   {
       writeOrder(order1);
       balanceUpdate(-order1.total,order1.userID);
       *currentBalance=*currentBalance-order1.total;
       balanceUpdate(order1.total,"55300");
       //accountPay();
       printf("paid");
       getch();
   }
}else{
	printf(" \n\t Insufficient Balance !! Please contact our Employee to load Balance in your account \n\t Thank you !!");
	getch();
}
    /*printf("\nEnter number of product you want to order:");
    scanf("%d",&num);
    struct menu food[num];
    for(i=0;i<num;i++){
    printf("\nEnter the product number from menu:");
    scanf("%d",&food[i].items);
     printf("Enter the quantity:");
    scanf("%d",&food[i].quantity);
}  system("cls");
    displayMenuList();
   displayOrder(food,num);
   printf("\nDo you want to confirm your order:y/n:");
   scanf(" %c",&confirm);
   if(confirm=='y')
   {
       //writeOrder(food,num);
       //accountPay();
       printf("paid");
   }
   */
}
 void displayMenuList()
   {
        printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-MENU-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
    printf("\n1.BUFF MOMO:Rs70\t\t2.CHOWMIEN:Rs75\t\t\t3.PIZZA:Rs110\t\t4.CHOUPSEY:Rs120");
    printf("\n\n5.SIZZLER:Rs210\t\t\t6.FRIED RICE:Rs60\t\t7.FRENCH FRY:Rs45\t8.CHICKEN MOMO:Rs80");
    printf("\n\n9.SAME BAJI SET:Rs300\t\t10.VEG PAKODA:Rs50\t\t11.COKE:Rs25\t\t12.ICECREAM:Rs30\n");
    printf("-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-");
   }

long int getTransactionID(){
	struct order order1;
	FILE *f;
	f=fopen("recOrder.txt","rb");
	while(fread(&order1,sizeof(order1),1,f)==1){
		//displayOrder(order1);	
	}
	return(order1.transactionID+28795);
	fclose(f);
}


void accountPay()
{
    char acc_exist;
    printf("Do you have an account in Siddhartha bank??y/n:");
    scanf(" %c",&acc_exist);
    if(acc_exist =='y')
    {
        payBill();
    }
    else
    {
        printf("!!!CREATE YOUR NEW ACCOUNT IN SIDDHARTHA BANK--REFER TO EMPLOYEE FOR CREATING NEW ACCOUNT!!");
        printf("\nSORRY FOR THE INCONVENIENT CAUSE");
        getch();
    }
}
void payBill()
{system("cls");
    char accholder_name[20];
    int accholder_id;
    printf("Enter name of account holder:");
    fflush(stdin);
    gets(accholder_name);
    printf("Enter account number:");
    scanf("%d",&accholder_id);

}
 

void displayOrder(struct order order1)
{

	int i,j=1;
	float subTotal=0,total;
	char itemList[12][20]={"BUFF MOMO","CHOWMEIN","PIZZA    ","CHOUPSEY","SIZZLER","FRIED RICE","FRENCH FRY","CHICKEN MOMO","SAME BAJI SET","VEG PAKODA","COKE     ","ICECREAM"};
	int priceList[12]={70,75,110,120,210,60,45,80,300,50,25,30};
	printf("\n User Name :%s \t\t User ID : %s \t\t TransactionID :%li",order1.userName,order1.userID,order1.transactionID);
	printf("\n--------------------------BILL-----------------------------");
    printf("\nSN ITEMS           PRICE    \tQUANTITY   \tTOTAL PRICE");
    printf("\n------------------------------------------------------------");
    for(i=0;i<12;i++){
    	if(order1.orderedItems[i]!=0){
		
    	printf("\n%d.%s\t   %d\t\t%d\t\t%d ",j,itemList[i],priceList[i],order1.orderedItems[i],priceList[i]*order1.orderedItems[i]);
    	subTotal=subTotal+priceList[i]*order1.orderedItems[i];
    	j++;
	}
    
}
printf("\n-----------------------------------------------------------");
printf("\nTotal");
printf("\t\t\t\t\t\tRs %.2f",subTotal);
printf("\nDiscount amount");
printf("\t\t\t\t\tRs %.2f",(0.1*subTotal));
printf("\n-----------------------------------------------------------");
printf("\nGrand total");
printf("\t\t\t\t\tRs %.2f",(0.9*subTotal));
printf("\n-----------------------------------------------------------");
}

void writeOrder(struct order order1)
{
    long int c,d,e;
    FILE *fptr1;
    fptr1=fopen("recOrder.txt","ab+");
     fwrite(&order1,sizeof(order1),1,fptr1);
     printf("Paid !!");
     fclose(fptr1);
}
 
/*int total[12],total1=0;
    printf("\n--------------------------BILL-----------------------------");
    printf("\nSN ITEMS           PRICE    \tQUANTITY   \tTOTAL PRICE");
    printf("\n------------------------------------------------------------");
    for(i=0;i<num;i++)
    {if((food[i].items)<=12)
        {printf("\n");
        switch(food[i].items)
        {
        case 1:
            printf("%d.BUFF MOMO",i+1);
            printf("\t   70");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*70;
            printf("\t\t%d",total[i]);
            break;
        case 2:
            printf("%d.CHOWMEIN",i+1);
            printf("\t   75");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*75;
            printf("\t\t%d",total[i]);
            break;
        case 3:
            printf("%d.PIZZA",i+1);
            printf("\t\t   110");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*110;
            printf("\t\t%d",total[i]);
            break;
        case 4:
            printf("%d.CHOUPSEY",i+1);
            printf("\t   120");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*120;
            printf("\t\t%d",total[i]);
            break;
        case 5:
            printf("%d.SIZZLER",i+1);
            printf("\t   210");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*210;
            printf("\t\t%d",total[i]);
            break;
        case 6:
            printf("%d.FRIED RICE",i+1);
            printf("\t   60");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*60;
            printf("\t\t%d",total[i]);
            break;
        case 7:
            printf("%d.FRENCH FRY",i+1);
            printf("\t   45");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*45;
            printf("\t\t%d",total[i]);
            break;
        case 8:
            printf("%d.CHICKEN MOMO",i+1);
            printf("\t   80");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*80;
            printf("\t\t%d",total[i]);
            break;
        case 9:
            printf("%d.SAME BAJI SET",i+1);
            printf("    300");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*300;
            printf("\t\t%d",total[i]);
            break;
        case 10:
            printf("%d.VEG PAKODA",i+1);
            printf("\t   50");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*50;
            printf("\t\t%d",total[i]);
            break;
        case 11:
            printf("%d.COKE",i+1);
            printf("\t\t   25");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*25;
            printf("\t\t%d",total[i]);
            break;
        case 12:
            printf("%d.ICECREAM",i+1);
            printf("\t   30");
            printf("\t\t%d",food[i].quantity);
            total[i]=food[i].quantity*30;
            printf("\t\t%d",total[i]);
            break;
        deafult:
            printf("Please enter valid number!!!!");
            }}
            else{
             total[i]=0;
            }
}
for(i=0;i<num;i++)
{
    total1=total1+total[i];

}
printf("\n-----------------------------------------------------------");
printf("\nTotal");
printf("\t\t\t\t\t\tRs %d",total1);
printf("\nDiscount amount");
printf("\t\t\t\t\tRs %.2f",(0.1*total1));
printf("\n-----------------------------------------------------------");
printf("\nGrand total");
printf("\t\t\t\t\tRs %.2f",(0.9*total1));
printf("\n-----------------------------------------------------------");
*/

