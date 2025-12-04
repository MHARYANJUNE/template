#ifndef ADW_SIMPLE_H
#define ADW_SIMPLE_H

#include <adwaita.h>
#include <functional>
#include <string>

namespace AdwSimple {

class Window {
public:
  Window(GtkApplication *app, const std::string &title);
  virtual ~Window();

  // Add a group (preference group) to the window
  GtkWidget *add_group(const std::string &title);

  // Add a row to a group with an icon
  void add_row(GtkWidget *group, const std::string &title,
               const std::string &icon_name);

  // Add a control box at the bottom of the window
  GtkWidget *add_control_box();

  // Show the window
  void show();

protected:
  GtkWidget *window_;
  GtkWidget *content_box_;
  GtkWidget *scrolled_window_;
  GtkWidget *clamp_;
  GtkWidget *main_box_;
};

class App {
public:
  App(const std::string &app_id,
      std::function<void(GtkApplication *)> activate_callback);
  ~App();

  // Run the application
  int run(int argc, char *argv[]);

private:
  GtkApplication *app_;
  std::function<void(GtkApplication *)> activate_callback_;

  static void on_activate(GtkApplication *app, gpointer user_data);
};

} // namespace AdwSimple

#endif // ADW_SIMPLE_H
