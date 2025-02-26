// THIS FILE IS UNDER CONSTRUCTION
// Right now, I dont have any tests to run, but I will as soon as I start compiling things separately
#include<catch2/catch_test_macros.hpp>
#include<catch2/benchmark/catch_benchmark.hpp>

long long factorial( long long n){
  return n<= 1 ? n: factorial(n-1) * n;
}

TEST_CASE("bench factorial", "[!benchmark]"){
  REQUIRE( factorial( 1) == 1 );
  REQUIRE( factorial( 10) == 3'628'800 );
  BENCHMARK("fact 10"){
    return factorial(10);
  };
}
