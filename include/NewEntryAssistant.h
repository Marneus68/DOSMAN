#ifndef __NEWENTRYASSISTANT_H__
#define __NEWENTRYASSISTANT_H__

#include <gtkmm/assistant.h>

namespace dosman {
    class NewEntryAssistant : public Gtk::Assistant {
        private:
            /* data */

            // Signal handlers:
            void on_assistant_apply();
            void on_assistant_cancel();
            void on_assistant_close();
            void on_assistant_prepare(Gtk::Widget* widget);
            void on_entry_changed();

            // Member functions:
            void print_status();

        public:
            NewEntryAssistant ();
            NewEntryAssistant (const NewEntryAssistant& e_NewEntryAssistant);
            virtual ~NewEntryAssistant ();
    
            NewEntryAssistant operator=(NewEntryAssistant& e_NewEntryAssistant);

            void get_result(bool& check_state, Glib::ustring& entry_text);
    };
} /* dosman */

#endif /* __NEWENTRYASSISTANT_H__ */
