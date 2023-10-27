# Euclidean-vector-CPP
My code for an Euclidean Vector library I implemented using C++ for an assignment in uni.

I have also uploaded a sample of some of my unit testing with Catch2, a testing framework for C++.

The interface for the library is provided in include/euclidean_vector.hpp.

Here is an example of using the library:
```
 {  
   auto a = comp6771::euclidean_vector(2);  
   a[0] = 1;  
   a[1] = 2;  
   auto b = comp6771::euclidean_vector(2);  
   b[0] = 1;  
   b[1] = 2;  
   auto c = comp6771::unit(a);  
   auto d = comp6771::unit(b);  
   REQUIRE(c == d);  
}  
```
