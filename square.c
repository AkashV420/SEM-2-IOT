__asm__ int my_sqrt(int x)
{
  PUSH {r4-r7}
	MOV r2,#0x0   ;a
	MOV r3,r0 ;a
	//MOV r1,#1   ;c
	MOV r4,#0    ;temp
	
LOOPS
	// MOV r4,r1   ;cold=c
	 ADD r4,r2,r3
	 ASRS r4,r4,#1
	 MUL r5,r4,r4
	 ADD r6,r4,#1
	 MUL r7,r6,r6
	 CMP r5,r0
	 BEQ RETURNING
	 BLT CHECK
	 SUBGT r3,r4,#1
	 MOV r4,r2
	 CMP r2,r3
	 BLE LOOPS
	 mov r0,r4
	 POP {r4-r7};
	 BX LR   ;MOV pc,R14

CHECK
	 CMP r7,r0
	 BGT RETURNING
	 ADD r4,r4,#1
	 MOV r2,r4
	 CMP r2,r3
	 BLE LOOPS
	 MOV r0,r4
	 POP {r4-r7};
	 BX LR   ;MOV pc,R14
	 
	 
RETURNING
		mov r0,r4
		POP {r4-r7};
	  BX LR   ;MOV pc,R14
}

int sqrt(int x)
{
	 int min = 0;
	 int max = x;
	 int mid = min+max;
	 mid /= 2;
	while(min<=max)
	{
		mid = min+max;
		mid /= 2;
		if(mid*mid < x)
		{
     if((mid+1)*(mid+1) > x)
		{	
		    return mid;
		}
		else
		{
		    min = mid+1;
		}
		}
		else if(mid * mid > x)
		{
			max = mid - 1;
		}
	}
	return mid;
}

int main(void)
{
	volatile int r,j=0;
	int i;
	r = my_sqrt(0);
	r = my_sqrt(65535);
	r = my_sqrt(133);
	r = my_sqrt(0);  //should be 0
	r = my_sqrt(25); //should be 5
	r = my_sqrt(121); //should be 11
   
	
	for(i=0;i<10000;i++)
	{
		r = my_sqrt(i);
		j+=r;
	}
	
	while(1)
		;
}



































