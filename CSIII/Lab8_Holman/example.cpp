// example opening file for appending 
// Wayne Cheng
// 4/15/2018 

// modified by Ben Holman
#include <iostream>
#include <fstream>
#include <string>

class Logger{
public:
  static Logger& instance(){
    //static Logger s_instance; 
    return s_instance; 
  }

void report(const std::string& string1){
    std:: ofstream fout; 
    fout.open(string1, std::fstream::out | std::fstream::app);
    fout << "more lorem ipsum" << std::endl; 
    fout.close(); 
  } 
private:
  Logger(const Logger&){}
  Logger& operator=(const Logger&){}
  static Logger s_instance; 
protected:
  Logger() = default; 
}; 

Logger Logger::s_instance;  

// 2 external functions that call Logger, but only one instance 
int main () {
  //Logger::instance.report("test.txt");
  Logger& Get = Logger::instance(); 
  Get.report("test.txt");
  Logger::instance().report("test.txt"); 

	return 0;
} 
