#include <stdio.h>
#include <gtk/gtk.h>
#include <cairo.h>
#include <math.h>
#include <string.h>

//Gráfico v(x): janela adicional?


gdouble xlen=1200, ylen=800;
gchar str1[80]="Simulação de sistema composto por massa-mola + massa adicional";
gchar str2[48]="Gráfico v(x) para as massas M1 e M2";
gdouble v1=-1000.,dt=0.001,k=2500,m=5,ScaleInitValue=0;//k=64*6,m=6.//v1=1.0.
gint n_digits=2, n_show_value=1, mov=0;
gdouble disp=0, maxscale=-700;
gdouble pos1x = 120+30.; //(30 iniciais +60).
gdouble x=90+250.; //(30+250 inicias +60).
gdouble pos1y = 50.;
//0, maxscale, 0, 1, 1.
gdouble mheight=    13.;
gdouble mwidth=     14.;
gdouble M1INICIAL   =5;
gdouble M2INICIAL   =5;
gdouble LINICIAL    =0.00;
gdouble lINICIAL    =13;
gdouble KINICIAL    =1000;
gdouble NIUINICIAL  =0.50;//12*8.
gdouble X1INICIAL   =13;
gdouble X2INICIAL   =0;
gdouble V1INICIAL   =-1000.0;
gdouble V2INICIAL   =10000.0;
gdouble v2          =10000.0;
gdouble m2          =5;
gdouble niu         =0.50;
gdouble x2i         =0;
gint parede2ch      =0;
gdouble v2i         =0;
gdouble graphx1[701];
gdouble graphx2[701];
gdouble graphv1[701];
gdouble graphv2[701];
gint c=0, cc=0;
gint r=1, rr=1;
gdouble t2=0, tt2=0;
gdouble exx, ex=0.5;
gdouble eyy, ey=0.01;
gdouble yi= 180, yyi= 225;
GtkWidget *GRAPH_X, *GRAPH_V;
GtkWidget *FRAME_X,*FRAME_V,*STACK_G,*SWITCH_G,*VBOX_G;
GtkWidget *FG_ESQUERDA,*BOX_FG,*LG_M1,*SWITCH_M1,*FG_DIREITA,*BOX_FG2,*LG_M1_2,*SWITCH_M1_2,*LG_M2,*SWITCH_M2,*LG_M2_2,*SWITCH_M2_2;
gboolean BOOX1, BOOX2, BOOV1, BOOV2, BOO2X1, BOO2X2;
GtkWidget *lxx,*xx,*lyy,*yy;
int z=0;
GtkWidget *tbutton, *SWITCH_1, *SWITCH_2, *scale1, *scale2;


typedef struct {
  GtkWidget *button1;
  GtkWidget *scale;
  GtkAdjustment *adjustment;
  GtkWidget *M1;
  GtkWidget *M2;
  GtkWidget *PAREDES;
  GtkWidget *SPRING;
  GtkWidget *K;
  GtkWidget *AMORT;
  GtkWidget *VM1;
  GtkWidget *VM2;
  GtkWidget *XM1;
  GtkWidget *XM2;
  GtkAdjustment *adjustment2x;
} boo;


void scalev()
{
  if(z<=0)
    {
      z++;
      if(z==1)
	{
	  // gtk_range_set_value (GTK_RANGE (xx), 1);
	  gtk_range_set_value (GTK_RANGE (yy), 0.010);
	}
    }
}

void scalex()
{
  if(z==1)
    {
      z--;
      if(z==0)
	{
	  // gtk_range_set_value (GTK_RANGE (xx), 1);
	  gtk_range_set_value (GTK_RANGE (yy), 0.18);
	}
    }
}


void BOO ()
{
  BOOX1=gtk_switch_get_active (GTK_SWITCH (SWITCH_M1));
  BOOX2=gtk_switch_get_active (GTK_SWITCH (SWITCH_M2));
  BOOV1=gtk_switch_get_active (GTK_SWITCH (SWITCH_M1_2));
  BOOV2=gtk_switch_get_active (GTK_SWITCH (SWITCH_M2_2));
}



void BOO2 ()
{
  BOO2X1=gtk_switch_get_active (GTK_SWITCH (SWITCH_1));
  BOO2X2=gtk_switch_get_active (GTK_SWITCH (SWITCH_2));
}


