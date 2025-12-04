#include "adw_simple.h"

class MyWindow : public AdwSimple::Window {
public:
  MyWindow(GtkApplication *app) : AdwSimple::Window(app, "My App") {
    // Add your UI setup here
    GtkWidget *group = add_group("Settings");
    add_row(group, "Option 1", "preferences-system-symbolic");

    GtkWidget *controls = add_control_box();
    GtkWidget *button = gtk_button_new_with_label("Click Me");
    gtk_box_append(GTK_BOX(controls), button);
  }
};

int main(int argc, char *argv[]) {
  AdwSimple::App app("com.example.MyApp", [](GtkApplication *app) {
    auto *window = new MyWindow(app);
    window->show();
    // Note: GTK's reference counting system manages the window's lifecycle
  });
  return app.run(argc, argv);
}
