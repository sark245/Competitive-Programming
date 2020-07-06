## Performance of various algorithms

A hand coded Quick sort works almost similar to C++ sort() function, there is a difference though.  
C++ sort() function uses a hybrid sorting technique, it uses introsort which is a hybrid algorithm.  
Different implementations use different algorithms. The GNU Standard C++ library, uses a 3-part hybrid sorting   
algorithm: introsort is performed first (introsort itself being a hybrid of quicksort and heap sort)   
followed by an insertion sort on the result.

Can Improve quick sort by using middle element as the pivot or using a random element as pivot. 
