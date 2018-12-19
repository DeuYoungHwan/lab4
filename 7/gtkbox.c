#include <gtk/gtk.h>
void quit ( GtkWidget *window, gpointer data)
{
gtk_main_quit();
}
int main (int argc, char *argv[])
{
GtkWidget *window;
GtkWidget *label1, *label2, *label3;
GtkWidget *hbox;
GtkWidget *vbox;

gtk_init(&argc, &argv);
window =gtk_window_new(GTK_WINDOW_TOPLEVEL);
gtk_window_set_title(GTK_WINDOW(window), "TheWindow Title");
gtk_window_set_position(GTK_WINDOW(window),GTK_WIN_POS_CENTER);
gtk_window_set_default_size(GTK_WINDOW(window),300, 200);



/* 윈도우를 닫을 때 “destroy” 시그널이 발생함 */
g_signal_connect (GTK_OBJECT(window), "destroy",GTK_SIGNAL_FUNC ( quit), NULL);
label1 = gtk_label_new("라벨 1");
label2 = gtk_label_new("라벨 2");
label3 = gtk_label_new("라벨 3");

hbox = gtk_hbox_new ( TRUE, 5 );

vbox = gtk_vbox_new ( FALSE, 10);
gtk_box_pack_start(GTK_BOX(vbox), label1, TRUE,FALSE, 5);
gtk_box_pack_start(GTK_BOX(vbox), label2, TRUE,FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox), vbox, FALSE,FALSE, 5);
gtk_box_pack_start(GTK_BOX(hbox), label3, FALSE,FALSE, 5);

gtk_container_add(GTK_CONTAINER(window), hbox);
gtk_widget_show_all(window);
gtk_main ();
return 0;
} 
