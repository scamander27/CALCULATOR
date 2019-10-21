#include<pic.h>
void delay(int x)
{
    while(x--);
}
void command();
void data();
void enable();
int input();
void reset_lcd();
char input2();
void main()
{
	int i,x,j=0,y,q,n1,n2;
	float p;
	char z;
    int b[10]={48,49,50,51,52,53,54,55,56,57};
	char a1[12]={"Enter no.1:"};
	char a2[12]={"Enter no.2:"};
	char a4[5]={"Sum="};
	char a5[6]={"diff="};
	char a6[10]={"product="};
	char a7[10]={"division="};
	char bc[]={"0123456789"};
	char a3[10]={"Enter opt:"};
	TRISC=0x00;
    TRISB=0x00;
	PORTC=0x00;
	TRISD=0x0F;
	PORTD=0X00;

	reset_lcd();
	while(1)
	{
		for(i=0;i<12;i++)
		{
			PORTC=0x80+i;
			command();
			PORTC=a1[i];
			data();
		}
		x=input();
		reset_lcd();
		n1=x;
		delay(1000);
		reset_lcd();
		for(i=0;i<12;i++)
		{
			PORTC=0x80+i;
			command();
			PORTC=a2[i];
			data();
		}
		y=input();
		reset_lcd();
		n2=y;
		delay(1000);
		reset_lcd();

		for(i=0;i<10;i++)
		{
			PORTC=0x80+i;
			command();
			PORTC=a3[i];
			data();
		}
		z=input2();	
		delay(1000);
		reset_lcd();	
		if(z=='+')
		{
			for(i=0;i<4;i++)
			{
				PORTC=0x80+i;
				command();
				PORTC=a4[i];
				data();
			}
			q=n1+n2;
			j=0;
			while(q!=0)
			{
				i=q%10;
				q=q/10;
				PORTC=0x88-j;
				command();
				PORTC=bc[i];
				data();
				j++;
			}
			while(1);
		}
		else if(z=='-')
		{
			for(i=0;i<5;i++)
			{
				PORTC=0x80+i;
				command();
				PORTC=a5[i];
				data();
			}
			q=n1-n2;
			if(n2>n1)
			{
				PORTC=0x86;
				command();
				PORTC='-';
				data();
				q=(-1)*q;
			}
			j=0;
			if(q==0)
			{
				PORTC=0x88;
				command();
				PORTC='0';
				data();
			}
			while(q!=0)
			{
				i=q%10;
				q=q/10;
				PORTC=0x88-j;
				command();
				PORTC=bc[i];
				data();
				j++;
			}	
			while(1);
		}
		else if(z=='*')
		{
			for(i=0;i<9;i++)
			{
				PORTC=0x80+i;
				command();
				PORTC=a6[i];
				data();
			}
			q=n1*n2;
			j=0;
			while(q!=0)
			{
				i=q%10;
				q=q/10;
				PORTC=0x8D-j;
				command();
				PORTC=bc[i];
				data();
				j++;
			}
			while(1);
		}
		else if(z=='/')
		{
			for(i=0;i<9;i++)
			{
				PORTC=0x80+i;
				command();
				PORTC=a7[i];
				data();
			}
				p=(float)n1/n2;
				p=p*100;
				q=(int)p;
				j=0;
				while(q!=0)
				{
					if(j==2)
					{
						PORTC=0x8E-j;
						command();
						PORTC='.';
						data();
						j++;
					}
					else
					{	
						i=q%10;
						q=q/10;
						PORTC=0x8E-j;
						command();
						PORTC=b[i];
						data();
						j++;
					}
				}
				if(j==2)
				{
						PORTC=0x8E-j;
						command();
						PORTC='.';
						data();
						j++;		
						PORTC=0x8E-j;
						command();
						PORTC='0';
						data();
						j++;			
				}
				while(1);
		}
		while(1);
	}
}
void command()
{
	RB6=0;
	enable();
}
void data()
{
	RB6=1;
	enable();
}
void enable()
{
	RB7=1;
	delay(100);
	RB7=0;
	delay(100);
}			
int input()
{
		int j=0,s,q,x,p;
		int str[5];
		int bc[]={0,1,2,3,4,5,6,7,8,9};
		int b[10]={48,49,50,51,52,53,54,55,56,57};
        while(1)
        {
			
        	RD6=0;RD4=1;RD5=0;
       	 	if(RD0==1)
			{
           		PORTC=0x8C+j;
				command();
				x=b[1];
				PORTC=b[1];
				data();
				delay(500);
				str[j]=bc[1];
				j++;
				while(RD0==1);
				if(j==2)
				{
					break;
				}	
			}
			else if(RD1==1)
			{
				PORTC=0x8C+j;
				command();
				x=b[4];
				PORTC=b[4];
				data();
				delay(500);
				str[j]=bc[4];
				j++;
				while(RD1==1);
				if(j==2)
				{
					break;
				}
			}
			else if(RD2==1)
			{
				PORTC=0x8C+j;
				command();
				x=b[7];
				PORTC=b[7];
				data();
				delay(500);
				str[j]=bc[7];
				j++;
				while(RD2==1);
				if(j==2)
				{
					break;
				}
			}
            RD4=0;RD5=1;RD6=0;
			if(RD0==1)
			{
           		PORTC=0x8C+j;
				command();
				x=b[2];
				PORTC=b[2];
				data();
				delay(500);
				str[j]=bc[2];
				j++;
				while(RD0==1);
				if(j==2)
				{
					break;
				}
			}
			else if(RD1==1)
			{
				PORTC=0x8C+j;
				command();
				x=b[5];
				PORTC=b[5];
				data();
				delay(500);
				str[j]=bc[5];
				j++;
				while(RD1==1);
				if(j==2)
				{
					break;
				}
			}
			else if(RD2==1)
			{
				PORTC=0x8C+j;
				command();
				x=b[8];
				PORTC=b[8];
				data();
				delay(500);
				str[j]=bc[8];
				j++;
				while(RD2==1);
				if(j==2)
				{
					break;
				}
			}
            else if(RD3==1)
			{
				PORTC=0x8C+j;
				command();
				x=b[0];
				PORTC=b[0];
				data();
				delay(500);
				str[j]=bc[0];
				j++;
				while(RD3==1);
				if(j==2)
				{
					break;
				}
			}
            RD5=0;RD6=1;RD4=0;
			if(RD0==1)
			{
           		PORTC=0x8C+j;
				command();
				x=b[3];
				PORTC=b[3];
				data();
				delay(500);
				str[j]=bc[3];
				j++;
				while(RD0==1);
				if(j==2)
				{
					break;
				}
			}
			else if(RD1==1)
			{
				PORTC=0x8C+j;
				command();
				x=b[6];
				PORTC=b[6];
				data();
				delay(500);
				str[j]=bc[6];
				j++;
				while(RD1==1);
				if(j==2)
				{
					break;
				}
			}
			else if(RD2==1)
			{   
				PORTC=0x8C+j;
				command();
				x=b[9];
				PORTC=b[9];
				data();
				delay(500);
				str[j]=bc[9];
				j++;
				while(RD2==1);
				if(j==2)
				{
					break;
				}
			}	
			else if(RD3==1&&j==1)
			{
				while(RD3==1);
				break;
			}	
		}
		q=str[0];
		if(j==1)
		{
			s=q;
			q=0;
		}
		else
		{
			s=str[1];
		}
		x=(s)+(q)*10;
		return x;

}
void reset_lcd()
{
	PORTC=0x01;
	command();
	PORTC=0x0C;
	command();
	PORTC=0x38;
	command();
}
char input2()
{
	char e[]={"+-*/"};
	char z;
	while(1)
	{
	RD4=0;RD7=1;
	if(RD0==1)
	{
		PORTC=0x8B;
		command();
		z=e[0];
		PORTC=e[0];
		data();
		delay(500);
		break;
	}
	else if(RD1==1)
	{
		PORTC=0x8B;
		command();
		z=e[1];
		PORTC=e[1];
		data();
		delay(500);
		break;	
	}
	else if(RD2==1)
	{
		PORTC=0x8B;
		command();
		z=e[2];
		PORTC=e[2];
		data();
		delay(500);
		break;
	}
	else if(RD3==1)
	{
		PORTC=0x8B;
		command();
		z=e[3];
		PORTC=e[3];
		data();
		delay(500);
		break;
	}
	} 	
	return z;				
}

		
		