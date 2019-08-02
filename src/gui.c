#include <gtk/gtk.h>
#include <gdk/gdk.h>

// static void print_hello (GtkWidget *widget, gpointer   data) {
  //g_print ("Hello World\n");
//}

void my_getsize(GtkWidget *widget, GtkAllocation *allocation, void *data) {
  printf("width = %d, height = %d\n", allocation->width, allocation->height);
}

void my_getsize2(GtkWidget *window, GdkEvent *event, GtkPaned *paned) {
  gint x, y;
  gtk_window_get_size(GTK_WINDOW(window), &x, &y);
  printf("%i xx %i", x, y);
  gtk_paned_set_position (paned, 0.6 * x);
}

int main_gui (int   argc, char *argv[]) {
  GtkBuilder *builder;
  GtkWidget *window;
  GObject *paned;
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

  paned = gtk_builder_get_object(builder, "paned1");

  g_signal_connect(window, "configure-event", G_CALLBACK(my_getsize2), paned);

  g_signal_connect(window, "size-allocate", G_CALLBACK(my_getsize), NULL);

  // get pointers to the two labels
  //g_lbl_hello = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_hello"));
  //g_lbl_count = GTK_WIDGET(gtk_builder_get_object(builder, "lbl_count"));

  g_object_unref(builder);

  gtk_widget_show(window); 
  gtk_main ();

  return 0;
}