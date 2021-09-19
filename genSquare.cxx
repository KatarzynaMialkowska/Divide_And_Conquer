#include <iostream> 
#include <cmath>
#include <random>
#include <cstdlib> 
#include <iomanip>
#include <sstream>
#include <stdlib.h>     /* exit, EXIT_FAILURE */
#include <ctime>

int main(int argc, char *argv[]){
    int n;
        if(argc==2){
        for (int i = 1; i < 2; i++) {
            if (!isdigit(*argv[i])) {
                 std::cout << "ARGUMENTS MUST BE NUMEROUS\n";
                exit(EXIT_FAILURE);
            }
        }
       std::istringstream iss1( argv[1] );
       if (iss1 >> n){}
    }else{
        std::cout << "WRONG NUMBER OF ARGUMENTS\nnumber of numbers<n>\n";
        exit (EXIT_FAILURE);

    }

    // GENERATOR //
    std::mt19937 generator(time(NULL));
    std::uniform_real_distribution <double> distribution(0.0, 1.0);
    //Random number distribution that produces floating-point values according to 
    //a uniform distribution, 
    //which is described by the following probability density function:
    //p(x|a,b)=1/(b-a), a<=x<b

    std::cout<<n<<'\n';
    for( int i = 0; i < n; i++ )
    {
		std::cout<<distribution(generator)<<'\n';
        std::cout<<distribution(generator)<<'\n';
    }
    return 0;
}