gchar texto[10];
gboolean graph1 (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  gint i=0;
  eyy=gtk_range_get_value (GTK_RANGE(yy));
  exx=gtk_range_get_value (GTK_RANGE(xx));

  cairo_set_source_rgb (cr, 0., 0., 0.);
  cairo_set_line_width (cr, 1.0);

  cairo_move_to (cr, 2, 5);
  cairo_line_to (cr, 2, 800);
  cairo_stroke(cr);

  cairo_move_to (cr, 0, 180);
  cairo_line_to (cr, 900, 180);
  cairo_stroke(cr);

  cairo_move_to (cr, 885, 175);
  cairo_select_font_face (cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size (cr, 18);
  cairo_set_source_rgb (cr, 0., 0., 0.);
  strcpy (texto, "t");
  cairo_show_text (cr, texto);

  cairo_move_to (cr, 7, 25);
  strcpy (texto, "x(t)");
  cairo_show_text (cr, texto);
  cairo_stroke (cr);

  //Seta(t) :)
  cairo_move_to (cr, 900, 180);
  cairo_rel_line_to(cr, -5, -5);
  cairo_stroke(cr);

  cairo_move_to (cr, 900, 180);
  cairo_rel_line_to(cr, -5, 5);
  cairo_stroke(cr);

  //Seta(x(t)) :)
  cairo_move_to (cr, 2, 5);
  cairo_rel_line_to(cr, 5, 5);
  cairo_stroke(cr);

  cairo_move_to (cr, 2, 5);
  cairo_rel_line_to(cr, -5, 5);
  cairo_stroke(cr);

  cairo_set_font_size (cr, 16);
  cairo_move_to (cr, 6, 197);
  strcpy (texto, "O");
  cairo_show_text (cr, texto);
  cairo_stroke (cr);


  //Gráfico x1(t)
   if(BOOX1==TRUE)
    {
      cairo_set_source_rgb (cr, 0.9, 0.01, 0);
      cairo_set_line_width (cr, 3.0);
      
      if(graphx1[0]!=0)
	{
	  if((c-(700/exx))>=0)
	    cairo_move_to (cr, 0, (yi+(-graphx1[(int) (c-(700/exx)-1)])*eyy));
	  else
	    cairo_move_to (cr, 0, (yi+(-graphx1[0])*eyy));
	}

      t2=0;

      if((c-(700/exx))>=0)
      for(i=(int) (c-(700/exx)); (i<(c-1) && r!=0) ; ++i)
	{
	  if(graphx1[i]!=0)
	    {
	      cairo_line_to (cr, t2, yi+((-graphx1[i])*eyy));
	      t2=t2+exx;
	    }
	}
      else
	 for(i=0; (i<(c-1) && r!=0) ; ++i)
	{
	  if(graphx1[i]!=0)
	    {
	      cairo_line_to (cr, t2, yi+((-graphx1[i])*eyy));
	      t2=t2+exx;
	    }
	}

      cairo_stroke (cr);
    }

   
   //Gráfico x2(t)
   if(BOOX2==TRUE)
    {
      cairo_set_source_rgb (cr, 0, 0.4, 0);
      cairo_set_line_width (cr, 3.0);
      
      if(graphx2[0]!=0)
	{
	  if((c-(700/exx))>=0)
	    cairo_move_to (cr, 0, (yi+(-graphx2[(int) (c-(700/exx)-1)])*eyy));
	  else
	    cairo_move_to (cr, 0, (yi+(-graphx2[0])*eyy));
	}

      t2=0;

      if((c-(700/exx))>=0)
      for(i=(int) (c-(700/exx)); (i<(c-1) && r!=0) ; ++i)
	{
	  if(graphx2[i]!=0)
	    {
	      cairo_line_to (cr, t2, yi+((-graphx2[i])*eyy));
	      t2=t2+exx;
	    }
	}
      else
	 for(i=0; (i<(c-1) && r!=0) ; ++i)
	{
	  if(graphx2[i]!=0)
	    {
	      cairo_line_to (cr, t2, yi+((-graphx2[i])*eyy));
	      t2=t2+exx;
	    }
	}

      cairo_stroke (cr);
    }

   
return FALSE;
}


gboolean graph2 (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  gint i=0;
  eyy=gtk_range_get_value (GTK_RANGE(yy));
  exx=gtk_range_get_value (GTK_RANGE(xx));

  cairo_set_source_rgb (cr, 0., 0., 0.);
  cairo_set_line_width (cr, 1.0);

  cairo_move_to (cr, 2, 5);
  cairo_line_to (cr, 2, 800);
  cairo_stroke(cr);

  cairo_move_to (cr, 0, 180);
  cairo_line_to (cr, 900, 180);
  cairo_stroke(cr);

  cairo_move_to (cr, 885, 175);
  cairo_select_font_face (cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size (cr, 18);
  cairo_set_source_rgb (cr, 0., 0., 0.);
  strcpy (texto, "t");
  cairo_show_text (cr, texto);

  cairo_move_to (cr, 7, 25);
  strcpy (texto, "v(t)");
  cairo_show_text (cr, texto);
  cairo_stroke (cr);

  //Seta(t) :)
  cairo_move_to (cr, 900, 180);
  cairo_rel_line_to(cr, -5, -5);
  cairo_stroke(cr);

  cairo_move_to (cr, 900, 180);
  cairo_rel_line_to(cr, -5, 5);
  cairo_stroke(cr);

  //Seta(x(t)) :)
  cairo_move_to (cr, 2, 5);
  cairo_rel_line_to(cr, 5, 5);
  cairo_stroke(cr);

  cairo_move_to (cr, 2, 5);
  cairo_rel_line_to(cr, -5, 5);
  cairo_stroke(cr);

  cairo_set_font_size (cr, 16);
  cairo_move_to (cr, 6, 197);
  strcpy (texto, "O");
  cairo_show_text (cr, texto);
  cairo_stroke (cr);

  
  //Gráfico v1(t)
   if(BOOV1==TRUE)
    {
      cairo_set_source_rgb (cr, 0.9, 0.01, 0);
      cairo_set_line_width (cr, 3.0);
      
      if(1)
	{
	  if((c-(700/exx))>=0)
	    cairo_move_to (cr, 0, (yi+(-graphv1[(int) (c-(700/exx)-1)])*eyy));
	  else
	    cairo_move_to (cr, 0, (yi+(-graphv1[0])*eyy));
	}

      t2=0;

      if((c-(700/exx))>=0)
      for(i=(int) (c-(700/exx)); (i<(c-1) && r!=0) ; ++i)
	{
	  if(1)//graphv1[i]!=0)
	    {
	      cairo_line_to (cr, t2, yi+((-graphv1[i])*eyy));
	      t2=t2+exx;
	    }
	}
      else
	 for(i=0; (i<(c-1) && r!=0) ; ++i)
	{
	  if(1)
	    {
	      cairo_line_to (cr, t2, yi+((-graphv1[i])*eyy));
	      t2=t2+exx;
	    }
	}

      cairo_stroke (cr);
    }

   
   //Gráfico v2(t)
   if(BOOV2==TRUE)
    {
      cairo_set_source_rgb (cr, 0, 0.4, 0);
      cairo_set_line_width (cr, 3.0);
      
      if(1)
	{
	  if((c-(700/exx))>=0)
	    cairo_move_to (cr, 0, (yi+(-graphv2[(int) (c-(700/exx)-1)])*eyy));
	  else
	    cairo_move_to (cr, 0, (yi+(-graphv2[0])*eyy));
	}

      t2=0;

      if((c-(700/exx))>=0)
      for(i=(int) (c-(700/exx)); (i<(c-1) && r!=0) ; ++i)
	{
	  if(graphv2[i]!=0)
	    {
	      cairo_line_to (cr, t2, yi+((-graphv2[i])*eyy));
	      t2=t2+exx;
	    }
	}
      else
	 for(i=0; (i<(c-1) && r!=0) ; ++i)
	{
	  if(1)
	    {
	      cairo_line_to (cr, t2, yi+((-graphv2[i])*eyy));
	      t2=t2+exx;
	    }
	}

      cairo_stroke (cr);
    }
  
return FALSE;
}

 
GtkWidget *
cria_scale (GtkAdjustment *adjustment)
{
  GtkWidget *w ;

  w = gtk_scale_new(GTK_ORIENTATION_HORIZONTAL, adjustment);
  gtk_scale_set_digits (GTK_SCALE(w), n_digits);
  gtk_scale_set_value_pos (GTK_SCALE(w), GTK_POS_BOTTOM);
  gtk_scale_set_draw_value (GTK_SCALE(w), (n_show_value ? TRUE : FALSE));
  gtk_range_set_value (GTK_RANGE(w), ScaleInitValue);
  gtk_adjustment_set_lower (adjustment, maxscale+x-450+250-11.5);

  return w;
}



gboolean
cb_change_scale (GtkWidget  *w)
{
  disp = gtk_range_get_value (GTK_RANGE(w));

  return FALSE;
}



gboolean
LCHANGE (GtkWidget *w, boo *bu)
{
  gtk_spin_button_set_value ((GtkSpinButton*)bu->PAREDES, disp);

  return FALSE;
}



gboolean
button1click (GtkWidget *b, boo *bu)
{
  gtk_widget_set_sensitive (b, FALSE);
  gtk_widget_set_sensitive (bu->M1, FALSE);
  gtk_widget_set_sensitive (bu->M2, FALSE);
  gtk_widget_set_sensitive (bu->PAREDES, FALSE);
  gtk_widget_set_sensitive (bu->SPRING, FALSE);
  gtk_widget_set_sensitive (bu->K, FALSE);
  gtk_widget_set_sensitive (bu->AMORT, FALSE);
  gtk_widget_set_sensitive (bu->XM1, FALSE);
  gtk_widget_set_sensitive (bu->XM2, FALSE);
  gtk_widget_set_sensitive (bu->VM1, FALSE);
  gtk_widget_set_sensitive (bu->VM2, FALSE);
  gtk_widget_set_sensitive (bu->scale, FALSE);
  mov=1;

  return FALSE;
}

gboolean
button2click (GtkWidget *b, boo *bu)
{
  gtk_widget_set_sensitive (b, TRUE);
  gtk_widget_set_sensitive (bu->button1, TRUE);
  gtk_widget_set_sensitive (bu->scale, TRUE);
  
  if((maxscale+x-450+250-11.5)<=0)
    gtk_adjustment_set_lower (bu->adjustment, maxscale+x-450+250-11.5);
  else
    gtk_adjustment_set_lower (bu->adjustment, 0);
  
  mov=0;
  
  return FALSE;
}


gboolean
button3click (GtkWidget *b, boo *bu)
{
  gint i=0;
  pos1x = 120+30.;
  mheight= 13.;
  x=90+250.;
  disp=0;

  m=5;
  m2=5;
  k=2500;
  niu=0.50;
  v1=-1000;
  v2=10000;
  // X1INICIAL=...
  x2i=0;// X2INCIAL=...
  // V1INICIAL=...
  // V2INICIAL=...

  
  gtk_range_set_value (GTK_RANGE(bu->scale),0);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->M1,M1INICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->M2,M2INICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->PAREDES,LINICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->SPRING,lINICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->K,KINICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->AMORT,NIUINICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->XM1,X1INICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->XM2,X2INICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->VM1,V1INICIAL);
  gtk_spin_button_set_value ((GtkSpinButton*)bu->VM2,V2INICIAL);

  
  gtk_widget_set_sensitive (bu->M1, TRUE);
  gtk_widget_set_sensitive (bu->M2, TRUE);
  //gtk_widget_set_sensitive (bu->PAREDES, TRUE);
  gtk_widget_set_sensitive (bu->SPRING, TRUE);
  gtk_widget_set_sensitive (bu->K, TRUE);
  gtk_widget_set_sensitive (bu->AMORT, TRUE);
  //gtk_widget_set_sensitive (bu->XM1, TRUE);
  gtk_widget_set_sensitive (bu->XM2, TRUE);
  gtk_widget_set_sensitive (bu->VM1, TRUE);
  gtk_widget_set_sensitive (bu->VM2, TRUE);
  gtk_widget_set_sensitive (bu->scale, TRUE);

  c=0;
  for(i=0;i<701;i++)
    {
      graphx1[i]=0;
      graphx2[i]=0;
      graphv1[i]=0;
      graphv2[i]=0;
    }

  //Condição para dar reset nas escalas dos gráficos em xx e em yy.
  if(strcmp(gtk_stack_get_visible_child_name(GTK_STACK(STACK_G)),"Position.")==0)
    {
      gtk_range_set_value (GTK_RANGE (xx), 1);
      gtk_range_set_value (GTK_RANGE (yy), 0.18);
    }

  if(strcmp(gtk_stack_get_visible_child_name(GTK_STACK(STACK_G)),"Velocity.")==0)
    {
      gtk_range_set_value (GTK_RANGE (xx), 1);
      gtk_range_set_value (GTK_RANGE (yy), 0.015);
    }
  
  return FALSE;
}



void
create_other_window (GtkWidget *w, GtkWidget *win)
{                    ;
  GtkWidget    *win2, *button1,*button2, *vbox;

  win2 = gtk_window_new (GTK_WINDOW_POPUP);
  gtk_widget_set_size_request (win2, 300, 100);
  gtk_window_set_position (GTK_WINDOW(win2), GTK_WIN_POS_CENTER);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox), 10);
  gtk_container_add (GTK_CONTAINER (win2), vbox);

  button1 = gtk_button_new_with_label ("Sair");
  gtk_widget_set_size_request (button1, 25, 20);
  gtk_box_pack_start (GTK_BOX(vbox), button1, FALSE, TRUE, 3);
  g_signal_connect (G_OBJECT(button1), "clicked", G_CALLBACK(gtk_main_quit), NULL);

  button2 = gtk_button_new_with_label ("Voltar atrás");
  gtk_widget_set_size_request (button2, 25, 20);
  gtk_box_pack_start (GTK_BOX(vbox), button2, FALSE, TRUE, 2);
  g_signal_connect (G_OBJECT(button2), "clicked", G_CALLBACK(gtk_window_close) , NULL);

  gtk_widget_show_all (win2);
}







