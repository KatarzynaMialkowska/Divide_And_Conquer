#include <iostream>
#include <vector>
#include <iterator>
#include <cmath>
#include <algorithm>
#include <cstdio> 
#include <ctime>
#include <chrono>

using P = std::vector<int>;

int merge(P& vec, int l, int mid, int r) {
    int i, j, k;
    int count = 0;

    P leftvec (mid - l + 1);
    P rightvec (r - mid);
    for (i = 0; i < (mid - l + 1); i++)
        leftvec[i] = vec[i+l];
    for (j = 0; j < (r - mid); j++)
        rightvec[j] = vec[j+mid+1];
    
    k = l; i = 0; j = 0;
    
    while(i < (mid - l + 1) && j < (r - mid)) {
        if(leftvec[i] <= rightvec[j]) {
            vec[k] = leftvec[i++];
        }else{
            vec[k] = rightvec[j++];
            count += (mid - l + 1) - i;
        }
        k++;
    }
    while(i < (mid - l + 1)) {
        vec[k++] = leftvec[i++];
    }
    while(j < (r - mid)) {
        vec[k++] = rightvec[j++];
    }
    return count;
}

int mergeSort(P &vec, int l, int r) {
    int count = 0;
    if(l < r){
        int mid = floor( (l + r) / 2 );
        count  = mergeSort(vec, l, mid);
        count += mergeSort(vec, mid+1, r);
        count += merge(vec, l, mid, r);
    }
    
    return count;
}

int Inversions(P &vec) {
    return mergeSort(vec, 0, vec.size()-1);
}

int bruteInversions(P &vec) {
    int count = 0;
    for (int i = 0; i < vec.size() - 1; i++) {
        for (int j = i + 1; j < vec.size(); j++) {
            if (vec[i] > vec[j]) {
                count++;
            }
        }
    }
    return count;
}



int main()
{
    P vec(
    std::istream_iterator<int>(std::cin),
    std::istream_iterator<int>()
    );

//    for(const auto &i : vec){
//         std::cout << i << "\n";
//     }
  
    auto start1 = std::chrono::high_resolution_clock::now();
        std::cout <<"The number of inversions with the ,,bruteForce'' algorithm: "<< bruteInversions(vec) << '\n';  
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bruteForce = end1 - start1;
    std::cerr << "bruteForce elapsed time[s] = " << bruteForce.count() << std::endl;
    std::cout<<"------------\n";
    auto start2 = std::chrono::high_resolution_clock::now();
        std::cout <<"The number of inversions with the ,,divide and conquer' algorithm: "<< Inversions(vec) << '\n'; 
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> closest = end2 - start2;
    std::cerr << "divide and conquer elapsed time[s] = " << closest.count() << std::endl;

 
    return 0;
}