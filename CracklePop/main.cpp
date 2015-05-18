#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
          for(int i = 1; i <101; i++)
          {
                    if(i % 3 == 0)
                              cout << "Crackle";

                    if(i % 5 == 0)
                              cout << "Pop";

                    if(i % 5 != 0 && i % 3 != 0)
                              cout << i;

                    cout << endl;
          }
}
