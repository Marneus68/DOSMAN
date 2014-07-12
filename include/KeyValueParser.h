#ifndef _KEYVALUEPARSER_H_
#define _KEYVALUEPARSER_H_
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cstdint>
#include <iostream>
#include <exception>
#include <glibmm.h>
typedef Glib::Container_Helpers::ArrayHandleIterator<Glib::Container_Helpers::TypeTraits<Glib::ustring>> DSGlibIterator ; 
typedef Glib::ArrayHandle<Glib::ustring> DSGlibArray ; 

/**
 * my namespace
 * */
namespace dosman{



  /**
   * my class
   */
  class KeyValueParser{


    public:
      const Glib::KeyFileFlags flags = Glib::KeyFileFlags::KEY_FILE_KEEP_COMMENTS | 
                                       Glib::KeyFileFlags::KEY_FILE_KEEP_TRANSLATIONS;  /*!< keep the object from erasing the comments and translation when saving the file */
      
      Glib::KeyFile* dosConfFile; /*!< a key value struct in which the conf file datas will be stored */

      KeyValueParser(const std::string& filename);
      KeyValueParser(const KeyValueParser&);
      KeyValueParser& operator=(const KeyValueParser&);
      
      /// get all groups
      std::vector<Glib::ustring> getGroups();

      // get all key from a group
      std::vector<Glib::ustring> getKeysFromGroup(const std::string& group_name);

      /// print groups their keys/values
      friend std::ostream& operator<<( std::ostream& out , const KeyValueParser& parserIn ) ;

      ///get key value
      std::string  getKeyValueFromGroup(const std::string& group_name, const std::string& key);

      ///update some key value
      void  setKeyValue(const Glib::ustring& group_name, const Glib::ustring& key, const Glib::ustring& value);

      /// set list as value of a key = 1;2;3
      void  setMultipleValuesInKey (const std::string& group_name, const std::string& key, const std::vector<Glib::ustring >& list);

      /// save dos config file  
      bool saveConfigurationFile( const std::string & filename);
      
      /**
       * destructor
       */
      ~KeyValueParser();

  };
}


#endif
