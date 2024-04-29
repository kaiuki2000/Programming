#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
#include <cairo.h>
#include <math.h>

GtkWidget *window, *area, *graph1_area, *graph2_area;
GtkAllocation alloc1;
gchar texto[10];
gboolean vgp1, vgp2, vgp3, vgv1, vgv2, vgv3;
gint p, c=0, r=1, i=0, s, a, g, g1=1, fr=0, escp=0, escv=0, c1=0;
gdouble k=100, f0=0, dt, m=10, w, v1=0, v2=0, v3=0, t=0, d1, d2, d3, d4, x0, a1, a2, a3, comp, alt, yini=205, vgraph1[701], t2=0, vgraph2[701], vgraph3[701], eyy, t3, vvgraph1[701], vvgraph2[701], vvgraph3[701], max=0, exx=1;
GtkWidget *box, *vbox, *vbox1, *hbox, *hbox1, *frame, *frame1, *bframe1, *frame2, *hhelp, *help, *vhelp, *bcomecar, *comecar1, *parar, *reiniciar, *massa, *bcondicao, *bcondicao2, *bhcondicao, *lmassa, *lcte_elas, *cte_elas, *pos1, *lpos1, *pos2, *lpos2, *pos3, *lpos3, *vel1, *lvel1, *vel2, *lvel2, *vel3, *lvel3, *lforca, *forca, *lxx, *xx, *lyy, *yy, *lvelocidade, *velocidade, *gpos1, *framecg, *framecgv, *bframecg, *bframecgv, *lgpos1, *lgpos2, *gpos2, *lgpos3, *gpos3, *lgvel1, *gvel1, *lgvel2, *gvel2, *lgvel3, *gvel3, *stack, *switcher, *frame3, *vhbox1, *ls1, *box_cores, *box_desenho, *box_cores2, *cores;
gdouble   x1=-5., x2=5., x3=5., y = 182.;

/*gboolean fhelp (GtkWidget *widget)
{
  GtkWidget *hwindow, *box, *label;

  hwindow= gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(hwindow), 500, 500);
  gtk_window_set_resizable (GTK_WINDOW(hwindow), FALSE);
  gtk_window_set_position (GTK_WINDOW(hwindow), GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW(hwindow), "Ajuda");

  g_signal_connect (G_OBJECT(hwindow), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  box= gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (box), 5);
  gtk_container_add (GTK_CONTAINER (hwindow), box);

  label= gtk_label_new ("HEEEEELLLLPPPP");
  gtk_box_pack_start (GTK_BOX (box), label, TRUE, FALSE, 0);

  gtk_widget_show_all (hwindow);

  gtk_main ();
  
  return FALSE;

}*/


