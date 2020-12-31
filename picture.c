#include <stdio.h>
#include <gtk-2.0/gtk/gtk.h>

GtkWidget *label;

void hello(GtkWidget *widget, gpointer data) {
	GString *string = g_string_new (NULL);
	g_print("Hello World %s\n", (gchar *) data);
	g_string_printf(string, "Hello World %s\n", (gchar *) data);
	gtk_label_set_text (GTK_LABEL(label), string->str);
	g_string_free(string, TRUE);
}

gint delete_event(GtkWidget *widget, GdkEvent *event, gpointer data) {
	g_print ("delete event occurred\n");
	
	return FALSE;
}

void destroy(GtkWidget *widget, gpointer data) {
	g_print("destroy event \n");
	gtk_main_quit();
}

gboolean deal_mouse_press(GtkWidget *widget, GdkEventButton *event, gpointer data) {
	switch(event->button) {
		case 1:
			g_print ("Left Button!!\n");
			break;
		case 2:
			g_print ("Middle Button!!\n");
			break;
		case 3:
			g_print ("Right Button!!\n");
			break;
		default:
			g_print	("Unknown Button!!\n");
	}

	if (event->type == GDK_2BUTTON_PRESS) {
		g_print ("double click\n");
	}

	gint i = event->x;
	gint j = event->y;
	g_print ("press_x = %d, press_y = %d\n", i, j);

	return TRUE;
}

gboolean deal_motion_notify_event(GtkWidget *widget, GdkEventMotion *event, gpointer data){
	gint i = event->x;	
	gint j = event->y;
	g_print ("motion_x = %d, motion_y = %d\n", i, j);

	return TRUE;
}

int main(int argc, char * argv[]){
	GtkWidget *window;
        GtkWidget *button;
	GtkWidget *box1;
	GtkWidget *box2;
	GtkWidget *box3;

      	gtk_init (&argc, &argv);

      	window=gtk_window_new (GTK_WINDOW_TOPLEVEL); 

	/* 设置title文字，注意UTF8格式的文字转换，否则是乱码*/
    	gtk_window_set_title(GTK_WINDOW (window), g_locale_to_utf8("你好",-1,NULL,NULL,NULL));

	g_signal_connect(G_OBJECT (window), "delete_event",\
			 G_CALLBACK (delete_event), NULL);
	
	g_signal_connect(G_OBJECT (window), "destroy",\
			 G_CALLBACK (destroy), NULL);

	gtk_container_set_border_width(GTK_CONTAINER (window), 10);	

	box1 = gtk_hbox_new(FALSE, 1) ;
	box2 = gtk_hbox_new(FALSE, 1);
	box3 = gtk_hbox_new(FALSE, 1);

	gtk_container_add (GTK_CONTAINER (window), box3);
	gtk_container_add (GTK_CONTAINER (box3), box1);
	
	gtk_container_add (GTK_CONTAINER (box3), box2);

	label = gtk_label_new ("label");

	gtk_container_add(GTK_CONTAINER(box2), label);

	button = gtk_button_new_with_label("button");

	g_signal_connect (G_OBJECT (button), "clicked",\
			  G_CALLBACK (hello), "1");

	gtk_container_add(GTK_CONTAINER(box1), button);

	gtk_widget_show(button);

	button = gtk_button_new_with_label("button");

	g_signal_connect (G_OBJECT (button), "clicked",\
			  G_CALLBACK (hello), "2");

	gtk_container_add(GTK_CONTAINER(box1), button);

	gtk_widget_show(button);
	

	button = gtk_button_new_with_label("button");

	g_signal_connect (G_OBJECT (button), "clicked",\
			  G_CALLBACK (hello), "3");
#if 0
	gtk_container_add(GTK_CONTAINER(box1), button);
#else
	gtk_box_pack_start (GTK_BOX(box1), button, TRUE, TRUE, 0);
#endif	
	gtk_widget_add_events(window, GDK_BUTTON_PRESS_MASK | GDK_BUTTON_MOTION_MASK);

	g_signal_connect(window, "button-press-event", G_CALLBACK(deal_mouse_press), NULL);

	g_signal_connect(window, "motion-notify-event", G_CALLBACK(deal_motion_notify_event), NULL);

#if 0
	gtk_widget_show(button);
	
	gtk_widget_show(box1);

	gtk_widget_show(window);
#endif
	gtk_widget_show_all (window);

	gtk_main();

	return 0;
}

