# Euclidean-vector-CPP
My code for an Euclidean Vector library I implemented using C++ for an assignment in uni.

I have also uploaded a sample of some of my unit testing with Catch2, a testing framework for C++.

The interface for the library is provided in include/euclidean_vector.hpp.

Here is an example of using the library:

TEST_CASE("Creation of unit vectors") {  
  &ensp; SECTION("You have two identical vectors") {  
  &ensp; &ensp; auto a = comp6771::euclidean_vector(2);  
  &ensp; &ensp; a[0] = 1;  
  &ensp; &ensp; a[1] = 2;  
  &ensp; &ensp;  auto b = comp6771::euclidean_vector(2);  
  &ensp; &ensp;  b[0] = 1;  
  &ensp; &ensp;  b[1] = 2;  
  &ensp; &ensp;  auto c = comp6771::unit(a);  
  &ensp; &ensp;  auto d = comp6771::unit(b);  
  &ensp; &ensp;  REQUIRE(c == d);  
  &ensp; &ensp;}  
}  

