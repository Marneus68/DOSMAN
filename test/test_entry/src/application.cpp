#include <KeyValueParser.h>

int main(int argv, char** argc){  
  std::string filename = std::string("../dosbox.conf");
  dosman::KeyValueParser test2(filename);
  dosman::KeyValueParser test = dosman::KeyValueParser(filename);
  test.setKeyValue("dosbox", "language", "english");
  test.saveConfigurationFile("../dosbox.conf");
  std::vector<Glib::ustring> vectorTest = test.getGroups();
  std::cout << " vector 1" << vectorTest[0] << std::endl;
  std::cout << " getting key 3 from group ..." << std::endl;
  std::cout << test.getKeysFromGroup("dosbox")[2] << std::endl;
  std::cout << " getting language from dosbox group ..." << std::endl;
  std::cout << " [dosbox]"<< std::endl << "language = " 
            << test.getKeyValueFromGroup("dosbox","language") 
            << std::endl;
  std::vector<Glib::ustring> testVector;
  testVector.push_back("English");
  testVector.push_back("french");
  testVector.push_back("spanish");
  test.setMultipleValuesInKey("dosbox", "language", testVector);
  std::cout << test;
    return 0;
}

