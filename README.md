# Euclidean-vector-CPP
Some of my code for an Euclidean Vector library I implemented using C++.

The interface is provided in include/euclidean_vector.hpp.

Here is a sample and example usage of the library:

TEST_CASE("Creation of unit vectors") {  
  SECTION("You have two identical vectors") {  
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
}  

