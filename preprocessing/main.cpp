// regex_match example
#include <iostream>
#include <string>
#include <regex>
#include <fstream>

#include <algorithm>
#include <vector>

using namespace std;

regex BEGIN_REGEX("(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*),(.*)");
regex SUMMARY("(.*)summary(.*)");

char tolower(char in){
  if(in<='Z' && in>='A')
    return in-('Z'-'z');
	return in;
}

string tolower(string s) {
	string ret=s;
	for(int i=0;i<s.length();i++) ret[i]=tolower(s[i]);
	return ret;
}

// trim from start
std::string &ltrim(std::string &s) {
  s.erase(s.begin(), std::find_if(s.begin(), s.end(), std::not1(std::ptr_fun<int, int>(std::isspace))));
  return s;
}

// trim from end
std::string &rtrim(std::string &s) {
  s.erase(std::find_if(s.rbegin(), s.rend(), std::not1(std::ptr_fun<int, int>(std::isspace))).base(), s.end());
  return s;
}

// trim from both ends
std::string strip(std::string s) {
  return ltrim(rtrim(s));
}

bool isSummary(string s) {
	int pos=s.find("summary");
	int len = s.length();
	if(pos>=0 && pos<len && len-pos-7<=3) return true;
	return false;
}

int main ()
{
	string testline("CS00107125,Ravi,Kumar,rkanalyst26@gmail.com,NULL,NJ,NULL,NULL,224-208-5704,");
	string sumtest("SUMMARY");

	ifstream file("fraudresumes.txt");
	string line;

	while(getline(file,line)) {
	  line=strip(tolower(line));
		cout<<line<<endl;
	  if(isSummary(line))
	  //if(regex_match(line,SUMMARY))
		  cout<<"Summary matched!\n";
    if(regex_match(line,BEGIN_REGEX))
	    cout<<"Begin matched!\n";

	}
	
  
	
	
  if (std::regex_match ("subject", std::regex("(sub)(.*)") ))
    std::cout << "string literal matched\n";

  std::string s ("subject");
  std::regex e ("(sub)(.*)");
  if (std::regex_match (s,e))
    std::cout << "string object matched\n";

  if ( std::regex_match ( s.begin(), s.end(), e ) )
    std::cout << "range matched\n";

  std::cmatch cm;    // same as std::match_results<const char*> cm;
  std::regex_match ("subject",cm,e);
  std::cout << "string literal with " << cm.size() << " matches\n";

  std::smatch sm;    // same as std::match_results<string::const_iterator> sm;
  std::regex_match (s,sm,e);
  std::cout << "string object with " << sm.size() << " matches\n";

  std::regex_match ( s.cbegin(), s.cend(), sm, e);
  std::cout << "range with " << sm.size() << " matches\n";

  // using explicit flags:
  std::regex_match ( "subject", cm, e, std::regex_constants::match_default );

  std::cout << "the matches were: ";
  for (unsigned i=0; i<sm.size(); ++i) {
    std::cout << "[" << sm[i] << "] ";
  }

  std::cout << std::endl;

  return 0;
}