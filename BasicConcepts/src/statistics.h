#ifndef STATISTICS_H_
#define STATISTICS_H_
#include "gcem.hpp"
#include <vector>
#include <ostream>

template<typename T>
std::ostream& operator<<(std::ostream& stream, const std::vector<T>& vector)
{
    stream<<"{";
    for(size_t i=0; i< vector.size(); i++)stream<<vector.at(i)<<",";
    stream<<"\b}";
    return stream;
}

inline void exchange(float& a, float& b)
{
    a+=b; b=a-b; a-=b;
}
inline void exchange(int& a, int& b)
{
    a=a+b; b=a-b; a=a-b;
}
inline void exchange(char& a, char& b)
{
    a+=b; b=a-b; a-=b;
}
inline void exchange(size_t& a, size_t& b)
{
    a+=b; b=a-b; a-=b;
}
inline void exchange(unsigned char& a, unsigned char& b)
{
    a+=b; b=a-b; a-=b;
}
inline void exchange(double& a, double& b)
{
    a+=b; b=a-b; a-=b;
}
template <typename T>
inline void exchange(T& a, T& b)
{
    T c= a; a=b; b=c;
}


//quicksort algorithm with p being set to 1 and r to the array_length
template <typename T>
inline std::vector<T>& quicksort(std::vector<T>& elements, const size_t p, const size_t r)
{
    if(p<r)
    {
    const T x= elements.at(r);
    size_t i= p-1;
    for(size_t j=p; j<r; j++) if(elements.at(j)<=x)
    {
        i++;
        exchange(elements.at(i),elements.at(j));
    }
    exchange(elements.at(i+1),elements.at(r)); 
    quicksort(elements,p,i);
    quicksort(elements,i+2,r);
    }
    return elements;
}

//Sorts array values according to arbitrary measure, starting value p:1, r: array_length
template<typename T, class F>
inline std::vector<T>& quicksort(std::vector<T>& elements, F measure, const size_t p, const size_t r)
{
    if(p<r)
  {
    const T x= elements.at(r);
    size_t i= p-1;
    for(size_t j=p; j<r; j++) if(measure(elements.at(j))<=measure(x))
    {
        i++;
        exchange(elements.at(i),elements.at(j));
    }
    exchange(elements.at(i+1),elements.at(r)); 
    quicksort(elements,p,i);
    quicksort(elements,i+2,r);
    }
    return elements;
}
//Quicksort of an std::vector
#define Quicksort(v) quicksort(v,1,v.size()-1);
//Quicksort of an std::vector with arbitrary measure
#define QuicksortM(v,m) quicksort(v,m,1,v.size()-1);

template <typename T>
inline float mean(const std::vector<T>& arr,const float sum=0, const size_t ind=0)
{
    return (ind<arr.size())?mean(arr,sum+arr[ind],ind+1):sum/arr.size();
}
template <typename T>
inline T max(const std::vector<T>& arr)
{
    if(arr.size()==0)return 0;
    T max=arr.at(0);
    for(int i=1; i< arr.size(); i++)if(max<arr.at(i))max=arr.at(i);
    return max;
}

template <typename T>
inline T min(const std::vector<T>& arr)
{
    if(arr.size()==0)return 0;
    T min=arr.at(0);
    for(int i=1; i< arr.size(); i++)if(min>arr.at(i))min=arr.at(i);
    return min;
}

template <typename T, class F>
inline T max_measure(const std::vector<T>& arr, F measure)
{
    if(arr.size()==0)return 0;
    T max=arr.at(0);
    for(int i=1; i< arr.size(); i++)if(measure(max)<measure(arr.at(i)))max=arr.at(i);
    return max;
}

template <typename T, class F>
inline T min_measure(const std::vector<T>& arr, F measure)
{
    if(arr.size()==0)return 0;
    T min=arr.at(0);
    for(int i=1; i< arr.size(); i++)if(measure(min)>measure(arr.at(i)))min=arr.at(i);
    return min;
}
#endif