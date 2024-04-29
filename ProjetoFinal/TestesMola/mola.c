#include <stdio.h>
#include <gtk/gtk.h>
#include <cairo.h>

gdouble xlen=500, ylen=250;
gchar str1[16]="Projeto:v1";
gdouble dt,t=0.001,k=1e4,m=1;

gboolean
cb_draw_event (GtkWidget  *darea , 
               cairo_t    *cr    , 
               gpointer    data  )
{      
  static gdouble  pos1x = 30., pos1y = 50., x=30+250., y=50+20., c=0., mheight= (30+40)/10., mwidth= 16., dx;//
  GtkAllocation  alloc1 ;
  gchar texto[64];

  gtk_widget_get_allocation (darea, &alloc1);

  //Background
  cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
  cairo_paint_with_alpha (cr, 0.4);
 
  //Parede1
  cairo_set_source_rgb (cr, 0.7, 0.7, 0.7);
  cairo_set_line_width (cr, 3.0);
  cairo_rectangle (cr, 0, 0, 20, alloc1.height);
  cairo_fill_preserve (cr);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke (cr);

  //Parede2
  cairo_set_source_rgb (cr, 0.7, 0.7, 0.7);
  cairo_set_line_width (cr, 3.0);
  cairo_rectangle (cr, alloc1.width-20, 0, 20, alloc1.height);
  cairo_fill_preserve (cr);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke (cr);
  
  //Massa1
  cairo_set_source_rgb (cr, 0.8, 0.64, 0.49);
  cairo_set_line_width (cr, 1.0);
  cairo_rectangle (cr, (gint) pos1x+60, (gint) pos1y, 40, 75);
  cairo_fill_preserve (cr);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke (cr);

  //Texto Base!!
  cairo_move_to (cr, 35, alloc1.height-35);
  cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size (cr, 14);
  cairo_set_source_rgb (cr, 0.8, 0., 0.);
  sprintf (texto, "Demonstração de um sistema massa(M1)-mola + massa(M2)");
  cairo_show_text (cr, texto);
  
  //MolaTestes!
  //Parte1(ramo de cima);
  cairo_set_source_rgb(cr, 0., 0., 0.);
  cairo_move_to(cr, 20, pos1y+(75/2)-(mwidth/2));
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_stroke(cr);

  //Parte2(ramo de baixo;
  cairo_move_to(cr, 20, pos1y+(75/2)+(mwidth/2));
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_rel_line_to(cr, mheight, -mwidth);
  cairo_rel_line_to(cr, mheight, mwidth);
  cairo_stroke(cr);


  
  //TextoMassa1
  cairo_move_to (cr, (gint) pos1x+60+12.5, (gint) pos1y+75+15);
  cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size (cr, 16);
  cairo_set_source_rgb (cr, 0.8, 0., 0.);
  sprintf (texto, "M1");
  cairo_show_text (cr, texto);

  //Massa2
  cairo_set_source_rgb (cr, 0.8, 0.64, 0.49);
  cairo_set_line_width (cr, 1.0);
  cairo_rectangle (cr, (gint) x+60, (gint) y, 45, 30);
  cairo_fill_preserve (cr);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke (cr);

  //TextoMassa2
  cairo_move_to (cr, (gint) x+60+12.5, (gint) y+30+15);
  cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size (cr, 16);
  cairo_set_source_rgb (cr, 0.8, 0., 0.);
  sprintf (texto, "M2");
  cairo_show_text (cr, texto);
  
  //Actualizacao da posicao(Massa1) e da mola!!
  dt= dt-((k/m)*pos1x*t);
  dx=pos1x-(pos1x+(dt*t));
  pos1x=pos1x+(dt*t);
  mheight=mheight-(dx/10);
  
  //Atualização da posição(Massa2)
  if ((x+45+20+65) >= alloc1.width)
    c=1;

  if(x<=(pos1x+45)){
    c=0;x+=1;}
     
  if(c==0)
    x+=2;
  if(c==1)
  x-=2;
  
  return FALSE; 
}


gboolean 
time_handler (GtkWidget *widget)
{  
  if ((!GTK_IS_WIDGET(widget)) || (!gtk_widget_get_window (widget)))
    return FALSE;

  gtk_widget_queue_draw(widget);

  return TRUE;
}


int main(int argc, char **argv)
{
  GtkWidget *window, *darea;
						     
  gtk_init (&argc, &argv);
  window= gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(window),xlen,ylen);
  gtk_window_set_title(GTK_WINDOW(window),str1);
  gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);

  darea= gtk_drawing_area_new();
  gtk_container_add (GTK_CONTAINER (window), darea);

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(cb_draw_event),NULL);

  g_timeout_add (1, (GSourceFunc) time_handler, darea);
    
  gtk_widget_show_all(window);
  gtk_main();

  return(0);
}
