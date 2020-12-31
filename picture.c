#include <stdio.h>
#include <gtk-2.0/gtk/gtk.h>

int main(int argc, char * argv[]){
	GtkWidget *window;
        GtkWidget *button;
      	gtk_init (&argc, &argv);
      	window=gtk_window_new (GTK_WINDOW_TOPLEVEL); 
	/* 设置title文字，注意UTF8格式的文字转换，否则是乱码*/
    	gtk_window_set_title(GTK_WINDOW (window), g_locale_to_utf8("你好",-1,NULL,NULL,NULL));
	gtk_widget_show(window);
	gtk_main();
	return 0;
}

