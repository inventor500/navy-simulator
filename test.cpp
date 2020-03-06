#include "time.h"
using namespace std;

int main() {
  string testDate;
  string testTime;
  Timer t("1/20/2020","10:20:40");
  Timer s("1/20/2020","10:20:30");
  Timer i = s;
  cout << "Testing < operator: ";
  cout << boolalpha << (s < t) << endl;
  cout << "Testing == operator: ";
  cout << boolalpha << (s == i) << endl;
  cout << "Testing > operator: ";
  cout << boolalpha << (t > s) << endl;
  cout << "Testing <= operator: ";
  cout << boolalpha << ((s <= t) && (s <= i)) << endl;
  cout << "Testing >= operator: ";
  cout << boolalpha << ((t >= s) && (s >= i)) << endl;
  cout << "Testing != operator: ";
  cout << boolalpha << (t != s) << endl;
  cout << "Testing + operator: " << t << " + 1 second == " << (t + 1) << endl;
  cout << "Testing ++c operator: " << t << " " << ++t << endl;
  cout << "Testing c++ operator: " << t++ << " is now " << t << endl;
  cout << "Testing += operator: " << t << " + 8 == ";
  t += 8;
  cout << t << endl;
  cout << "Please ener a time M:D:Y H:M:S: ";
  cin >> i;
  cout << i << endl;
  cout << "Time between " << t << " and " << s << " is: " << (t-s) << " seconds. " << endl;
  cout << t << " - 20 seconds == " << (t-20) << endl;
  cout << t << " is now ";
  t -= 20;
  cout << t << endl;
  
  return 0;
}
