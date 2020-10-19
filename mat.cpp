#include<bits/stdc++.h>
using namespace std;
void get(int *arr[],int r,int c)
{  
	for(int i=0;i<r;i++)
     {
          arr[i] = new int[c];
      for(int j=0;j<c;j++)
       {
         arr[i][j]=rand()%10;
        }
   }
}
void out(int *arr[],int r,int c)
{  
	for(int i=0;i<r;i++)
   {
    for(int j=0;j<c;j++)
    {
      cout<<arr[i][j]<<"  ";
    }
    printf("\n");
   }
}

void matmul_div_rec(int *a[],int *b[],int *c[],
               int ra1,int ra2,int ca1,int ca2,
			   int rb1,int rb2,int cb1,int cb2
			 
			   )
{ 

   if((ca2-ca1)==0&&(ra2-ra1)==0&&(cb2-cb1)==0&&(rb2-rb1)==0)
  {
  
    c[ra1][cb1]+=a[ra1][ca1]*b[rb2][cb2];
	return;}

   if(((ca2-ca1)==1||(ra2-ra1)==1)||((cb2-cb1)==1||(rb2-rb1)==1))
	{ 
	
	for(int i=ra1;i<=ra2;i++)
	{
		for(int j=cb1;j<=cb2;j++)
		{
			
			for(int k=ca1;k<=ca2;k++)
			{
				c[i][j]+=a[i][k]*b[k][j];
				
			}
		}
	}
	 return ;
    }
           matmul_div_rec(a,b,c,                                //1.1
			                ra1,(ra2+ra1)/2,ca1,(ca1+ca2)/2,
						rb1,(rb2+rb1)/2,cb1,(cb1+cb2)/2);
           matmul_div_rec(a,b,c,                                 //1.2
			                ra1,(ra2+ra1)/2,(ca1+ca2)/2+1,ca2,
						 (rb2+rb1)/2+1,rb2,cb1,(cb1+cb2)/2);
           matmul_div_rec(a,b,c,                                    //2.1
			               ra1,(ra2+ra1)/2,ca1,(ca1+ca2)/2, 
						  rb1,(rb2+rb1)/2,(cb1+cb2)/2+1,cb2);
           matmul_div_rec(a,b,c,                                      //2.2
			                ra1,(ra2+ra1)/2,(ca1+ca2)/2+1,ca2,
							(rb2+rb1)/2+1,rb2,(cb1+cb2)/2+1,cb2);
           matmul_div_rec(a,b,c,                                   //3.1
			                (ra2+ra1)/2+1,ra2,ca1,(ca1+ca2)/2,
						rb1,(rb2+rb1)/2,cb1,(cb1+cb2)/2);
           matmul_div_rec(a,b,c,                                   //3.2
			                 (ra2+ra1)/2+1,ra2,(ca1+ca2)/2+1,ca2,
						(rb2+rb1)/2+1,rb2,cb1,(cb1+cb2)/2);
           matmul_div_rec(a,b,c,                                   //4.1
			                (ra2+ra1)/2+1,ra2,ca1,(ca1+ca2)/2,
						 rb1,(rb2+rb1)/2,(cb1+cb2)/2+1,cb2);
           matmul_div_rec(a,b,c,                                        //4.2
			                (ra2+ra1)/2+1,ra2,(ca1+ca2)/2+1,ca2,
							(rb2+rb1)/2+1,rb2,(cb1+cb2)/2+1,cb2);
		
	
}


int main()
{
		clock_t start,end;
	 
	int r1,r2,c1,c2;
x:	cout<<"enter no of rows and col of a"<<endl;
	cin>>r1>>c1;
	cout<<"enter no of rows and col of b"<<endl;	
	cin>>r2>>c2;
	if(c1!=r2){
		cout<<"wrong inputs"<<endl;
		goto x;	}
srand(time(0));
int *a[r1],*b[r2], *c[r1];

	for(int i=0;i<r1;i++)
     {
          a[i] = new int[c1];
          for(int j=0;j<c1;j++)
          {
          	 a[i][j]=rand()%10;
		  }
	 }

    for(int i=0;i<r2;i++)
     {
          b[i] = new int[c2];
          for(int j=0;j<c2;j++)
          {
          	 b[i][j]=rand()%10;
		  }
	 }
    for(int i=0;i<r1;i++)
     {
          c[i] = new int[c2];
          for(int j=0;j<c2;j++)
          {
          	 c[i][j]=0;
		  }
	 }
    start=clock();
	matmul_div_rec(a,b,c,0,r1-1,0,c1-1,0,r2-1,0,c2-1); 
	end=clock();
		cout<<"A is"<<endl;
out(a,r1,c1);
cout<<"B is"<<endl;
out(b,r2,c2);
cout<<endl;
cout<<"Answer is"<<endl;
out(c,r1,c2);
cout<<endl<<endl<<endl<<((double)(end-start))/CLOCKS_PER_SEC;
}
