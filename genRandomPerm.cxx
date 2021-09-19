#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <iostream>
#include <ctime>
#include <vector>
template<typename RandomAccessIterator>
void knuthShuffle(RandomAccessIterator begin, RandomAccessIterator end) {
  for(unsigned int n = end - begin - 1; n >= 1; --n) {
    unsigned int k = rand() % (n + 1);
    if(k != n) {
      std::iter_swap(begin + k, begin + n);
    }
  }
}

 
int main(int argc, char *argv[])
{
    srand(time(NULL));
    int n;
    std::vector<int> vec;
    
    if(argc==2){
        for (int i = 1; i < 2; i++) {
            if (!isdigit(*argv[i])) {
                 std::cout << "ARGUMENTY MUSZA BYC LICZBA\n";
                exit(EXIT_FAILURE);
            }
        }
       std::istringstream iss1( argv[1] );
       if (iss1 >> n){}
    }else{
        std::cout << "ZLA LICZBA ARGUMENTOW\nliczba losowan<n>\n";
        exit (EXIT_FAILURE);

    } 
    for(int i = 0; i<n; i++) vec.push_back(i);
   
    knuthShuffle(vec.begin(), vec.end()); // shuffle STL container
    //std::cout<<n<<'\n';
    for(auto p : vec)std::cout<<p<<'\n';
}