gboolean desenho (GtkWidget *widget, cairo_t *cr, gpointer data)
{


  m=gtk_spin_button_get_value (GTK_SPIN_BUTTON (massa));
  k=gtk_spin_button_get_value (GTK_SPIN_BUTTON (cte_elas));
  
  w=k/m;
  dt=gtk_range_get_value (GTK_RANGE(velocidade));

  cairo_set_source_rgb (cr, 0.5, 0.2, 0.2);
  cairo_set_line_width (cr, 1.0);
  cairo_rectangle (cr, (gint) x1+130, (gint) y, 80, 50);
  cairo_fill (cr);
  cairo_stroke(cr);

  cairo_set_source_rgb (cr, 0., 0.4, 0.4);
  cairo_rectangle (cr, (gint) x2+350, (gint) y, 80, 50);
  cairo_fill (cr);
  cairo_stroke (cr);

  cairo_set_source_rgb (cr, 0.1, 0.2, 0.6); 
  cairo_rectangle (cr, (gint) x3+570, (gint) y, 80, 50);
  cairo_fill (cr);
  cairo_stroke (cr);

  //molas
  d1=(x1+130)/13;
  x0=0;

  cairo_set_source_rgb (cr, 0.4, 0.4, 0.4); 

  cairo_move_to (cr, x0, y+25);
     
  cairo_line_to (cr, x0+d1, y);
  cairo_line_to (cr, x0+2*d1, y+50);
  cairo_line_to (cr, x0+3*d1, y);
  cairo_line_to (cr, x0+4*d1, y+50);
  cairo_line_to (cr, x0+5*d1, y);
  cairo_line_to (cr, x0+6*d1, y+50);
  cairo_line_to (cr, x0+7*d1, y);
  cairo_line_to (cr, x0+8*d1, y+50);
  cairo_line_to (cr, x0+9*d1, y);
  cairo_line_to (cr, x0+10*d1, y+50);
  cairo_line_to (cr, x0+11*d1, y);
  cairo_line_to (cr, x0+12*d1, y+50);
  cairo_line_to (cr, x0+13*d1, y+25);
  cairo_stroke(cr);

  d2=((x2+350)-(x1+130+80))/13;
  x0=x1+130+80;

  cairo_move_to (cr, x0, y+25);

  cairo_line_to (cr, x0+d2, y);
  cairo_line_to (cr, x0+2*d2, y+50);
  cairo_line_to (cr, x0+3*d2, y);
  cairo_line_to (cr, x0+4*d2, y+50);
  cairo_line_to (cr, x0+5*d2, y);
  cairo_line_to (cr, x0+6*d2, y+50);
  cairo_line_to (cr, x0+7*d2, y);
  cairo_line_to (cr, x0+8*d2, y+50);
  cairo_line_to (cr, x0+9*d2, y);
  cairo_line_to (cr, x0+10*d2, y+50);
  cairo_line_to (cr, x0+11*d2, y);
  cairo_line_to (cr, x0+12*d2, y+50);
  cairo_line_to (cr, x0+13*d2, y+25);
  cairo_stroke(cr);

  d3=((x3+570)-(x2+350+80))/13;
  x0=x2+350+80;

  cairo_move_to (cr, x0, y+25);

  cairo_line_to (cr, x0+d3, y);
  cairo_line_to (cr, x0+2*d3, y+50);
  cairo_line_to (cr, x0+3*d3, y);
  cairo_line_to (cr, x0+4*d3, y+50);
  cairo_line_to (cr, x0+5*d3, y);
  cairo_line_to (cr, x0+6*d3, y+50);
  cairo_line_to (cr, x0+7*d3, y);
  cairo_line_to (cr, x0+8*d3, y+50);
  cairo_line_to (cr, x0+9*d3, y);
  cairo_line_to (cr, x0+10*d3, y+50);
  cairo_line_to (cr, x0+11*d3, y);
  cairo_line_to (cr, x0+12*d3, y+50);
  cairo_line_to (cr, x0+13*d3, y+25);
  cairo_stroke(cr);

  d4=(800-(x3+570+80))/13;
  x0=x3+570+80;

  cairo_move_to (cr, x0, y+25);

  cairo_line_to (cr, x0+d4, y);
  cairo_line_to (cr, x0+2*d4, y+50);
  cairo_line_to (cr, x0+3*d4, y);
  cairo_line_to (cr, x0+4*d4, y+50);
  cairo_line_to (cr, x0+5*d4, y);
  cairo_line_to (cr, x0+6*d4, y+50);
  cairo_line_to (cr, x0+7*d4, y);
  cairo_line_to (cr, x0+8*d4, y+50);
  cairo_line_to (cr, x0+9*d4, y);
  cairo_line_to (cr, x0+10*d4, y+50);
  cairo_line_to (cr, x0+11*d4, y);
  cairo_line_to (cr, x0+12*d4, y+50);
  cairo_line_to (cr, x0+13*d4, y+25);
  cairo_stroke(cr);

  a1= -(2*w*(x1))+w*(x2)+(f0/m)*cos(sqrt(w)*t);
  t=t+dt;
  a2= w*(x1)-2*w*(x2)+w*(x3);
  a3= w*(x2)-2*w*(x3);

  v1=v1+a1*dt;
  v2=v2+a2*dt;
  v3=v3+a3*dt;
  
   if(c<700)
    {
      vvgraph1[c]=v1;
      vvgraph2[c]=v2;
      vvgraph3[c]=v3;
    }
  else
    {
      for(i=1; i<=c; ++i)
	{
	  vvgraph1[i-1]=vvgraph1[i];
	  vvgraph2[i-1]=vvgraph2[i];
	  vvgraph3[i-1]=vvgraph3[i];	  
	}
      vvgraph1[c-1]=v1;
      vvgraph2[c-1]=v2;
      vvgraph3[c-1]=v3;
    }

  
  x1=x1+v1*dt;
  x2=x2+v2*dt;
  x3=x3+v3*dt;
  
  if(c<700)
    {
      vgraph1[c]=x1;
      vgraph2[c]=x2;
      vgraph3[c]=x3;
    }
   else
    {
  	{
	  for(i=0; i<=c; ++i)
	    {
	      vgraph1[i-1]=vgraph1[i];
	      vgraph2[i-1]=vgraph2[i];
	      vgraph3[i-1]=vgraph3[i];  
	    }
	  vgraph1[c-1]=x1;
	  vgraph2[c-1]=x2;
	  vgraph3[c-1]=x3;
	}
    }
  
  if(c<700)
      c=c+1;
    else
      c=700;
  
    return FALSE;
}

