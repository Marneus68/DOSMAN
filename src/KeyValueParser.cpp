#include<KeyValueParser.h>

#include "Exceptions.h"

namespace dosman{

    dosman::KeyValueParser::KeyValueParser( const std::string& filename ) {
        dosConfFile = new Glib::KeyFile();  
        bool isFileEmpty = dosConfFile->load_from_file(filename, flags);
        if(!isFileEmpty){
            std::cout <<"sorry the configuration file is empty"<< std::endl;
            //exit(-1);
            throw InvalidConfigFileException();
        }
    }

    dosman::KeyValueParser::KeyValueParser(const KeyValueParser& parserIn) {
        try {
            dosConfFile = new Glib::KeyFile();  
            dosConfFile = parserIn.dosConfFile;
        } catch (std::exception &e ) {
            //std::cout << "Failed to init key parser by copy" << e.what() << std::endl ;
            throw InvalidConfigFileException();
        }
    }

    dosman::KeyValueParser& dosman::KeyValueParser::operator=(const KeyValueParser& parserIn) {
        delete dosConfFile;
        try {
            dosConfFile = new Glib::KeyFile();  
            dosConfFile = parserIn.dosConfFile;
        } catch (std::exception &e ) {
            std::cout << "Affectation Error" << e.what() << std::endl ;
        }
        return *this;
    }

    std::ostream& operator<<( std::ostream& out , const dosman::KeyValueParser& parserIn ) {
        out << " " << parserIn.dosConfFile->to_data() << " " << std::endl;
        return out;
    } 

    void  KeyValueParser::setKeyValue(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& value) {
        dosConfFile->set_string(group_name, key, value);
    }

    bool KeyValueParser::saveConfigurationFile( const std::string &   filename){
        if(dosConfFile->save_to_file(filename)){
            std::cout << "the file have been saved" <<std::endl;
            return 1;
        } else {
            std::cout << "failed to save dos configs" <<std::endl;
            return 0;
        }
    }

    std::vector<Glib::ustring> KeyValueParser::getGroups(){
        return dosConfFile->get_groups();
    }

    std::vector<Glib::ustring> KeyValueParser::getKeysFromGroup(const std::string& group_name){
        return dosConfFile->get_keys(group_name);
    };

    std::string  KeyValueParser::getKeyValueFromGroup(const std::string& group_name, const std::string& key) {
        return dosConfFile->get_string(group_name, key);
    }

    void  KeyValueParser::setMultipleValuesInKey(const std::string& group_name, const std::string& key, const std::vector<Glib::ustring >& list) {
        dosConfFile->set_string_list (group_name, key, list);
    }

    KeyValueParser::~KeyValueParser() {
        delete dosConfFile;
    }
}
 
