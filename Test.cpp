#include "doctest.h"
#include <string>
#include <algorithm>
#include <iostream>
#include <sstream>
#include "sources/OrgChart.hpp"
using namespace ariel;
using namespace std;




int countWorkers(OrgChart organization){
    int count = 0;
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it){
        count++;
    }
    return count;
}


TEST_CASE("tests") {

    OrgChart organization;

    organization.add_root("CEO")
        .add_sub("CEO", "CTO")         // Now the CTO is subordinate to the CEO
        .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
        .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
        .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
        .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO
    ostringstream out1{""};
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        out1 << (*it) << " " ;;
    } 
    string out1_str = out1.str();
    CHECK(out1_str == "CEO CTO CFO COO VP_SW VP_BI ");


    ostringstream out2{""};
    for (auto it = organization.begin_reverse_order(); it != organization.end_reverse_order(); ++it)
    {
        out2 << (*it) << " " ;
    } 
    string out2_str = out2.str();
    CHECK(out2_str == "VP_SW VP_BI CTO CFO COO CEO ");


    ostringstream out3{""};
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        out3 << (*it) << " " ;
    } 
    string out3_str = out3.str();
    CHECK(out3_str == "CEO CTO VP_SW CFO COO VP_BI ");


    ostringstream out4{""};
    for (auto element : organization){ 
        out4 << element << " " ;
    }
    string out4_str = out4.str();
    CHECK(out4_str == "CEO CTO CFO COO VP_SW VP_BI ");


    ostringstream out5{""};
    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it)
    {
        out5 << it->size() << " " ;
    } 
    string out5_str = out5.str();
    CHECK(out5_str == "3 3 3 3 5 5 ");


    CHECK_THROWS(organization.add_sub("underCEO","underUnderCEO"));
    CHECK(countWorkers(organization) == 6);

    CHECK_NOTHROW(organization.add_sub("CEO","underCEO"));
    CHECK(countWorkers(organization) == 7);

    CHECK_NOTHROW(organization.add_sub("CEO","underCEO"));
    CHECK(countWorkers(organization) == 8);

    //doesnt add multiple times 
    CHECK_NOTHROW(organization.add_sub("underCEO","underUnderCEO"));
    CHECK(countWorkers(organization) == 9);

    //can add 2 with the same name
    CHECK_NOTHROW(organization.add_sub("underCEO","underCEO"));
    CHECK(countWorkers(organization) == 10);

    CHECK_NOTHROW(organization.add_root("CEO2"));
    CHECK(countWorkers(organization) == 10);

    //ceo doesnt exist
    CHECK_THROWS(organization.add_sub("CEO","underCEO"));

    CHECK_NOTHROW(organization.add_root("underCEO"));
    CHECK(countWorkers(organization) == 10);

    CHECK_NOTHROW(organization.add_sub("VP_BI","CEO"));
    CHECK(countWorkers(organization) == 11);
    
}


