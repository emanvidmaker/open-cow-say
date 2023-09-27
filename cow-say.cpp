/* open cow-say, an Opensource alternative to cowsay by Emanvidmaker
  ___
< moo >
  ---
      \   ^__^
       \  (oo)\_______
          (__)\       )\/\
              ||----w |
              ||     ||
---------------------------
open-cow-say, an open-source alternative to cowsay
*/

/*still questioning the C like coding in this C++*/ 

#include <iostream>

void place(const int n, const char c){
    if (n <= 0) return;
    
    std::cout << c; 
    place(n-1, c);
    
    return;   
}

void place(const int n = 1) {place(n, 32);};

void draw_cow(const int& length, const std::string& cowSays)
{
	int i, j; 
	int repeat[]={3, 4, 7, 11, 11, 24};
	char a, b, c; 
	
	int cow[6][20]=
	{
	    {0x5c, 0x20, 0x20,  0x20, 0x5e, 0x5f,  0x5f, 0x5e, 0x20, 0xea},
		{0x5c, 0x20, 0x20,  0x28, 0x6f, 0x6f,  0x29, 0x5c, 0x5f, 0x5f, 
		 0x5f, 0x5f, 0x5f,  0x5f, 0x5f, 0xea},{0x28, 0x5f, 0x5f, 0x29, 
		 0x5c, 0x20, 0x20,  0x20, 0x20, 0x20,  0x20, 0x20, 0x29, 0x5c, 
		 0x2f, 0x5c, 0xea},{0x7c, 0x7c, 0x2d,  0x2d, 0x2d, 0x2d, 0x77, 
		 0x20, 0x7c, 0xea},{0x7c, 0x7c, 0x20,  0x20, 0x20, 0x20, 0x20, 
		 0x7c, 0x7c, 0xea},{0xea, 0xea, 0xea,  0xea, 0xea, 0xea, 0xea}
	};
	
	a = 0x3c; 
	b = 0x20; 
	c = 0x3e; 
	
	place(2);
    place(length, 0x5f);
    std::cout << std::endl << a << b << cowSays << b << c << std::endl;
    place(2);
    place(length, 0x2d);
    std::cout << std::endl;
	
	for (i = 0; i < 6; ++i)
	{
		place(length + repeat[i], (repeat[i] > 0x17) ? 0x2d : 0x20);
		
		for(j = 0; cow[i][j] != 0xea; ++j)
		{
			std::cout << (char)cow[i][j]; 
		}
		
		if (j > 0)
			std::cout << std::endl; 
	}
}

int main(int argCount,char *argv[]) {
    
    std::string cowSays = "";
    
    if (argCount-1 <= 0) {
        cowSays = "moo";
    } else {
        for (int i = 1; i < argCount; i++)
        {
            cowSays += argv[i];
            if (i < argCount-1){
                cowSays += ' ';
            }
        }
    }
    
    int length = cowSays.length();

	draw_cow(length, cowSays); 

    std::cout << "\nopen-cow-say, an open-source alternative to cowsay"<< std::endl;

   return 0;
}

