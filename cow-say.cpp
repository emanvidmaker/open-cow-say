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
#include <iostream>
void place(int n, char c){
    if (n <= 0) return;
    else {
        std::cout << c; 
        place(n-1,c);
        return;
    }
}
void place(int n = 1) {place(n,' ');};
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
    place(2);
    place(length,'_');
    std::cout << std::endl;
    std::cout << "< " << cowSays << " >"<< std::endl;
    place(2);
    place(length,'-');
    std::cout << std::endl;
    //draw cow
    place(length+3);
    std::cout << "\\   ^__^ "<< std::endl;
    place(length+4);
    std::cout << "\\  (oo)\\_______"<< std::endl;
    place(length+7);
    std::cout << "(__)\\       )\\/\\"<< std::endl;
    place(length+11);
    std::cout << "||----w |"<< std::endl;
    place(length+11);
    std::cout << "||     ||"<< std::endl;
    place(length+24,'-');
    std::cout << "\nopen-cow-say, an open-source alternative to cowsay"<< std::endl;

   return 0;
}

