#include <gtk/gtk.h>

// static void print_hello (GtkWidget *widget, gpointer   data) {
  //g_print ("Hello World\n");
//}

int main_gui (int   argc, char *argv[]) {
  GtkBuilder *builder;
  GtkWidget *window;
  //GObject *button;
  //GObject *menuitem;
  GError *error = NULL;

  gtk_init (&argc, &argv);

  /* Construct a GtkBuilder instance and load our UI description */
  builder = gtk_builder_new ();
  if (gtk_builder_add_from_file (builder, "src/gui.ui", &error) == 0)
    {
      g_printerr ("Error loading file: %s\n", error->message);
      g_clear_error (&error);
      return 1;
    }

  window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
  gtk_builder_connect_signals(builder, NULL);

  // get pointers to the two labels
  //g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
  //g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));

  g_object_unref(builder);

  gtk_widget_show(window); 
  gtk_main ();

  return 0;
}