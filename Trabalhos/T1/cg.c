#include <stdio.h>
#include <stdlib.h>

#include <GL/glew.h>
#include <GL/glut.h>

#include <gtk/gtk.h>

#include "poligono.h"

#define HEIGHT 400
#define WIDTH 400

poligono p ;

static gboolean render (GtkGLArea *area, GdkGLContext *context) {
  // inside this function it's safe to use GL; the given
  // #GdkGLContext has been made current to the drawable
  // surface used by the #GtkGLArea and the viewport has
  // already been set to be the size of the allocation
  glClearColor (0, 0, 0, 0);
  glClear (GL_COLOR_BUFFER_BIT);

  return TRUE;
}

static void activate(GtkApplication *app) {
  GtkWidget *window;
  GtkWidget *gl_area;

  window = gtk_application_window_new (app);
  gtk_window_set_title (GTK_WINDOW (window), "Hello Window");
  gtk_window_set_default_size (GTK_WINDOW (window), WIDTH, HEIGHT);

  gl_area = gtk_gl_area_new();
  g_signal_connect (gl_area, "render", G_CALLBACK (render), NULL);
  gtk_container_add (GTK_CONTAINER(window), gl_area);

  gtk_widget_show_all (window);
}


int main(int argc, char **argv)  {
//	initPoligono(&p) ;

    GtkApplication *app;
    int status;

    app = gtk_application_new ("org.gtk.example", G_APPLICATION_FLAGS_NONE);
    g_signal_connect (app, "activate", G_CALLBACK (activate), NULL);
    status = g_application_run (G_APPLICATION (app), argc, argv);
    g_object_unref (app);

    return status;
}