void
create_other_window2 (GtkWidget *w, GtkWidget *win)
{                    ;
  GtkWidget    *win2, *button1, *vbox, *label;

  win2 = gtk_window_new (GTK_WINDOW_POPUP);
  gtk_widget_set_size_request (win2, 300, 100);
  gtk_window_set_position (GTK_WINDOW(win2), GTK_WIN_POS_CENTER);

  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (vbox), 10);
  gtk_container_add (GTK_CONTAINER (win2), vbox);

  button1 = gtk_button_new_with_label ("Voltar atrás");
  gtk_widget_set_size_request (button1, 25, 20);
  gtk_box_pack_end (GTK_BOX(vbox), button1, FALSE, TRUE, 2);
  g_signal_connect (G_OBJECT(button1), "clicked", G_CALLBACK(gtk_window_close) , NULL);

  label= gtk_label_new("Este programa funciona do seguinte modo:\n\nÀ direita tem o menu das condições, onde pode fazer variar os seguintes parâmetros:\n-M1: massa de M1;\n-M2: massa de M2;\n-L: distância entre as paredes (utilizar a barra em baixo da simulação);\n-l: distância entre a parede da esquerda e a extremidade da mola;\n-K: Constante de elasticidade da mola;\n-µ: Constante de amortecimento (associada ao movimento de M1);\n-x1i: posição inicial de M1;\n-x2i: posição inicial de M2;\n-v1i: velocidade inicial de M1;\n-v2i: velocidade inicial de M2.\n(Para efeitos desta demonstração, definimos o comprimento natural da mola como igual a 7);\n\nUma vez iniciada a simulação não será possível alterar os valores que a caracterizam até que o botão 'reset' seja primido.\nEm baixo poderá, ainda, vizualizar os gráficos posição-tempo e velocidade-tempo selecionando as opções existentes de acordo com aquilo que pretender.\nO botão mais abaixo permite visualizar o gráfico velocidade-posição.\n\nPara mais informações consultar o manual construído em Latex.");
  gtk_box_pack_start (GTK_BOX(vbox), label, FALSE, FALSE, 2);
  gtk_widget_show_all (win2);
}


void ativar()
{
  gtk_widget_set_sensitive(tbutton, TRUE);
}




