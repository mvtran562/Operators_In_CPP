//Matthew Tran
// Lab2
// 4/13/23 

// FILE: statistician.cpp
// CLASS IMPLEMENTED: statistician (see stats.h for documentation)

#include <cassert>   // Provides assert
#include <iostream>  // Provides istream class
#include "statistician.h"

using namespace std;

namespace coen79_lab2
{
    // PRECONDITION: No parameters
    // POSTCONDITION: initializes the 5 values: size, total, avg, min, max as 0 or 0.0 accordingly
    statistician::statistician()
    {
        size = 0;
        total = 0.0;
        avg = 0.0;
        min = 0.0;
        max = 0.0;
    }
    // PRECONDITION: Only 1 parameter and it is to be a double
    // POSTCONDITION: If there were no values previously, then the min and max are set to the parameter
    // The size is incremented and the total is added onto by the parameter
    // the average is updated by recalculating the total / size
    void statistician::next(double input)
    {
        size+=1;
        total+=input;
        if(size ==1)
        {
            min = input;
            max = input;
        }else if(input < min)
        {
            min = input;
        }else if(input >max){
            max = input;
        }
        avg = total / size;
    }
    // PRECONDITION: none
    // POSTCONDITION: returns avg instance variable
    double statistician::mean() const
    {
        return avg;
    }
    // PRECONDITION: none
    // POSTCONDITION: returns minimum instance variable
    double statistician::minimum() const
    {
        return min;
    }
    // PRECONDITION: none
    // POSTCONDITION: returns maximum instance variable 
    double statistician::maximum() const
    {
        return max;
    }
    // PRECONDITION: none
    // POSTCONDITION: resets the 5 variables size, total, avg, min, max to 0 
    void statistician::reset() 
    {
        size = 0;
        total = 0.0;
        avg = 0.0;
        min = 0.0;
        max = 0.0;
    }
    //FRIEND function +
    // PRECONDITION: Only 2 parameters, which are statistician objects. The function will reference them
    // POSTCONDITION:Adds the values size, total, avg, min, max of two statistician instances. Returns a statistician object
    statistician operator +(const statistician& s1, const statistician& s2)
    {
        statistician s;
        s.total = s1.total + s2.total; // new total
        s.size = s1.size + s2.size; // new size
        if(s1.min < s2.min) // setting min
        {
            s.min = s1.min;
        }else{
            s.min = s2.min;
        }

        if(s1.max > s2.max) // setting max
        {
            s.max = s1.max;
        }else{
            s.max = s2.max;
        }

        s.avg = s.total / s.size;
        return s;
    	//TO DO
    	//The function returns a statistician object
    	//After combination, think about how to assign values to the returned object's member variables
    }
    
    
    //FRIEND function *
    // PRECONDITION:Only 2 parameters, which are statistician objects. The function will reference them
    // POSTCONDITION:scales the values size, total, avg, min, max of two statistician instances.
    // If the scale is negative, the minimum and maximum values are set accordingly. Returns a statistician object
    statistician operator *(double scale, const statistician& p)
    {
        statistician s;
        s.total = p.total * scale;
        s.size = p.size * scale;
        s.avg = p.avg * scale;
        if(scale < 0)
        {
            s.max = p.min;
            s.min = p.max;
        }else{
            s.max = p.max;
            s.max = p.min;
        }

        return s;
    	//TO DO
    	//The function returns a statistician object
    	//Pay attention to the scale, it could be either positive or negative       
        //Assume we have 4 and -2 added to the object
        //The total is 2
        //If the scale is 4, then the total will be 8, and if the scale is -4, the total will be -8
        //If the scale is 4, then the largest and tiniest will be the same, if the scale is -4, the largest becomes the tiniest and the tiniest becomes the largest
        //Therefore, you need to distinguish between these 2 situations
    }

    //NON-MEMBER function ==
    // PRECONDITION: Only 2 parameters, which are statistician objects. The function will reference them
    // POSTCONDITION: The function will return true if the instance variables size, total, avg, min, max are equal and return false otherwise
    bool operator ==(const statistician& s1, const statistician& s2)
    {
        if( (s1.length() != 0) && (s2.length() != 0) )
        {
            if((s1.sum()==s2.sum()) && (s1.length()==s2.length()) && (s1.minimum() == s2.minimum()) && (s1.maximum() == s2.maximum()) && (s1.mean() == s2.mean()))
            {
                return true;
            }
        }else{
            return false;
        }
    	//TO DO
    	//2 situations:1. If at least one of the sequence is empty; 2. Both sequences are NOT empty
    }
}




