#include "adw_simple.h"

namespace AdwSimple {

// Window implementation
Window::Window(GtkApplication *app, const std::string &title) {
  // Create the main window
  window_ = adw_application_window_new(app);
  gtk_window_set_title(GTK_WINDOW(window_), title.c_str());
  gtk_window_set_default_size(GTK_WINDOW(window_), 400, 600);

  // Create a scrolled window for content
  scrolled_window_ = gtk_scrolled_window_new();
  gtk_widget_set_vexpand(scrolled_window_, TRUE);
  gtk_widget_set_hexpand(scrolled_window_, TRUE);

  // Create a clamp for responsive design
  clamp_ = adw_clamp_new();
  adw_clamp_set_maximum_size(ADW_CLAMP(clamp_), 600);
  gtk_scrolled_window_set_child(GTK_SCROLLED_WINDOW(scrolled_window_),
                                 clamp_);

  // Create main box to hold content
  main_box_ = gtk_box_new(GTK_ORIENTATION_VERTICAL, 12);
  gtk_widget_set_margin_top(main_box_, 12);
  gtk_widget_set_margin_bottom(main_box_, 12);
  gtk_widget_set_margin_start(main_box_, 12);
  gtk_widget_set_margin_end(main_box_, 12);
  adw_clamp_set_child(ADW_CLAMP(clamp_), main_box_);

  // Create content box for scrollable content
  content_box_ = gtk_box_new(GTK_ORIENTATION_VERTICAL, 24);
  gtk_box_append(GTK_BOX(main_box_), content_box_);

  // Set the scrolled window as the window content
  adw_application_window_set_content(ADW_APPLICATION_WINDOW(window_),
                                      scrolled_window_);
}

Window::~Window() {
  // GTK handles widget cleanup
}

GtkWidget *Window::add_group(const std::string &title) {
  // Create a preferences group
  GtkWidget *group = adw_preferences_group_new();
  adw_preferences_group_set_title(ADW_PREFERENCES_GROUP(group), title.c_str());
  gtk_box_append(GTK_BOX(content_box_), group);
  return group;
}

void Window::add_row(GtkWidget *group, const std::string &title,
                     const std::string &icon_name) {
  // Create an action row with icon
  GtkWidget *row = adw_action_row_new();
  adw_preferences_row_set_title(ADW_PREFERENCES_ROW(row), title.c_str());

  // Add icon if provided
  if (!icon_name.empty()) {
    GtkWidget *icon = gtk_image_new_from_icon_name(icon_name.c_str());
    adw_action_row_add_prefix(ADW_ACTION_ROW(row), icon);
  }

  adw_preferences_group_add(ADW_PREFERENCES_GROUP(group), row);
}

GtkWidget *Window::add_control_box() {
  // Create a box for controls at the bottom
  GtkWidget *control_box = gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6);
  gtk_widget_set_halign(control_box, GTK_ALIGN_CENTER);
  gtk_widget_set_margin_top(control_box, 12);
  gtk_box_append(GTK_BOX(main_box_), control_box);
  return control_box;
}

void Window::show() { gtk_window_present(GTK_WINDOW(window_)); }

// App implementation
App::App(const std::string &app_id,
         std::function<void(GtkApplication *)> activate_callback)
    : activate_callback_(activate_callback) {
  app_ = adw_application_new(app_id.c_str(), G_APPLICATION_DEFAULT_FLAGS);
  g_signal_connect(app_, "activate", G_CALLBACK(on_activate), this);
}

App::~App() { g_object_unref(app_); }

int App::run(int argc, char *argv[]) {
  int status = g_application_run(G_APPLICATION(app_), argc, argv);
  return status;
}

void App::on_activate(GtkApplication *app, gpointer user_data) {
  App *self = static_cast<App *>(user_data);
  if (self->activate_callback_) {
    self->activate_callback_(app);
  }
}

} // namespace AdwSimple