gboolean GRAPH_VX (GtkWidget *widget, cairo_t *cr, gpointer data)
{
  gint i=0;
  ey=gtk_range_get_value (GTK_RANGE(scale2));
  ex=gtk_range_get_value (GTK_RANGE(scale1));

  cairo_set_source_rgb (cr, 0., 0., 0.);
  cairo_set_line_width (cr, 1.0);

  cairo_move_to (cr, 150, 5);
  cairo_line_to (cr, 150, 800);
  cairo_stroke(cr);

  cairo_move_to (cr, 2, 225);
  cairo_line_to (cr, 800, 225);
  cairo_stroke(cr);

  cairo_move_to (cr, 783, 175+45);
  cairo_select_font_face (cr, "Arial", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_NORMAL);
  cairo_set_font_size (cr, 18);
  cairo_set_source_rgb (cr, 0., 0., 0.);
  strcpy (texto, "x");
  cairo_show_text (cr, texto);

  cairo_move_to (cr, 7+150, 25);
  strcpy (texto, "v(x)");
  cairo_show_text (cr, texto);
  cairo_stroke (cr);

  //Seta(t) :)
  cairo_move_to (cr, 800, 180+45);
  cairo_rel_line_to(cr, -5, -5);
  cairo_stroke(cr);

  cairo_move_to (cr, 800, 180+45);
  cairo_rel_line_to(cr, -5, 5);
  cairo_stroke(cr);

  //Seta(x(t)) :)
  cairo_move_to (cr, 150, 5);
  cairo_rel_line_to(cr, 5, 5);
  cairo_stroke(cr);

  cairo_move_to (cr, 150, 5);
  cairo_rel_line_to(cr, -5, 5);
  cairo_stroke(cr);

  cairo_set_font_size (cr, 16);
  cairo_move_to (cr, 6+150, 197+45);
  strcpy (texto, "O");
  cairo_show_text (cr, texto);
  cairo_stroke (cr);

  
  //Gráfico v1(x)
  if(BOO2X1==TRUE)
    {
      cairo_set_source_rgb (cr, 0.9, 0.01, 0);
      cairo_set_line_width (cr, 3.0);

      if (1)//graphx1[0]!=0 && graphv1[0]!=0
	cairo_move_to (cr, 150+(graphx1[0]*ex), yyi+(graphv1[0]*ey));

      for(i=0; i<c; ++i)
	{
	  if(1)//graphx1[0]!=0 && graphv1[0]!=0
	    {
	      cairo_line_to (cr, 150+(graphx1[i]*ex), yyi+((graphv1[i])*ey));
	    }
	}
   
  cairo_stroke (cr);
    }

  
  if(BOO2X2==TRUE)
    {
      cairo_set_source_rgb (cr, 0, 0.4, 0);
      cairo_set_line_width (cr, 3.0);

      if (1)//graphx1[0]!=0 && graphv1[0]!=0
	cairo_move_to (cr, 150+(graphx2[0]*ex), yyi+(graphv2[0]*ey));

      for(i=0; i<c; ++i)
	{
	  if(1)//graphx1[0]!=0 && graphv1[0]!=0
	    {
	      cairo_line_to (cr, 150+(graphx2[i]*ex), yyi+((graphv2[i])*ey));
	    }
	}
   
  cairo_stroke (cr);
    }
   
  return FALSE;
}


gboolean
time_handler3 (GtkWidget *widget)
{
  if ((!GTK_IS_WIDGET(widget)) || (!gtk_widget_get_window (widget)))
    return FALSE;

  gtk_widget_queue_draw(widget);

  return TRUE;
}


void
create_other_window3 (GtkWidget *w, GtkWidget *win)
{                 
  GtkWidget    *win2,*button2, *vbox, *hbox2, *framev, *drawv, *framescale, *lx, *ly, *vbox2, *LG_1, *LG_2, *frameb, *vbox3;

  gtk_widget_set_sensitive(tbutton, FALSE);
  win2 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_widget_set_size_request (win2, 1100, 450);
  gtk_window_set_position (GTK_WINDOW(win2), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable((GtkWindow*)win2,FALSE);
  gtk_window_set_title(GTK_WINDOW(win2),str2);

  
  vbox = gtk_box_new (GTK_ORIENTATION_VERTICAL, 10);
  gtk_container_set_border_width (GTK_CONTAINER (vbox), 10);
  gtk_container_add (GTK_CONTAINER (win2), vbox);

  
  hbox2 = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 10);
  gtk_box_pack_start (GTK_BOX (vbox), hbox2, TRUE, TRUE, 0);
  framev = gtk_frame_new ("Gráfico v(x)");
  gtk_box_pack_start (GTK_BOX (hbox2), framev, TRUE, TRUE, 0);
  drawv= gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER (framev), drawv);
  g_signal_connect (G_OBJECT(drawv), "draw", G_CALLBACK(GRAPH_VX), drawv);
  g_timeout_add (1, (GSourceFunc) time_handler3, drawv);
  g_signal_connect(G_OBJECT(drawv), "draw", G_CALLBACK(BOO2),NULL);

  framescale = gtk_frame_new ("Escalas");
  gtk_box_pack_start (GTK_BOX (hbox2), framescale, FALSE, FALSE, 0);
  gtk_widget_set_size_request(framescale, 250,450);
  
  button2 = gtk_button_new_with_label ("Voltar atrás");
  gtk_widget_set_size_request (button2, 25, 20);
  gtk_box_pack_end (GTK_BOX(vbox), button2, FALSE, TRUE, 2);
  g_signal_connect (G_OBJECT(button2), "clicked", G_CALLBACK(gtk_window_close) , NULL);
  g_signal_connect (G_OBJECT(button2), "clicked", G_CALLBACK(ativar) , NULL);
  g_signal_connect (G_OBJECT(win2), "destroy", G_CALLBACK(ativar), NULL);

  vbox2 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 10);
  gtk_container_add (GTK_CONTAINER(framescale), vbox2);
  
  lx= gtk_label_new ("\nEscala do xx");
  gtk_box_pack_start (GTK_BOX(vbox2), lx, FALSE, TRUE, 2);
  scale1=gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, 0.1, 0.65, 0.05);
  gtk_container_add (GTK_CONTAINER (vbox2), scale1);
  gtk_scale_set_draw_value (GTK_SCALE(scale1), TRUE);
  gtk_range_set_value (GTK_RANGE (scale1), 0.5);

  ly= gtk_label_new ("\nEscala do yy");
  gtk_box_pack_start (GTK_BOX(vbox2), ly, FALSE, TRUE, 2);
  scale2=gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, 0.001, 0.100, 0.001);
  gtk_container_add (GTK_CONTAINER (vbox2), scale2);
  gtk_scale_set_draw_value (GTK_SCALE(scale2), TRUE);
  gtk_range_set_value (GTK_RANGE (scale2), 0.01);

  frameb = gtk_frame_new ("Controlo do gráfico v(x)");
  gtk_box_pack_start (GTK_BOX (vbox2), frameb, FALSE, FALSE, 0);

  vbox3= gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_container_add (GTK_CONTAINER (frameb), vbox3);
  
  LG_1= gtk_label_new ("\n\nBloco 1");
  gtk_box_pack_start (GTK_BOX(vbox3), LG_1, FALSE, TRUE, 2);
  SWITCH_1=gtk_switch_new();
  gtk_box_pack_start (GTK_BOX(vbox3), SWITCH_1, FALSE, TRUE, 2);
  gtk_switch_set_active (GTK_SWITCH (SWITCH_1), TRUE);
  gtk_widget_set_size_request(SWITCH_1, 50, 20);
  
  LG_2= gtk_label_new ("\n\nBloco 2");
  gtk_box_pack_start (GTK_BOX(vbox3), LG_2, FALSE, TRUE, 2);
  SWITCH_2=gtk_switch_new();
  gtk_box_pack_start (GTK_BOX(vbox3), SWITCH_2, FALSE, TRUE, 2);
  gtk_switch_set_active (GTK_SWITCH (SWITCH_2), TRUE);
  gtk_widget_set_size_request(SWITCH_2, 50, 20);

  gtk_widget_show_all (win2);
}



