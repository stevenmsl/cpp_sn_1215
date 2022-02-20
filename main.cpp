#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol1215;

/*
Input: low = 0, high = 21
Output: [0,1,2,3,4,5,6,7,8,9,10,12,21]
*/
tuple<int, int, vector<int>> testFixture1()
{
  return make_tuple(0, 21,
                    vector<int>{
                        0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 12, 21});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << Util::toString(get<2>(f)) << endl;
  auto result = Solution::steppingNums(get<0>(f), get<1>(f));
  cout << "result: " << Util::toString(result) << endl;
}

main()
{
  test1();
  return 0;
}