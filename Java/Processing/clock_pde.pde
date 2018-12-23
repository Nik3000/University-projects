  float rad = PI/30;
  float rad3 = PI/6;
  
  float x1 = 0;
  float y1 = 0;
  float x2 = 0;
  float y2 = 0;
  float x3 = 0;
  float y3 = 0;
  int r;
  int g;
  int b;
void setup()
{
  
  
  size (700,700);
  //fullScreen();
}
void draw()
{
 
  background (255);
  float x = width/2;
  float y = height/2;
  float l = (height - height/5)/2;
  float l2 = (height - height/3)/2;
  float l3 = (height - height/2)/2; 
  float sW = height/350;
  float mW = height/140;
  float hW = height/70;
  float eW = height/45;
  stroke (#000000);
  strokeWeight (eW);
  ellipse(width/2, height/2, height*0.96, height*0.96);
 
  int s = second();
  x1 = x + l*cos(rad*s - PI/2);
  y1 = y + l*sin(rad*s - PI/2);
  
  
  if ((s >= 0) && (s < 10))
  {
     r = 0;
     g = 100 + s * 15;  //g --> 255
     b = 255;
  }
  else if ((s > 9) && (s < 27))
  {
     s = s - 9;
     r = 0;
     g = 255;
     b = 255 - s * 15;  //b --> 0
  }
  
  else if ((s > 26) && (s < 43))
  {
    s = s - 26; 
    r = 0 + s * 15;  //r --> 255
    g = 255;
    b = 0;
  }
  
  else if ((s > 42) && (s < 60))
  {
    s = s - 42;
    r = 255;
    g = 255 - s * 15;
    b = 0;
  }
  stroke (r,g,b);
  strokeWeight (sW);
  line (x, y, x1, y1);
  
  int m = minute(); 
   
  x2 = x + l2*cos(rad*m - PI/2); // + cos(rad/10*s));
  y2 = y + l2*sin(rad*m - PI/2); // + sin(rad/10*s));
     
  //x2 = x + l2*(cos(rad*m - PI/2) + cos(PI/30/60*s-PI/2));
  //y2 = y + l2*(sin(rad*m - PI/2) + sin(PI/30/60*s-PI/2));
  
      if ((m >= 0) && (m < 10))
  {
     r = 0;
     g = 100 + m * 15;  //g --> 255
     b = 255;
  }
  if ((m > 9) && (m < 27))
  {
     m = m - 10;
     r = 0;
     g = 255;
     b = 255 - m * 15;  //b --> 0
  }
  
  if ((m > 26) && (m < 43))
  {
    m = m - 26; 
    r = 0 + m * 15;  //r --> 255
    g = 255;
    b = 0;
  }
  
  if ((m > 42) && (m < 60))
  {
    m = m - 42;
    r = 255;
    g = 255 - m * 15;
    b = 0;
  }
  
  stroke (r, g, b);
  strokeWeight (mW);
  line (x, y, x2, y2);
  
  int h = hour();
  
  x3 = x + l3*cos(rad3*h - PI/2);
  y3 = y + l3*sin(rad3*h - PI/2);
  
  if ((h >= 0) && (h < 5))
  {
     r = 0;
     g = 40 + h * 40;  //g --> 255
     b = 255;
  }
  if ((h > 5) && (h < 12))
  {
     h = h - 5;
     r = 0;
     g = 255;
     b = 255 - h * 40;  //b --> 0
  }
  
  if ((h > 11) && (h < 17))
  {
    h = h - 11; 
    r = 0 + h * 40;  //r --> 255
    g = 255;
    b = 0;
  }
  
  if ((h > 16) && (h < 24))
  {
    h = h - 16;
    r = 255;
    g = 255 - h * 40;
    b = 0;
  }
  
  stroke (r, g, b);
  strokeWeight (hW);
  line (x, y, x3, y3);
}