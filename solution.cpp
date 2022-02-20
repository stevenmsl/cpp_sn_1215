#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <deque>
#include <sstream>
using namespace sol1215;
using namespace std;

/*takeaways
  - the key is to know how you can produce next
    stepping numbers from the current one. The
    next two stepping numbers will have one
    more digit than the current one
     n*10 + lastDigit(n) + 1 if lastDigit(n) < 9
     or
     n*10 + lastDigit(n) - 1 if lastDigit(n) > 0
  - example with range in [0,21]
    0 -> 0*10 + (0+1) = 1
        (which is already covered if we put
        all the single digit numbers in the queue
        initially)
    1 -> 1*10 + (1 +1) = 12
    2 -> 2*10 + (2-1) = 21
    2 -> 2*10 + (2+1) = 23 (out of range)

*/

vector<int> Solution::steppingNums(int low, int high)
{
  auto q = deque<int>();
  /* start with 1 digit numbers */
  for (auto i = 0; i < 10; i++)
    if (i >= low && i <= high)
      q.push_back(i);
  /*
    - low and high don't cover the whole 1 digit
      numbers range
    - what's in the queue is the answer already
  */
  if (q.size() < 10)
    return vector<int>(q.begin(), q.end());

  auto result = vector<int>();

  while (!q.empty())
  {
    auto n = q.front();
    q.pop_front();
    /* collect the result */
    result.push_back(n);

    /*
      - what 0 can produce is already in the queue
        0 * (0+1) = 1; skip it
    */
    if (n == 0)
      continue;

    auto lastDigit = n % 10;

    /*
      - make sure when you add or subtract
        one from the last digit of the current
        number the result is within 0 to 9
      - our goal is to produce the next
        stepping number that has one
        more digit than the current number
    */

    /*
      - do the subtraction first so we have a smaller number
        of the two goes in to the queue first
      - the result will be sorted if we do this
    */
    if (lastDigit > 0)
    {
      auto next = 10 * n + lastDigit - 1;
      if (next <= high)
        q.push_back(next);
    }
    if (lastDigit < 9)
    {
      auto next = 10 * n + lastDigit + 1;
      if (next <= high)
        q.push_back(next);
    }
  }

  // sort(result.begin(), result.end());
  return result;
}