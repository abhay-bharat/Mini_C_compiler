#include <stdio.h>

int main()
{

	// int a = 1;
	// int b = 10;
	// {
	// 	int p;
	// }
	// p = a;
	// a = b*2;
	//eg. for deadcode elimination, first deadcode to be removed and then constant propagation is done
	// int a;
	// int b = 10;
	// a = b*2;
	// b = 100;
	// a = 10;
	// b = b*a;
	/////////////////

	//eg. for constant propagation and constant folding
        int i = 5;
        int j = 10;
       if(i == 5)
       {
               i = 1;
       }
        ++j;
    /////////////////////////////

    //eg. for deadcode elimination
    // int a = 10;
    // int b = 20;
    // a = 100;
    /////////////////////////////
	//eg. for constant propagation
	// int a = 10;
	// int b = 20;
	// a = a + b;
	/////////////////////////////

	//eg. for constant folding
	// int a = 11;
	// int b = a/2;
	////////////////////////////
}

