#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>

gchar chlabel[32] = "Valor atual:" ;
gdouble NUM=0;

gint len_chlabel;

void add1 (GtkWidget *widget, gpointer label)
{
  NUM+=1;
  sprintf(&chlabel[len_chlabel]," %.2lf",NUM);
  gtk_label_set_text(label,chlabel);
}

void subtract1 (GtkWidget *widget, gpointer label)
{
  NUM-=1;
  sprintf(&chlabel[len_chlabel]," %.2lf",NUM);
  gtk_label_set_text(label,chlabel);
}

void times2 (GtkWidget *widget, gpointer label)
{
  NUM*=2;
  sprintf(&chlabel[len_chlabel]," %.2lf",NUM);
  gtk_label_set_text(label,chlabel);
}

void divideby3 (GtkWidget *widget, gpointer label)
{
  NUM/=3;
  sprintf(&chlabel[len_chlabel]," %.2lf",NUM);
  gtk_label_set_text(label,chlabel);
}
  



int
main (int argc, char **argv)
{
  GtkWidget *window, *vbox, *label , *hbox, *buttonplus1, *buttonminus1, *buttontimes2, *buttondivideby3;
  
  if(argc!=2)
    {
      perror("Número de argumentos incorreto!");
      return(0);
    }

  len_chlabel= strlen(chlabel);

  sscanf(argv[1],"%lf",&NUM);



  
  sprintf(&chlabel[len_chlabel]," %.2lf",NUM);
  
  gtk_init (&argc, &argv);

  window = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(window), 500, 200);
  gtk_window_set_title (GTK_WINDOW(window), "Grande programa do Afonso!");
  gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,0);
  gtk_container_add(GTK_CONTAINER(window),vbox);

  label = gtk_label_new(chlabel);
  gtk_box_pack_start(GTK_BOX(vbox),label,TRUE,FALSE,0);
  
  hbox = gtk_box_new(GTK_ORIENTATION_HORIZONTAL,0);
  gtk_box_pack_end(GTK_BOX(vbox),hbox,TRUE,FALSE,0);


  buttonplus1 = gtk_button_new_with_label("+1");
  gtk_box_pack_start(GTK_BOX(hbox),buttonplus1,TRUE,FALSE,0);
  gtk_widget_set_size_request(buttonplus1,75,40);
      
  buttonminus1 = gtk_button_new_with_label("-1");
  gtk_box_pack_start(GTK_BOX(hbox),buttonminus1,TRUE,FALSE,0);
  gtk_widget_set_size_request(buttonminus1,75,40);
    
  buttontimes2 = gtk_button_new_with_label("*2");
  gtk_box_pack_start(GTK_BOX(hbox),buttontimes2,TRUE,FALSE,0);
  gtk_widget_set_size_request(buttontimes2,75,40);
      
  buttondivideby3 = gtk_button_new_with_label("/3");
  gtk_box_pack_start(GTK_BOX(hbox),buttondivideby3,TRUE,FALSE,0);
  gtk_widget_set_size_request(buttondivideby3,75,40);

  g_signal_connect(G_OBJECT(buttonplus1), "clicked", G_CALLBACK(add1),label);
  g_signal_connect(G_OBJECT(buttonminus1), "clicked", G_CALLBACK(subtract1),label);
  g_signal_connect(G_OBJECT(buttontimes2), "clicked", G_CALLBACK(times2),label);
  g_signal_connect(G_OBJECT(buttondivideby3), "clicked", G_CALLBACK(divideby3),label);
      
  gtk_widget_show_all(window);
  gtk_main ();

  return 0;
}
