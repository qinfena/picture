LIBS = `pkg-config --libs gtk+-2.0` 
INCLUDES = -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include/ -I/usr/include/cairo/ -I/usr/include/pango-1.0/ -I/usr/lib64/gtk-2.0/include/ -I/usr/include/gdk-pixbuf-2.0/ -I/usr/include/atk-1.0/

#LIBS = `pkg-config --libs gtk+-3.0`
#INCLUDES = -I/usr/include/gtk-2.0/ -I/usr/include/glib-2.0 -I/usr/lib64/glib-2.0/include/ -I/usr/include/cairo/ -I/usr/include/pango-1.0/ -I/usr/lib64/gtk-2.0/include/ -I/usr/include/gdk-pixbuf-2.0/ -I/usr/include/atk-1.0/	-I/usr/include/gtk-3.0/
picture: picture.o
	gcc -g -o picture picture.o ${LIBS}

picture.o:picture.c
	gcc -g -c picture.c ${INCLUDES}

.PHONY:clean

clean:
	rm *.o picture