gint                win2_xlen = 600 ;
gint                win2_ylen = 400 ;


void
create_about (GtkWidget *w   ,
	      gpointer   win )
{
  GtkWidget    *dialog ;
  GdkPixbuf    *image  ;
  const gchar  *authors[] = {"Afonso \"Hardstuck\" Azenha", "Nuno \"hazboin\" Gonçalves", NULL};
  gchar        *info      = "Este trabalho foi realizado no âmbito da disciplina de Programação.";
  gchar        *copyright = "(c) Todos os direitos reservados para a Boo!!";
  gchar        *website   = "http://label2.tecnico.ulisboa.pt/IC";

  image = gdk_pixbuf_new_from_file ("/home/afonso/Imagens/ist.png", NULL); //É necessário ajustar a diretoria.

  dialog = gtk_about_dialog_new ();
  gtk_window_set_transient_for (GTK_WINDOW(dialog), GTK_WINDOW(win));
  gtk_window_set_default_size (GTK_WINDOW(dialog), win2_xlen, win2_ylen);
  gtk_about_dialog_set_program_name (GTK_ABOUT_DIALOG(dialog), "Sistema Massa-Mola + Massa adicional");
  gtk_about_dialog_set_copyright (GTK_ABOUT_DIALOG(dialog), copyright);
  gtk_about_dialog_set_authors (GTK_ABOUT_DIALOG(dialog), authors);
  gtk_about_dialog_set_comments (GTK_ABOUT_DIALOG(dialog), info);
  gtk_about_dialog_set_logo (GTK_ABOUT_DIALOG(dialog), image);
  gtk_about_dialog_set_website (GTK_ABOUT_DIALOG(dialog), website);
  gtk_about_dialog_set_website_label (GTK_ABOUT_DIALOG(dialog), website);
  g_object_unref (image);

  gtk_dialog_run(GTK_DIALOG (dialog));
  gtk_widget_destroy(dialog);
}


GtkWidget *
cria_toolbar (GtkWidget *window)
{
  GtkWidget *toolbar ;
  GtkToolItem *tb_help, *tb_about, *tb_sep, *tb_exit ;

  toolbar = gtk_toolbar_new ();

  gtk_toolbar_set_style (GTK_TOOLBAR(toolbar), GTK_TOOLBAR_BOTH);
  gtk_toolbar_set_show_arrow (GTK_TOOLBAR(toolbar), TRUE);
  gtk_container_set_border_width(GTK_CONTAINER (toolbar), 0);

  tb_help = gtk_tool_button_new (NULL, "Help");
  gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON(tb_help), "help-contents");
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_help, 0);

  tb_about = gtk_tool_button_new (NULL, "About");
  gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON(tb_about),"help-about");
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_about, 0);

  tb_sep = gtk_separator_tool_item_new ();
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_sep, 0);

  tb_exit = gtk_tool_button_new (NULL, "Sair");
  gtk_tool_button_set_icon_name (GTK_TOOL_BUTTON(tb_exit), "application-exit");
  gtk_toolbar_insert (GTK_TOOLBAR(toolbar), tb_exit, 0);

  g_signal_connect (G_OBJECT(tb_exit), "clicked", G_CALLBACK(create_other_window), NULL);
  g_signal_connect (G_OBJECT(tb_about), "clicked", G_CALLBACK (create_about), window);
  g_signal_connect (G_OBJECT(tb_help), "clicked", G_CALLBACK(create_other_window2), NULL);

  return toolbar;
}




gboolean
buttonsCH (GtkWidget *b, boo *bu)
{
  mheight=gtk_spin_button_get_value_as_int ((GtkSpinButton*)bu->SPRING);
  pos1x=(mheight*10)+20;
  gtk_spin_button_set_value ((GtkSpinButton*)bu->XM1, mheight);
  m=gtk_spin_button_get_value((GtkSpinButton*)bu->M1);
  m2=gtk_spin_button_get_value((GtkSpinButton*)bu->M2);
  k=gtk_spin_button_get_value((GtkSpinButton*)bu->K);
  niu=gtk_spin_button_get_value((GtkSpinButton*)bu->AMORT);
  v1=gtk_spin_button_get_value((GtkSpinButton*)bu->VM1);
  v2=gtk_spin_button_get_value((GtkSpinButton*)bu->VM2);
  x2i= gtk_spin_button_get_value((GtkSpinButton*)bu->XM2);
  gtk_adjustment_set_lower (bu->adjustment, maxscale+x-450+250-11.5+x2i);
  gtk_adjustment_set_lower (bu->adjustment2x, pos1x-150-149.0+0.5);
  
  if(((x+x2i)+45+1)>=(parede2ch-20+disp))
    {
      disp=x+x2i+45+20-parede2ch+1;
    }

  if((pos1x+40+1)>=(x+x2i))
    {
      //x2i=pos1x+40+1-x;
      x2i= pos1x-150-149.;
      gtk_spin_button_set_value ((GtkSpinButton*)bu->XM2, pos1x-150-149.);
    }
    
  
  return FALSE;
  //(30+40)/10;
}