gboolean graph1 (GtkWidget *widget, cairo_t *cr, gpointer data)
{
      
  eyy=gtk_range_get_value (GTK_RANGE(yy));
  exx=gtk_range_get_value (GTK_RANGE(xx));
  
  cairo_set_source_rgb (cr, 0., 0., 0.);
  cairo_set_line_width (cr, 1.0);

  cairo_move_to (cr, 2, 0);
  cairo_line_to (cr, 2, 800);
  cairo_stroke(cr);

  cairo_move_to (cr, 0, 205);
  cairo_line_to (cr, 800, 205);
  cairo_stroke(cr);

  cairo_move_to (cr, 770, 220);
  cairo_select_font_face (cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size (cr, 15);
  cairo_set_source_rgb (cr, 0., 0., 0.);
  strcpy (texto, "t(s)");
  cairo_show_text (cr, texto);

  cairo_move_to (cr, 5, 20);
  strcpy (texto, "x(m)");
  cairo_show_text (cr, texto);
  cairo_stroke (cr);

  //grafico posicao 1
  if(vgp1==TRUE)
    {
      cairo_set_source_rgb (cr, 0.5, 0.2, 0.2);
      cairo_set_line_width (cr, 3.0);
      
      if(vgraph1[0]!=0)
	{
	  if((c-(700/exx))>=0)
	    cairo_move_to (cr, 0, (yini+(vgraph1[(int) (c-(700/exx)-1)]))*eyy);
	  else
	    cairo_move_to (cr, 0, (yini+(vgraph1[0]))*eyy);
	}

      t2=0;

      if((c-(700/exx))>=0)
      for(i=(int) (c-(700/exx)); (i<(c-1) && r!=1) ; ++i)
	{
	  if(vgraph1[i]!=0)
	    {
	      cairo_line_to (cr, t2, yini+((vgraph1[i])*eyy));
	      t2=t2+exx;
	    }
	}
      else
	 for(i=0; (i<(c-1) && r!=1) ; ++i)
	{
	  if(vgraph1[i]!=0)
	    {
	      cairo_line_to (cr, t2, yini+((vgraph1[i])*eyy));
	      t2=t2+exx;
	    }
	}

      cairo_stroke (cr);
    }

  //grafico posicao 2
  if (vgp2==TRUE)
    {
      cairo_set_source_rgb (cr, 0., 0.4, 0.4);
      cairo_set_line_width (cr, 3.0);

      if(vgraph2[0]!=0)
	{
	  if((c-(700/exx))>=0)
	    cairo_move_to (cr, 0, (yini+(vgraph2[(int) (c-(700/exx)-1)]))*eyy);
	  else
	    cairo_move_to (cr, 0, (yini+(vgraph2[0]))*eyy);
	}

      t2=0;
      if((c-(700/exx))>=0)
	for(i=(int) (c-(700/exx)); (i<(c-1) && r!=1); ++i)
	  {
	    if (vgraph2[i]!=0)
	    {
		cairo_line_to (cr, t2, (yini+((vgraph2[i]))*eyy));
		t2=t2+exx;
	     }
	  }
      else
	for(i=0; (i<(c-1) && r!=1) ; ++i)
	  {
	    if(vgraph2[i]!=0)
	      {
		cairo_line_to (cr, t2, yini+((vgraph2[i])*eyy));
		t2=t2+exx;
	      }
	  }
      cairo_stroke (cr);
    }
  
  //grafico posicao 3
  if (vgp3==TRUE)
    {
      cairo_set_source_rgb (cr, 0.1, 0.2, 0.6);
      cairo_set_line_width (cr, 3.0);

      if(vgraph1[0]!=0)
	{
	  if((c-(700/exx))>=0)
	    cairo_move_to (cr, 0, (yini+(vgraph2[(int) (c-(700/exx)-1)]))*eyy);
	  else
	    cairo_move_to (cr, 0, (yini+(vgraph2[0]))*eyy);
	}
      
      t2=0;
      if((c-(700/exx))>=0)
	for(i=(int) (c-(700/exx)); (i<(c-1) && r!=1) ; ++i)
	  {
	    if(vgraph3[i]!=0)
	      {
		cairo_line_to (cr, t2, yini+((vgraph3[i])*eyy));
		t2=t2+exx;
	      }
	  }
      else
	for(i=1; (i<c && r!=1); ++i)
	  {
	    if(vgraph3[i]!=0)
	      {
		cairo_line_to (cr, t2, yini+((vgraph3[i])*eyy));
		t2=t2+exx;
	      }
	  }
      cairo_stroke (cr);
    }

  return FALSE;
}

gboolean graph2 (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  eyy=gtk_range_get_value (GTK_RANGE(yy));
  exx=gtk_range_get_value (GTK_RANGE(xx));
  
  cairo_set_source_rgb (cr, 0., 0., 0.);
  cairo_set_line_width (cr, 1.0);

  cairo_move_to (cr, 400, 0);
  cairo_line_to (cr, 400, 800);
  cairo_stroke(cr);

  cairo_move_to (cr, 0, 205);
  cairo_line_to (cr, 800, 205);
  cairo_stroke(cr);

  cairo_move_to (cr, 770, 220);
  cairo_select_font_face (cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size (cr, 15);
  cairo_set_source_rgb (cr, 0., 0., 0.);
  strcpy (texto, "x(m)");
  cairo_show_text (cr, texto);

  cairo_move_to (cr, 405, 20);
  strcpy (texto, "v(m/s)");
  cairo_show_text (cr, texto);
  cairo_stroke (cr);

  //grafico velocidade 1
  cairo_set_source_rgb (cr, 0.5, 0.2, 0.2);
  cairo_set_line_width (cr, 3.0);
  if(vgv1==FALSE)
    cairo_set_line_width (cr, 0.);

  if (vgraph1[0]!=0 && vvgraph1[0]!=0)
    cairo_move_to (cr, (vgraph1[1]*exx)+400, yini+(vvgraph1[1]*eyy));

  for(i=0; (i<c && r!=1); ++i)
    {
      if(vgraph1[i]!=0 && vvgraph1[i]!=0)
	{
	  cairo_line_to (cr, 400+(vgraph1[i]*exx), yini+((vvgraph1[i])*eyy));
	}
    }

  cairo_stroke (cr);

   //grafico velocidade 2
  cairo_set_source_rgb (cr, 0., 0.4, 0.4);
  cairo_set_line_width (cr, 3.0);
  if(vgv2==FALSE)
    cairo_set_line_width (cr, 0.);

  if (vgraph2[0]!=0 && vvgraph2[0]!=0)
    cairo_move_to (cr, (vgraph2[0]*exx)+400, yini+(vvgraph2[0]*eyy));

  for(i=0; (i<c && r!=1); ++i)
    {
      if(vgraph2[i]!=0 && vvgraph2[i]!=0)
	{
	  cairo_line_to (cr, 400+(vgraph2[i]*exx), yini+((vvgraph2[i])*eyy));
	}
    }

  cairo_stroke (cr);
  
 //grafico velocidade 3
  cairo_set_source_rgb (cr, 0.1, 0.2, 0.6);
  cairo_set_line_width (cr, 3.0);
  if(vgv3==FALSE)
    cairo_set_line_width (cr, 0.);

  if (vgraph3[0]!=0 && vvgraph3[0]!=0)
    cairo_move_to (cr, (vgraph3[0]*exx)+400, yini+(vvgraph3[0]*eyy));

  for(i=0; (i<c && r!=1); ++i)
    {
      if(vgraph3[i]!=0 && vvgraph3[i]!=0)
	{
	  cairo_line_to (cr, 400+(vgraph3[i]*exx), yini+((vvgraph3[i])*eyy));
	}
    }
   
  cairo_stroke (cr);
  
  
  return TRUE;
}


gboolean funcdesenho()
{
  if(p==0)
    {
      gtk_widget_queue_draw (area);
      gtk_widget_queue_draw (graph1_area);
      gtk_widget_queue_draw (graph2_area);      
    }
  
  return TRUE;
}

void escalas (int esc)
{ 
  if (escp==1)
    {
     gtk_range_set_value (GTK_RANGE (yy), 20);
      gtk_range_set_value (GTK_RANGE (xx), 1);
    }

  if(escv==1)
    {
      gtk_range_set_value (GTK_RANGE (yy), 2);
      gtk_range_set_value (GTK_RANGE (xx), 17);
    }
}

  
gboolean visibilidade ()
{
  vgp1=gtk_switch_get_active (GTK_SWITCH (gpos1));
  vgp2=gtk_switch_get_active (GTK_SWITCH (gpos2));
  vgp3=gtk_switch_get_active (GTK_SWITCH (gpos3));
  vgv1=gtk_switch_get_active (GTK_SWITCH (gvel1));
  vgv2=gtk_switch_get_active (GTK_SWITCH (gvel2));
  vgv3=gtk_switch_get_active (GTK_SWITCH (gvel3));

  if(strcmp (gtk_stack_get_visible_child_name (GTK_STACK (stack)), "posicao")==0)
    {
      escv=0;
      escp=escp+1;
      gtk_widget_set_sensitive (gvel1, FALSE);
      gtk_widget_set_sensitive (gvel2, FALSE);
      gtk_widget_set_sensitive (gvel3, FALSE);
      gtk_widget_set_sensitive (gpos1, TRUE);
      gtk_widget_set_sensitive (gpos2, TRUE);
      gtk_widget_set_sensitive (gpos3, TRUE);
      escalas (escp);
    }
  else if (strcmp (gtk_stack_get_visible_child_name (GTK_STACK (stack)), "velocidade")==0)
    {
      escp=0;
      escv=escv+1;
      gtk_widget_set_sensitive (gvel1, TRUE);
      gtk_widget_set_sensitive (gvel2, TRUE);
      gtk_widget_set_sensitive (gvel3, TRUE);
      gtk_widget_set_sensitive (gpos1, FALSE);
      gtk_widget_set_sensitive (gpos2, FALSE);
      gtk_widget_set_sensitive (gpos3, FALSE);
      escalas (escv);
      }

  return TRUE;
}


void controle ()
{
  if (s==0)
    {
      gtk_widget_set_sensitive (pos1, FALSE);
      gtk_widget_set_sensitive (pos2, FALSE);
      gtk_widget_set_sensitive (pos3, FALSE);
      gtk_widget_set_sensitive (vel1, FALSE);
      gtk_widget_set_sensitive (vel2, FALSE);
      gtk_widget_set_sensitive (vel3, FALSE);
      gtk_widget_set_sensitive (forca, FALSE);
      gtk_widget_set_sensitive (comecar1, FALSE);      
    }
  else 
    {
      gtk_widget_set_sensitive (pos1, TRUE);
      gtk_widget_set_sensitive (pos2, TRUE);
      gtk_widget_set_sensitive (pos3, TRUE);
      gtk_widget_set_sensitive (vel1, TRUE);
      gtk_widget_set_sensitive (vel2, TRUE);
      gtk_widget_set_sensitive (vel3, TRUE);
      gtk_widget_set_sensitive (forca, TRUE);
      gtk_widget_set_sensitive (comecar1, TRUE);      
    }

  if (r==1)
    {
      for (i=0; i<701;++i)
	{
	  vgraph1[i]=0;
	  vgraph2[i]=0;
	  vgraph3[i]=0;
	  vvgraph1[i]=0;
	  vvgraph2[i]=0;
	  vvgraph3[i]=0;
	}

      gtk_spin_button_set_value (GTK_SPIN_BUTTON (massa), 10);
      gtk_spin_button_set_value (GTK_SPIN_BUTTON (cte_elas), 100);
      gtk_spin_button_set_value (GTK_SPIN_BUTTON (pos1), -5);
      gtk_spin_button_set_value (GTK_SPIN_BUTTON (pos2), 5);
      gtk_spin_button_set_value (GTK_SPIN_BUTTON (pos3), 5);
      gtk_spin_button_set_value (GTK_SPIN_BUTTON (vel1), 0);
      gtk_spin_button_set_value (GTK_SPIN_BUTTON (vel2), 0);
      gtk_spin_button_set_value (GTK_SPIN_BUTTON (vel3), 0);
      gtk_spin_button_set_value (GTK_SPIN_BUTTON (forca), 0);
      gtk_range_set_value (GTK_RANGE (yy), 20);
      gtk_range_set_value (GTK_RANGE (xx), 1);
      gtk_range_set_value (GTK_RANGE (velocidade), 0.02);
    }

  if(g==1 && g1==1)
    {
      m=gtk_spin_button_get_value (GTK_SPIN_BUTTON (massa));
      k=gtk_spin_button_get_value (GTK_SPIN_BUTTON (cte_elas));
      x1=(gtk_spin_button_get_value (GTK_SPIN_BUTTON (pos1)));
      x2=(gtk_spin_button_get_value (GTK_SPIN_BUTTON (pos2)));
      x3=(gtk_spin_button_get_value (GTK_SPIN_BUTTON (pos3)));
      v1=gtk_spin_button_get_value (GTK_SPIN_BUTTON (vel1));
      v2=gtk_spin_button_get_value (GTK_SPIN_BUTTON (vel2));
      v3=gtk_spin_button_get_value (GTK_SPIN_BUTTON (vel3));
      f0=gtk_spin_button_get_value (GTK_SPIN_BUTTON (forca));
      exx=gtk_range_get_value (GTK_RANGE(xx));
      eyy=gtk_range_get_value (GTK_RANGE(yy));
      dt=gtk_range_get_value (GTK_RANGE (velocidade));
    }
    
  if (p==1)
    gtk_widget_set_sensitive (comecar1, TRUE);
  else if (p==0)
    g_timeout_add (1, (GSourceFunc) funcdesenho, NULL);
  
}


void comecar()
{
  g=1;
  s=0;
  p=0;
  r=0;

  if (g==1 && fr==1)
    {
      m=gtk_spin_button_get_value (GTK_SPIN_BUTTON (massa));
      k=gtk_spin_button_get_value (GTK_SPIN_BUTTON (cte_elas));
      x1=gtk_spin_button_get_value (GTK_SPIN_BUTTON (pos1));
      x2=gtk_spin_button_get_value (GTK_SPIN_BUTTON (pos2));
      x3=gtk_spin_button_get_value (GTK_SPIN_BUTTON (pos3));
      v1=gtk_spin_button_get_value (GTK_SPIN_BUTTON (vel1));
      v2=gtk_spin_button_get_value (GTK_SPIN_BUTTON (vel2));
      v3=gtk_spin_button_get_value (GTK_SPIN_BUTTON (vel3));
      f0=gtk_spin_button_get_value (GTK_SPIN_BUTTON (forca));
      exx=gtk_range_get_value (GTK_RANGE(xx));
      gtk_range_set_value (GTK_RANGE(yy), 20);
      eyy=gtk_range_get_value (GTK_RANGE(yy));
      dt=gtk_range_get_value (GTK_RANGE (velocidade));
    }
  controle();
}

void pausar ()
{
  g=0;
  fr=0;
  g1=0;
  p=1;
  r=0;
  s=0;
  controle();
}

void freiniciar ()
{
  g=0;
  g1=0;
  p=1;
  r=1;
  s=1;
  fr=1;
  controle();
}

int main(int argc, char**argv)
{ 
  gtk_init (&argc, &argv);
  
  window= gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(window), 1200, 800);
  gtk_window_set_resizable (GTK_WINDOW(window), FALSE);
  gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_title (GTK_WINDOW(window), "Sistema de quatro molas e três massas sujeito a uma força exterior");

  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);

  //gtk_window_get_size (GTK_WINDOW(window), &width, &height);
  
  box= gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (box), 5);
  gtk_container_add (GTK_CONTAINER (window), box);

  //box da vertical da esquerda
  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_start (GTK_BOX(box), vbox, FALSE, FALSE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox), 2.5);
  gtk_widget_set_size_request (vbox, 800, 750);

  //box vertical da direita
  vbox1 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_start (GTK_BOX(box), vbox1, TRUE, TRUE, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox1), 2.5);

  //box do desenho
  hbox = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0); 
  gtk_box_pack_start (GTK_BOX(vbox), hbox, FALSE, FALSE, 0);
  gtk_widget_set_size_request (hbox, 800, 395);

  //box dos gráficos
  hbox1 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0); 
  gtk_box_pack_start (GTK_BOX(vbox), hbox1, TRUE, TRUE, 5);

  //frame do desenho
  frame = gtk_frame_new ("Simulação");
  gtk_box_pack_start (GTK_BOX (hbox), frame, TRUE, TRUE, 0);
  box_cores = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add (GTK_CONTAINER (frame), box_cores);

  box_desenho= gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX (box_cores), box_desenho, FALSE, FALSE, 0);
  gtk_widget_set_size_request (box_desenho, 800, 375);

  box_cores2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX (box_cores), box_cores2, TRUE, TRUE, 0);
   cores=gtk_color_chooser_dialog_new ("Cores", GTK_WINDOW (window));

  
  area= gtk_drawing_area_new();
  gtk_box_pack_start (GTK_BOX (box_desenho), area, TRUE, TRUE, 0);

  g_signal_connect (G_OBJECT(area), "draw", G_CALLBACK(desenho), area);


  //frame das condições
  frame1 = gtk_frame_new ("Condições");
  gtk_box_pack_start (GTK_BOX (vbox1), frame1, TRUE, TRUE, 0);
  bframe1 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (frame1), bframe1);

  
  /*//HELP
  hhelp= gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX(bframe1), hhelp, FALSE, FALSE, 0);
  vhelp= gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_end (GTK_BOX(hhelp), vhelp, FALSE, FALSE,0);
  help= gtk_button_new_with_label ("Ajuda");
  gtk_container_add (GTK_CONTAINER (vhelp), help);
  g_signal_connect (help, "clicked", G_CALLBACK(fhelp), NULL);*/

  //botoes condicoes
  bhcondicao= gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX (bframe1), bhcondicao, FALSE, FALSE, 20);

  bcondicao= gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_start (GTK_BOX (bhcondicao), bcondicao, FALSE, FALSE, 0);
  gtk_widget_set_size_request (bcondicao, 200, 700);
  
  lmassa= gtk_label_new ("Massa");
  gtk_container_add (GTK_CONTAINER (bcondicao), lmassa);
  massa=gtk_spin_button_new_with_range (1, 30, 1);
  gtk_container_add (GTK_CONTAINER (bcondicao), massa);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (massa), 10);
  
  lpos1= gtk_label_new ("\n\n\nPosição inicial bloco 1");
  gtk_container_add (GTK_CONTAINER (bcondicao), lpos1);
  pos1=gtk_spin_button_new_with_range (-130, 140, 1);
  gtk_container_add (GTK_CONTAINER (bcondicao), pos1);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (pos1), -5);

  lpos2= gtk_label_new ("\n\n\nPosição inicial bloco 2");
  gtk_container_add (GTK_CONTAINER (bcondicao), lpos2);
  pos2=gtk_spin_button_new_with_range (-140, 140 , 1);
  gtk_container_add (GTK_CONTAINER (bcondicao), pos2);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (pos2), 5);
  
  lpos3= gtk_label_new ("\n\n\nPosição inicial bloco 3");
  gtk_container_add (GTK_CONTAINER (bcondicao), lpos3);
  pos3=gtk_spin_button_new_with_range (-140, 150, 1);
  gtk_container_add (GTK_CONTAINER (bcondicao), pos3);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (pos3), 5);
  
  lforca= gtk_label_new ("\n\nForça");
  gtk_container_add (GTK_CONTAINER (bcondicao), lforca);
  forca=gtk_spin_button_new_with_range (0, 1000, 1);
  gtk_container_add (GTK_CONTAINER (bcondicao), forca);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (forca), 0);

  lxx= gtk_label_new ("\nEscala do xx");
  gtk_container_add (GTK_CONTAINER (bcondicao), lxx);
  xx=gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, 1, 20, 0.25);
  gtk_container_add (GTK_CONTAINER (bcondicao), xx);      
  gtk_scale_set_draw_value (GTK_SCALE(xx), FALSE);
  gtk_range_set_value (GTK_RANGE (xx), 1);
  
  bcondicao2= gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_start (GTK_BOX (bhcondicao), bcondicao2, TRUE, TRUE, 0);
  
  lcte_elas= gtk_label_new ("Constante de elasticidade");
  gtk_container_add (GTK_CONTAINER (bcondicao2), lcte_elas);
  cte_elas=gtk_spin_button_new_with_range (1, 1000 , 1);
  gtk_container_add (GTK_CONTAINER (bcondicao2), cte_elas);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (cte_elas), 100);
  
  lvel1= gtk_label_new ("\n\n\nVelocidade inicial bloco 1");
  gtk_container_add (GTK_CONTAINER (bcondicao2), lvel1);
  vel1=gtk_spin_button_new_with_range (-10, 10, 0.01);
  gtk_container_add (GTK_CONTAINER (bcondicao2), vel1);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (vel1), 0);
  
  lvel2= gtk_label_new ("\n\n\nVelocidade inicial bloco 2");
  gtk_container_add (GTK_CONTAINER (bcondicao2), lvel2);
  vel2=gtk_spin_button_new_with_range (-10, 10, 0.01);
  gtk_container_add (GTK_CONTAINER (bcondicao2), vel2);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (vel2), 0);

  lvel3= gtk_label_new ("\n\n\nVelocidade inicial bloco 3");
  gtk_container_add (GTK_CONTAINER (bcondicao2), lvel3);
  vel3=gtk_spin_button_new_with_range (-10, 10, 0.01 );
  gtk_container_add (GTK_CONTAINER (bcondicao2), vel3);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (vel3), 0);

  lvelocidade= gtk_label_new ("\n\nVelocidade da simulação");
  gtk_container_add (GTK_CONTAINER (bcondicao2), lvelocidade);
  velocidade=gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, 0.001, 0.1, 0.001);
  gtk_container_add (GTK_CONTAINER (bcondicao2), velocidade);
  gtk_scale_set_draw_value (GTK_SCALE(velocidade), FALSE);
  gtk_range_set_value (GTK_RANGE (velocidade), 0.02);

  lyy= gtk_label_new ("\n\nEscala do yy");
  gtk_container_add (GTK_CONTAINER (bcondicao2), lyy);
  yy=gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, 0.01, 50, 0.05);
  gtk_container_add (GTK_CONTAINER (bcondicao2), yy);
  gtk_scale_set_draw_value (GTK_SCALE(yy), FALSE);
  gtk_range_set_value (GTK_RANGE (yy), 20);

  //botoes controlo graficos
  framecg=gtk_frame_new ("Visibilidade dos gráficos x(t)");
  gtk_box_pack_start (GTK_BOX (bcondicao), framecg, TRUE, TRUE, 25);
  bframecg=gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (framecg), bframecg);

  framecgv=gtk_frame_new ("Visibilidade dos gráficos v(x)");
  gtk_box_pack_start (GTK_BOX (bcondicao2), framecgv, TRUE, TRUE, 16);
  bframecgv=gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (framecgv), bframecgv);

  lgpos1= gtk_label_new ("Bloco 1");
  gtk_container_add (GTK_CONTAINER (bframecg), lgpos1);
  gpos1=gtk_switch_new();
  gtk_container_add (GTK_CONTAINER (bframecg), gpos1);
  gtk_switch_set_active (GTK_SWITCH (gpos1), TRUE);

  lgpos2= gtk_label_new ("Bloco 2");
  gtk_container_add (GTK_CONTAINER (bframecg), lgpos2);
  gpos2=gtk_switch_new();
  gtk_container_add (GTK_CONTAINER (bframecg), gpos2);
  gtk_switch_set_active (GTK_SWITCH (gpos2), TRUE);

  lgpos3= gtk_label_new ("Bloco 3");
  gtk_container_add (GTK_CONTAINER (bframecg), lgpos3);
  gpos3=gtk_switch_new();
  gtk_container_add (GTK_CONTAINER (bframecg), gpos3);
  gtk_switch_set_active (GTK_SWITCH (gpos3), TRUE);

  lgvel1= gtk_label_new ("\nBloco 1");
  gtk_container_add (GTK_CONTAINER (bframecgv), lgvel1);
  gvel1=gtk_switch_new();
  gtk_container_add (GTK_CONTAINER (bframecgv), gvel1);
  gtk_switch_set_active (GTK_SWITCH (gvel1), TRUE);

  lgvel2= gtk_label_new ("Bloco 2");
  gtk_container_add (GTK_CONTAINER (bframecgv), lgvel2);
  gvel2=gtk_switch_new();
  gtk_container_add (GTK_CONTAINER (bframecgv), gvel2);
  gtk_switch_set_active (GTK_SWITCH (gvel2), FALSE);

  lgvel3= gtk_label_new ("Bloco 3");
  gtk_container_add (GTK_CONTAINER (bframecgv), lgvel3);
  gvel3=gtk_switch_new();
  gtk_container_add (GTK_CONTAINER (bframecgv), gvel3);
  gtk_switch_set_active (GTK_SWITCH (gvel3), FALSE);
  
  
  //comecar, pausar
  bcomecar= gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_end (GTK_BOX(bframe1), bcomecar, FALSE, FALSE, 0);

  comecar1=gtk_button_new_with_label ("Começar");
  gtk_container_add (GTK_CONTAINER (bcomecar), comecar1);
  gtk_widget_set_size_request (comecar1, 133, 60);
  g_signal_connect (comecar1, "clicked", G_CALLBACK(comecar), NULL);

  parar=gtk_button_new_with_label ("Parar");
  gtk_container_add (GTK_CONTAINER (bcomecar), parar);
  gtk_widget_set_size_request (parar, 133, 60);
  g_signal_connect (parar, "clicked", G_CALLBACK(pausar), NULL);

  reiniciar= gtk_button_new_with_label ("Reiniciar");
  gtk_container_add (GTK_CONTAINER (bcomecar), reiniciar);
  gtk_widget_set_size_request (reiniciar, 133, 60);
  g_signal_connect (reiniciar, "clicked", G_CALLBACK(freiniciar), NULL);
  
  // frame dos gráficos
  vhbox1 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_start (GTK_BOX (hbox1), vhbox1, TRUE, TRUE, 0);
  
  frame2 = gtk_frame_new (NULL);
  graph1_area= gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER (frame2), graph1_area);
  g_signal_connect (G_OBJECT(graph1_area), "draw", G_CALLBACK(graph1), graph1_area);
  
  frame3 = gtk_frame_new (NULL);
  graph2_area = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER (frame3), graph2_area);
  g_signal_connect (G_OBJECT(graph2_area), "draw", G_CALLBACK(graph2), graph2_area);

  stack= gtk_stack_new ();
  switcher = gtk_stack_switcher_new ();
  gtk_stack_switcher_set_stack (GTK_STACK_SWITCHER (switcher), GTK_STACK (stack));
  gtk_box_pack_start (GTK_BOX (vhbox1), stack, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (vhbox1), switcher, FALSE, TRUE, 0);
  gtk_widget_set_size_request (switcher, 800, 30);
  gtk_stack_add_titled (GTK_STACK (stack), frame2,"posicao", "  x(t)  ");
  gtk_stack_add_titled (GTK_STACK (stack), frame3,"velocidade", "  v(x)  ");
  gtk_stack_set_visible_child (GTK_STACK(stack), frame2);
  gtk_stack_set_visible_child_name (GTK_STACK(stack), "posicao");

  g_timeout_add (1, (GSourceFunc) visibilidade, NULL);

  gtk_widget_show_all (window);

  gtk_main ();

}
