#include <vector>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <cstdio> 
#include <ctime>
#include <chrono>

template <class T>
struct Point {
	T x, y;
};

template <class T>
using P = std::vector<Point<T>>;

template <class T>
T dist(const Point<T> &p1, const Point<T> &p2) {  
        return sqrt(((p1.x - p2.x)*(p1.x - p2.x)) + ((p1.y - p2.y)*(p1.y - p2.y)));  
}

template <class T> 
void swap(Point<T> &a, Point<T> &b) { 
    Point<T> t = a; 
    a = b; 
    b = t; 
} 

template <class T>
int partition (P<T> &arr, int start, int end, const std::string &by) { 
    Point<T> pivot = arr[end];
    int i = (start - 1);
  
    for (int j = start; j <= end - 1; j++)  { 
        if(by == "x"){
            if (arr[j].x <= pivot.x) { 
                i++;
                swap(arr[i], arr[j]); 
            } 
        }else{
            if (arr[j].y <= pivot.y) { 
                i++;
                swap(arr[i], arr[j]); 
            } 
        }
       
    } 
    swap(arr[i + 1], arr[end]); 
    return (i + 1); 
} 

template <class T>
void quickSort(P<T> &arr, const int &start, const int &end, const std::string &by) {  
    if (start < end) { 
        int part = partition(arr, start, end, by); 
        quickSort(arr, start, part - 1, by); 
        quickSort(arr, part + 1, end, by); 
    } 
}

template <class T>
T Inside(P<T> strip, double d = std::numeric_limits<double>::max()) {
	auto min = d;
 
	for (int i = 0; i < strip.size(); ++i)
		for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < min; ++j)
			   if (dist(strip[i],strip[j]) < min)  
                    min = dist(strip[i], strip[j]); 
 
	return min;
}
// The method of divide and conquer 
template <class T>
T closestOutside(P<T> Px, P<T> Py) {  
    // If the points are max three, calculate the min distance iteratively
    if (Px.size() <= 3)  
        return bruteForce(Px);  
    // Finds the middle of the sorted array after x
    int mid = Px.size() / 2;  
    
    P<T> Pyl;   // Sorted array y on the left 
    P<T> Pyr;  // Sorted array y on the right 
    for (auto p : Py) {
		if (p.x <= Px[mid].x) Pyl.push_back(p);
		else Pyr.push_back(p);
	}
    P<T> Pxl =  P<T>(Px.begin(), Px.begin() + mid);
	P<T> Pxr =  P<T>(Px.begin() + mid + 1, Px.end());

    auto dl = closestOutside(Pxl, Pyl); 
	auto dr = closestOutside(Pxr, Pyr); 
	auto d = std::min(dl, dr);

    
    // Builds an array of points that are up to d distances from the line passing through the midpoint.
    P<T> strip;
    for (auto p : Py) 
		if (p.x - Px[mid].x < d) strip.push_back(p);
  
     
    // Finds the minimum in the "middle space" and we compare it with the minimum in the "outer space" 
    return Inside(strip, d);
}  

template <class T>
T closest(const P<T> &arr) {  
        // sorts arrays of points by x and y 
           
        P<T> Px;
        P<T> Py;

        for (int i = 0; i < arr.size(); i++) { 
            Px.push_back(arr[i]); 
            Py.push_back(arr[i]);
        } 
        quickSort(Px, 0, Px.size()-1, "x");
        quickSort(Py, 0, Py.size()-1, "y");  

        return closestOutside(Px, Py);  
} 

template <class T>
T bruteForce(P<T> &arr) {  

    T min = dist(arr[0], arr[1]);
    for (int i = 1; i < arr.size() - 1; i++)  
        for (int j = i+1; j < arr.size(); j++)  
            if (dist(arr[i], arr[j]) < min)  
                min = dist(arr[i], arr[j]);  
    return min;   
} 

int main() { 

    P<double> points;
    int n; 
    double x, y;

    std::cin >> n;
    for (int i = 0; i < n; i++) {
        
        std::cin >> x;
        std::cin >> y;
        points.push_back({x,y});
     
    }
    
    auto start1 = std::chrono::high_resolution_clock::now();
        std::cout <<"The shortest distance with the ,,bruteForce'' algorithm : "<< bruteForce(points) << '\n';  
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> bruteForce = end1 - start1;
    std::cerr << "bruteForce elapsed time[s] = " << bruteForce.count() << std::endl;
    std::cout<<"------------\n";
    auto start2 = std::chrono::high_resolution_clock::now();
        std::cout <<"The smallest distance with the ,,divide and conquer'' algorithm : "<< closest(points) << '\n'; 
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> closest = end2 - start2;
    std::cerr << "divide and conquer elapsed time[s] = " << closest.count() << std::endl;

    return 0; 
}
    