gboolean
cb_draw_event (GtkWidget  *darea ,
               cairo_t    *cr    ,
               gpointer    data  )
{
  static double  y=50+20., dx;
  GtkAllocation alloc1 ;
  gchar texto[48];
  gdouble OMEGA2= k/m;
  gdouble LAMBDA= niu/(2*m);
  gint i=0;

  gtk_widget_get_allocation (darea, &alloc1);
  parede2ch= alloc1.width;
  
  //Background
  cairo_set_source_rgb (cr, 0.0, 0.0, 0.0);
  cairo_paint_with_alpha (cr, 0.2);
  //Border
  cairo_set_source_rgb (cr, 0., 0., 0.);
  cairo_set_line_width (cr, 1.0);
  cairo_rectangle (cr, 0, 0, alloc1.width, alloc1.height);
  cairo_stroke (cr);

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
  cairo_rectangle (cr, alloc1.width-20+disp, 0, 20, alloc1.height);
  cairo_fill_preserve (cr);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke (cr);

  //Massa1
  cairo_set_source_rgb (cr, 0.8-(m/25), 0.64-(m/25), 0.49-(m/25));
  cairo_set_line_width (cr, 1.0);
  cairo_rectangle (cr, (gint) pos1x, (gint) pos1y, 40, 75);
  cairo_fill_preserve (cr);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke (cr);

  //TextoMassa1
  cairo_move_to (cr, (gint) (pos1x+12.5), (gint) pos1y+75+15);
  cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size (cr, 16);
  cairo_set_source_rgb (cr, 0.9, 0.01, 0);
  sprintf (texto, "M1");
  cairo_show_text (cr, texto);

  //Massa2
  cairo_set_source_rgb (cr, 0.8-(m2/25), 0.64-(m2/25), 0.49-(m2/25));
  cairo_set_line_width (cr, 1.0);
  cairo_rectangle (cr, (gint) x+x2i, (gint) y, 45, 30);
  cairo_fill_preserve (cr);
  cairo_set_source_rgb (cr, 0, 0, 0);
  cairo_stroke (cr);

  //TextoMassa2
  cairo_move_to (cr, (gint) (x+12.5+x2i), (gint) y+30+15);
  cairo_select_font_face(cr, "Courier", CAIRO_FONT_SLANT_NORMAL, CAIRO_FONT_WEIGHT_BOLD);
  cairo_set_font_size (cr, 16);
  cairo_set_source_rgb (cr, 0, 0.4, 0);
  sprintf (texto, "M2");
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


  //Actualizacao da posicao(Massa1) (e mola).
  if(mov==1){
    v1= v1-(2*LAMBDA*v1*dt)-(OMEGA2*(pos1x-90)*dt);
    pos1x=(pos1x-90)+(v1*dt)+90;
    
    dx=pos1x-(pos1x+(v1*dt));
    mheight=mheight-(dx/10);
    if(fabs(v1)<=1)
      v1=0;
    if(pos1x<=20)
      v1=-v1;
    
    //Atualização da posição(Massa2).
    if(((x+x2i)+45+1)>=(alloc1.width-20+disp)){ //(x+45+20+65);
      v2=-v2;}
    
    if(((x+x2i)-1)<=(pos1x+40)){
      v2i=v2;
      v2=((2*m)/(m+m2))*v1+((m2-m)/(m+m2))*v2;
      v1=((m-m2)/(m+m2))*v1+((2*m2)/(m+m2))*v2i;}

    x+=(v2*dt);}

  
  if(c<700)
    {
      graphx1[c]=pos1x;
      graphx2[c]=x+x2i;
      graphv1[c]=v1;
      graphv2[c]=v2;
    }
  else
    {
      {
	for(i=0; i<=c; ++i)
	  {
	    graphx1[i-1]=graphx1[i];
	    graphx2[i-1]=graphx2[i];
	    graphv1[i-1]=graphv1[i];
	    graphv2[i-1]=graphv2[i];
	      }
	graphx1[c-1]=pos1x;
	graphx2[c-1]=x+x2i;
	graphv1[c-1]=v1;
	graphv2[c-1]=v2;
      }
    }
  
  if(c<700)
    c=c+1;
  else
    c=700;    

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

gboolean
time_handler2 (GtkWidget *widget)
{

  gtk_widget_queue_draw(widget);

  return TRUE;
}



int main(int argc, char **argv)
{
  GtkWidget *window, *darea,*ANOTHERONE,*BOXDG,*BOX,*BOX_C,*BOX1_D,*FRAME_D,*FRAME_G,*BOX1_G,*BOX2_C,*BOX1_C,*FRAME_C,*LABEL_M1,*LABEL_M2,*LABEL_LP,*LABEL_LS,*LABEL_XM2 ,*LABEL_XM1 ,*LABEL_VM2,*LABEL_VM1 ,*LABEL_AMORT,*LABEL_K, *toolbar, *sep, *VBOX_1, *button2, *button3, *TB_BOX;

  boo buttons;

  buttons.adjustment= gtk_adjustment_new(0, maxscale, 1, 1, 1, 1);
  buttons.adjustment2x= gtk_adjustment_new(0, pos1x-150-149.0, 571.5, 0.5, 1, 1);

  //Inicializar window principal.
  gtk_init (&argc, &argv);
  window= gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size (GTK_WINDOW(window),xlen,ylen);
  gtk_window_set_title(GTK_WINDOW(window),str1);
  gtk_window_set_position (GTK_WINDOW(window), GTK_WIN_POS_CENTER);
  gtk_window_set_resizable ((GtkWindow*)window, FALSE);

  //Box maior
  VBOX_1 = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (VBOX_1), 10);
  gtk_container_add (GTK_CONTAINER (window), VBOX_1);

  //Box principal.
  toolbar = cria_toolbar (window);
  gtk_box_pack_start (GTK_BOX(VBOX_1), toolbar, FALSE, FALSE, 3);

  sep = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  gtk_box_pack_start (GTK_BOX(VBOX_1), sep, FALSE, TRUE, 0);

  BOX = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_set_border_width (GTK_CONTAINER (BOX), 10);
  gtk_box_pack_start(GTK_BOX(VBOX_1), BOX,FALSE,TRUE,3);

  BOXDG = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_start(GTK_BOX(BOX), BOXDG,FALSE,TRUE,3);
  gtk_container_set_border_width (GTK_CONTAINER (BOXDG), 10);


  g_signal_connect (G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), NULL);
  //Frame simulação e simulação.
  FRAME_D = gtk_frame_new ("Simulação.");
  gtk_box_pack_start (GTK_BOX (BOXDG), FRAME_D, FALSE, FALSE, 0);
  BOX1_D = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add (GTK_CONTAINER(FRAME_D), BOX1_D);
  gtk_widget_set_size_request (BOX1_D, 800, 385);
  darea= gtk_drawing_area_new();
  gtk_box_pack_start (GTK_BOX(BOX1_D), darea, TRUE, TRUE, 3);
  g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(cb_draw_event),NULL);
  g_signal_connect(G_OBJECT(darea), "draw", G_CALLBACK(BOO),NULL);
  g_timeout_add (1, (GSourceFunc) time_handler, darea);

  //Scale para o big L;
  buttons.scale = cria_scale (buttons.adjustment);
  gtk_container_add (GTK_CONTAINER (BOXDG), buttons.scale);
  gtk_widget_set_size_request (buttons.scale, 950, 30);
  g_signal_connect (G_OBJECT(buttons.scale), "value-changed", G_CALLBACK(cb_change_scale), buttons.scale);
  g_signal_connect (G_OBJECT(buttons.scale), "value-changed", G_CALLBACK(LCHANGE), &buttons);


  //Frame dos gráficos.
  FRAME_G = gtk_frame_new ("Gráficos.");
  gtk_box_pack_start (GTK_BOX (BOXDG), FRAME_G, FALSE, FALSE, 0);
  BOX1_G = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_container_add (GTK_CONTAINER(FRAME_G), BOX1_G);
  gtk_widget_set_size_request (BOX1_G, 800, 375);



  //Frame das condições
  FRAME_C = gtk_frame_new ("Condições");
  gtk_box_pack_start (GTK_BOX (BOX), FRAME_C, FALSE, FALSE, 0);
 
  BOX_C = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (FRAME_C), BOX_C);
  gtk_widget_set_size_request (BOX_C, 175, 600);
 
  BOX1_C = gtk_box_new (GTK_ORIENTATION_HORIZONTAL, 0);
  gtk_box_pack_start (GTK_BOX (BOX_C), BOX1_C, FALSE, FALSE, 20);

  BOX2_C = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_pack_start (GTK_BOX (BOX1_C), BOX2_C, FALSE, FALSE, 0);
  gtk_widget_set_size_request (BOX2_C, 175, 700);

  ANOTHERONE = gtk_box_new (GTK_ORIENTATION_VERTICAL, 5);
  gtk_box_pack_start (GTK_BOX (BOX1_C), ANOTHERONE, TRUE, TRUE, 5);
  gtk_widget_set_size_request (ANOTHERONE, 175, 600);

  //Condições inciais.
  LABEL_M1= gtk_label_new ("M1:");
  gtk_container_add (GTK_CONTAINER (BOX2_C), LABEL_M1);
  buttons.M1=gtk_spin_button_new_with_range (0.01, 10, 0.01);
  gtk_container_add (GTK_CONTAINER (BOX2_C), buttons.M1);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.M1), M1INICIAL);
  g_signal_connect(G_OBJECT(buttons.M1), "value-changed", G_CALLBACK(buttonsCH),&buttons);
  
  //sep4 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  //gtk_box_pack_end (GTK_BOX(BOX2_C), sep4, FALSE, TRUE,10);

  
  LABEL_M2= gtk_label_new ("M2:");
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), LABEL_M2);
  buttons.M2=gtk_spin_button_new_with_range (0.01, 10, 0.01);
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), buttons.M2);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.M2), M2INICIAL);
  g_signal_connect(G_OBJECT(buttons.M2), "value-changed", G_CALLBACK(buttonsCH),&buttons);

  
  //sep5 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  //gtk_box_pack_end (GTK_BOX(ANOTHERONE), sep5, FALSE, TRUE, 10);


  LABEL_LP= gtk_label_new ("\n\nL:(Usar a barra ao lado)");
  gtk_container_add (GTK_CONTAINER (BOX2_C), LABEL_LP);
  buttons.PAREDES=gtk_spin_button_new_with_range (-1000, 100, 0.01);
  gtk_container_add (GTK_CONTAINER (BOX2_C), buttons.PAREDES);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.PAREDES), LINICIAL);
  gtk_widget_set_sensitive(buttons.PAREDES, FALSE);//Este botão está bloqueado, pois é suposto alterar o L na barra.

  
  LABEL_LS= gtk_label_new ("\n\nl:");
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), LABEL_LS);
  buttons.SPRING=gtk_spin_button_new_with_range (1, 80, 1);//Valor máximo big boy!!
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), buttons.SPRING);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.SPRING), lINICIAL);
  g_signal_connect(G_OBJECT(buttons.SPRING), "value-changed", G_CALLBACK(buttonsCH),&buttons);
  
  LABEL_K= gtk_label_new ("\n\nK:");
  gtk_container_add (GTK_CONTAINER (BOX2_C), LABEL_K);
  buttons.K=gtk_spin_button_new_with_range (1, 5000 , 10);
  gtk_container_add (GTK_CONTAINER (BOX2_C), buttons.K);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.K), KINICIAL);
  g_signal_connect(G_OBJECT(buttons.K), "value-changed", G_CALLBACK(buttonsCH),&buttons);

  LABEL_AMORT= gtk_label_new ("\n\nµ:");
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), LABEL_AMORT);
  buttons.AMORT=gtk_spin_button_new_with_range (0, 2, 0.01);
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), buttons.AMORT);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.AMORT), NIUINICIAL);
  g_signal_connect(G_OBJECT(buttons.AMORT), "value-changed", G_CALLBACK(buttonsCH),&buttons);



  LABEL_VM1= gtk_label_new ("\n\nv1i:");
  gtk_container_add (GTK_CONTAINER (BOX2_C), LABEL_VM1);
  buttons.VM1=gtk_spin_button_new_with_range (-2500, 2500, 25);
  gtk_container_add (GTK_CONTAINER (BOX2_C), buttons.VM1);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.VM1), V1INICIAL);
  g_signal_connect(G_OBJECT(buttons.VM1), "value-changed", G_CALLBACK(buttonsCH),&buttons);
  
  LABEL_VM2= gtk_label_new ("\n\nv2i:");
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), LABEL_VM2);
  buttons.VM2=gtk_spin_button_new_with_range (-10, 10000, 25 );
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), buttons.VM2);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.VM2), V2INICIAL);
  g_signal_connect(G_OBJECT(buttons.VM2), "value-changed", G_CALLBACK(buttonsCH),&buttons);



  LABEL_XM1= gtk_label_new ("\n\nx1i:(Usar o botão l)");
  gtk_container_add (GTK_CONTAINER (BOX2_C), LABEL_XM1);
  buttons.XM1=gtk_spin_button_new_with_range (0, 100, 1);
  gtk_container_add (GTK_CONTAINER (BOX2_C), buttons.XM1);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.XM1), X1INICIAL);
  gtk_widget_set_sensitive(buttons.XM1, FALSE);
  

  
  LABEL_XM2= gtk_label_new ("\n\nx2i:");
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), LABEL_XM2);
  buttons.XM2=gtk_spin_button_new_with_range (-149.0, 571.5, 0.5 );
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), buttons.XM2);
  gtk_spin_button_set_value (GTK_SPIN_BUTTON (buttons.XM2), X2INICIAL);
  gtk_spin_button_set_adjustment ((GtkSpinButton*)buttons.XM2, buttons.adjustment2x);
  g_signal_connect(G_OBJECT(buttons.XM2), "value-changed", G_CALLBACK(buttonsCH),&buttons);

  
  //sep2 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  //gtk_box_pack_start(GTK_BOX(BOX2_C), sep2, FALSE, FALSE, 10);

  //sep3 = gtk_separator_new (GTK_ORIENTATION_HORIZONTAL);
  //gtk_box_pack_start(GTK_BOX(ANOTHERONE), sep3, FALSE, FALSE, 10);

  
  //Botões de controlo da simulação.
  buttons.button1= gtk_button_new_with_label("Começar");
  gtk_box_pack_end(GTK_BOX(BOX_C), buttons.button1, FALSE, FALSE, 5);
  g_signal_connect(G_OBJECT(buttons.button1), "clicked", G_CALLBACK(button1click),&buttons);
  //g_signal_connect(G_OBJECT(buttons.button1), "clicked", G_CALLBACK(BOO),NULL);

  button2= gtk_button_new_with_label("Parar");
  gtk_box_pack_end(GTK_BOX(BOX_C), button2, FALSE, FALSE, 5);
  g_signal_connect(G_OBJECT(button2), "clicked", G_CALLBACK(button2click),&buttons);

  button3= gtk_button_new_with_label("Reset");
  gtk_box_pack_end(GTK_BOX(BOX_C), button3, FALSE, FALSE, 5);
  g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(button3click),&buttons);
  g_signal_connect(G_OBJECT(button3), "clicked", G_CALLBACK(button2click),&buttons);

  
  //Escala dos eixos xx e yy.
  lxx= gtk_label_new ("\nEscala do xx");
  gtk_container_add (GTK_CONTAINER (BOX2_C), lxx);
  xx=gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, 0.1, 6, 0.25);
  gtk_container_add (GTK_CONTAINER (BOX2_C), xx);
  gtk_scale_set_draw_value (GTK_SCALE(xx), TRUE);
  gtk_range_set_value (GTK_RANGE (xx), 1);

  lyy= gtk_label_new ("\nEscala do yy");
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), lyy);
  yy=gtk_scale_new_with_range (GTK_ORIENTATION_HORIZONTAL, 0.001, 0.2, 0.001);
  gtk_container_add (GTK_CONTAINER (ANOTHERONE), yy);
  gtk_scale_set_draw_value (GTK_SCALE(yy), TRUE);
  gtk_range_set_value (GTK_RANGE (yy), 0.18);

  
  //Botões para controlo do gráfico.
  //Para o x(t)-> Lado esquerdo.
  FG_ESQUERDA=gtk_frame_new ("Controlo do gráfico x(t).");
  gtk_box_pack_start (GTK_BOX (BOX2_C), FG_ESQUERDA, TRUE, TRUE, 25);
  BOX_FG=gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (FG_ESQUERDA), BOX_FG);
  //para o v(t)-> Lado direito.
  FG_DIREITA=gtk_frame_new ("Controlo do gráfico v(t).");
  gtk_box_pack_start (GTK_BOX (ANOTHERONE), FG_DIREITA, TRUE, TRUE, 25);
  BOX_FG2=gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add (GTK_CONTAINER (FG_DIREITA), BOX_FG2);
  //Para o x(t).
  LG_M1= gtk_label_new ("\n\nBloco 1");
  gtk_container_add (GTK_CONTAINER (BOX_FG), LG_M1);
  SWITCH_M1=gtk_switch_new();
  //g_signal_connect(G_OBJECT(SWITCH_M1), "active", G_CALLBACK(BOO),NULL);
  gtk_container_add (GTK_CONTAINER (BOX_FG), SWITCH_M1);
  gtk_switch_set_active (GTK_SWITCH (SWITCH_M1), FALSE);
  LG_M2= gtk_label_new ("\nBloco 2");
  gtk_container_add (GTK_CONTAINER (BOX_FG), LG_M2);
  SWITCH_M2=gtk_switch_new();
  // g_signal_connect(G_OBJECT(SWITCH_M2), "active", G_CALLBACK(BOO),NULL);
  gtk_container_add (GTK_CONTAINER (BOX_FG), SWITCH_M2);
  gtk_switch_set_active (GTK_SWITCH (SWITCH_M2), FALSE);
  //Para o v(t).
  LG_M1_2= gtk_label_new ("\n\nBloco 1");
  gtk_container_add (GTK_CONTAINER (BOX_FG2), LG_M1_2);
  SWITCH_M1_2=gtk_switch_new();
  // g_signal_connect(G_OBJECT(SWITCH_M1_2), "active", G_CALLBACK(BOO),NULL);
  gtk_container_add (GTK_CONTAINER (BOX_FG2), SWITCH_M1_2);
  gtk_switch_set_active (GTK_SWITCH (SWITCH_M1_2), FALSE);
  LG_M2_2= gtk_label_new ("\nBloco 2");
  gtk_container_add (GTK_CONTAINER (BOX_FG2), LG_M2_2);
  SWITCH_M2_2=gtk_switch_new();
  // g_signal_connect(G_OBJECT(SWITCH_M2_2), "active", G_CALLBACK(BOO),NULL);
  gtk_container_add (GTK_CONTAINER (BOX_FG2), SWITCH_M2_2);
  gtk_switch_set_active (GTK_SWITCH (SWITCH_M2_2), FALSE);



  //Frames para os gráficos.
  VBOX_G = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_start (GTK_BOX (BOX1_G), VBOX_G, TRUE, TRUE, 0);
  FRAME_X = gtk_frame_new (NULL);
  GRAPH_X= gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER (FRAME_X), GRAPH_X);
  g_signal_connect (G_OBJECT(GRAPH_X), "draw", G_CALLBACK(graph1), GRAPH_X);
  g_timeout_add (1, (GSourceFunc) time_handler, GRAPH_X);

  FRAME_V = gtk_frame_new (NULL);
  GRAPH_V = gtk_drawing_area_new();
  gtk_container_add(GTK_CONTAINER (FRAME_V), GRAPH_V);
  g_signal_connect (G_OBJECT(GRAPH_V), "draw", G_CALLBACK(graph2), GRAPH_V);
  g_timeout_add (1, (GSourceFunc) time_handler2, GRAPH_V);

  STACK_G= gtk_stack_new ();
  SWITCH_G = gtk_stack_switcher_new ();
  gtk_stack_switcher_set_stack (GTK_STACK_SWITCHER (SWITCH_G), GTK_STACK (STACK_G));
  gtk_box_pack_start (GTK_BOX (VBOX_G), STACK_G, TRUE, TRUE, 0);
  gtk_box_pack_start (GTK_BOX (VBOX_G), SWITCH_G, FALSE, TRUE, 0);
  gtk_widget_set_size_request (SWITCH_G, 800, 30);
  //Sei que os espaços estão bué abusados mas assim ocupa todo o espaço e até fica melhor visualmente.
  gtk_stack_add_titled (GTK_STACK (STACK_G), FRAME_X, "Position." , "                                     Posição em função do tempo: x(t)                                          ");
  gtk_stack_add_titled (GTK_STACK (STACK_G), FRAME_V, "Velocity." , "                                     Velocidade em função do tempo: v(t)                                ");
  gtk_stack_set_visible_child (GTK_STACK(STACK_G), FRAME_X);
  gtk_stack_set_visible_child_name (GTK_STACK(STACK_G), "Position.");
  g_signal_connect(G_OBJECT(GRAPH_V), "draw", G_CALLBACK(scalev), NULL);//good!
  g_signal_connect(G_OBJECT(GRAPH_X), "draw", G_CALLBACK(scalex), NULL);//good!

  TB_BOX = gtk_box_new (GTK_ORIENTATION_VERTICAL, 0);
  gtk_box_pack_start (GTK_BOX (BOXDG), TB_BOX, TRUE, TRUE, 0);
  
  //Toggle button para o gráfico da velocidade em função da posição.
  tbutton = gtk_button_new_with_label("Ativar/Desativar gráfico v(x)");
  gtk_widget_set_size_request(tbutton, 100, 30);
  gtk_box_pack_start(GTK_BOX(TB_BOX), tbutton, TRUE, FALSE, 3);
  //gtk_widget_set_halign(tbutton,GTK_ALIGN_CENTER);
  g_signal_connect(G_OBJECT(tbutton), "clicked", G_CALLBACK(create_other_window3), NULL);

  gtk_stack_set_transition_duration (GTK_STACK(STACK_G), 10);

  gtk_widget_show_all(window);
  gtk_main();

  return(0);
}
