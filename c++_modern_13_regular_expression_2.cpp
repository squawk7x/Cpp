// ***********************************************
// Regular Expression 2
// ***********************************************

/***************  Deal with subexpression *****************/

/* 
  std::match_results<>  Store the detailed matches
  smatch                Detailed match in string

  smatch m;
  m[0].str()   The entire match (same with m.str(), m.str(0))
  m[1].str()   The substring that matches the first group  (same with m.str(1))
  m[2].str()   The substring that matches the second group
  m.prefix()   Everything before the first matched character
  m.suffix()   Everything after the last matched character
*/

#include <regex>
#include <iostream>
#include <string>

using namespace std;

int main() {
   string str;

   while (true) {
      cin >> str;
	  smatch m;        // typedef std::match_results<string>

	  regex e("([[:w:]]+)@([[:w:]]+)\\.com");  

	  bool found = regex_search(str, m, e);

      cout << "m.size() " << m.size() << endl;
	  for (int n = 0; n< m.size(); n++) {
		   cout << "m[" << n << "]: str()=" << m[n].str() << endl;
		   cout << "m[" << n << "]: str()=" << m.str(n) << endl;
		   cout << "m[" << n << "]: str()=" << *(m.begin()+n) << endl;
	  }
	  cout << "m.prefix().str(): " << m.prefix().str() << endl;
	  cout << "m.suffix().str(): " << m.suffix().str() << endl;
   }
}


