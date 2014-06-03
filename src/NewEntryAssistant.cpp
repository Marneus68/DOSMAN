#include "NewEntryAssistant.h"

extern "C" {
    #include <sys/stat.h>
}

void dosman::NewEntryAssistant::create_entry_dir(std::string e_name)
{
    mkdir(e_name.c_str(), 0);
}


dosman::NewEntryAssistant::NewEntryAssistant()
{
}

dosman::NewEntryAssistant::NewEntryAssistant(const NewEntryAssistant& e_NewEntryAssistant)
{
}

dosman::NewEntryAssistant::~NewEntryAssistant()
{
}

dosman::NewEntryAssistant dosman::NewEntryAssistant::operator=(NewEntryAssistant& e_NewEntryAssistant)
{
    return e_NewEntryAssistant;
}

void dosman::NewEntryAssistant::get_result(bool& check_state, Glib::ustring& entry_text)
{
}

void dosman::NewEntryAssistant::on_assistant_apply()
{
}

void dosman::NewEntryAssistant::on_assistant_cancel()
{
}

void dosman::NewEntryAssistant::on_assistant_close()
{
}

void dosman::NewEntryAssistant::on_assistant_prepare(Gtk::Widget* widget)
{
}

void dosman::NewEntryAssistant::on_entry_changed()
{
}

void dosman::NewEntryAssistant::print_status()
{
}

