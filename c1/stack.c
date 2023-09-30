#include<stdio.h>
int a[100],s,i,n,top=-1,item;
void push();
void pop();
void display();
int main()
{
   printf("******STACK OPERATIONS******\n");
   printf("enter the limit:\n");
   scanf("%d",&n);
     do
      {
        printf("\n Stavck operations");
        printf("\n 1.push \n 2.pop \n 3.display \n 4.exit");

        printf("\n Enter your choice:\n");
        scanf("%d",&s);

           switch(s)
             {
               case 1 :push();
               break;

               case 2 :pop();
               break;

               case 3:display();
               break;

               case 4:
               break;
 
               default:printf("\n not a choice ");
             }
      }
   while (s!=4);
   return 0;
}
void push()
{
    if(top==n-1)
    
    printf("\nStack is OVERFLOW\n");
    
    else
    
    printf("\n Enter the element to PUSH:\n");
    scanf("%d",&item);
    
    top=top+1;
    a[top]=item;
}
void pop()
{
   if(top==-1)
   
   printf("\nStack is UNDERFLOW\n");
   
   else
   
   top=top-1;
}
void display()
{
  if(top==-1)
  
  printf("\n Stack ois UNDERFLOW\n");
  
  else
  
  printf("******The stack is******\n");
  
  for(i=0;i<=top;i++)
  
  printf("%d\t",a[i]);
  
}  
  
      

