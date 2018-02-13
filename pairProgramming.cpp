#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include "catch.hpp"
#include <vector>
using std::vector;
#include <string>
using std::string;

string delimiter = ",";
int add(const string &addable){
    string modified_add = addable;
    modified_add += ",";
    vector<int> nums{};
    if(addable.size()==0){
        return 0;
    }

    auto num1 = stoi(modified_add.substr(0, modified_add.find(delimiter)));
    int num2;
    try{
      std::cout<<modified_add;
      num2 = stoi(modified_add.substr(1, modified_add.find(delimiter)));
      std::cout<<num2;
    }
    catch(...){
      return num1;
    }

    return num1 + num2;
}

TEST_CASE( "add null str [add]" ) {
    REQUIRE( add("") == 0 );
    REQUIRE( add("1") == 1);
    REQUIRE( add("2") == 2);
    REQUIRE( add("1,2") == 3);

}
