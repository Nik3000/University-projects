/*
 Test program developed by Daniel Bataev and Nikita Dultsev in 2017
 Программа рисует так называемое фрактальное дерево. 
 Рисует ствол с определенной толщиной, цветом и координатами.
 Рисует от конца этого ствола линии под определенным углом, цветом и шириной, и
 от каждого конца линии рисует еще такие же линии, но с определенно меньшей длиной 
 и с изменением опреденного угла
 и начиная с определенного момента поменятся цвет линии.
 
 Все параметры которые можно поменять, указаны ниже.
 Для вычисления последующих координат линии использовалась тригонометрия.
 Программа написана на processing .
 Всю документацию на эту библиотеку можно посмотреть на сайте https://processing.org/reference/
*/
float mycos(float x)
{
  x-=2*3*round(x/(2*PI));
  double x2 = x*x;
  x=1;
  double factorial = 2;
  double countFactorial = 2;
  double q = -1;
  double eps = 0.01;
  float sum = 1;
  double lastSum= 0;
  
  while (lastSum - sum > eps || lastSum - sum < eps) 
 {
   lastSum=sum;
   
   x*=x2;
   
   sum+=(q*x)/factorial;
   
   
   countFactorial++;
   factorial*= countFactorial;
   
   countFactorial++;
   factorial*= countFactorial;
   
   q*=-1;
   
   
 }//end while 
 
 return sum;
};

//================================================================================================================================================
float radianLeft = PI/4;//Поворорот линии в радианах на лево от pi/2
float radianRight = PI/6;//Поворорот линии в радианах на право от pi/2
//------------------
final float longColorGreen = 15; // Начиная с какой длины линии начнут рисаовать зеленым цветом
final float longExit = 9; // Длина определяющая прекращеник рисования линии
//------------------
final float changeWidthLine = 0.7; //Изменяет толщину линии в k раз
final float changeLongLine = 0.8; //Изменяет длину линии в k раз
//------------------
float beginWidthLine = 15;//Начальная ширина линии
float beginLongLine = 100; //Начальная длина линии 
//------------------
final color stickColor = #8F6F20;//Цвет "типо" ветки 16-ным числом, или можно задать в RGB "final color stickColor = color(204, 153, 0);" 
final color foliageColor = #349C34;//Цвет "типо" листьев 16-ным числом, или можно задать в RGB "final color stickColor = color(204, 153, 0);"
// В google.com можно выбрать цвет и получить #6FD460 для того чтобы ввести его в программу
// Для этого вставьте #6FD460 в поисковую строку google
//================================================================================================================================================

//счетчик для подсчета кол-во веток
int count = 0;

String str;


float x=100;
float widthTreeY=80;
float w=15;
float h=15;
boolean yN = false;


/*Функция рисует деревffо и принимает следующие аргументы (float x координаты точки к котрой надо нарисовать линию и от которой все линии пойдут дальше
                                                         float y координаты точки к котрой надо нарисовать линию и от которой все линии пойдут дальше
                                                         float l начальная длина ветки
                                                         flaot radL наклон левой ветки в радианах относительно вертекали
                                                         flaot radR наклон правой ветки в радинах относительно вертекали 
                                                         flaot weightLine ширина ветки)
*/

void tree(float x,float y, float l, float rad, float weightLine)
{ 
//------------------
  //подсчитывает кол-во веток
  count++;  
//------------------
  //Вычисления координат для отрисовки линии
  float x1 = x - l*cos(rad);
  float y1 = y - l*sin(rad);
  float x2 = x - l*cos(rad-radianLeft-radianRight);
  float y2 = y - l*sin(rad-radianLeft-radianRight);
//------------------  
//Задания цвета дерева и ширины
  if (l>longColorGreen)
    {stroke(stickColor);}//Начальный цвет дерева в RGB (ветки)
  else {
         stroke(foliageColor);//Конечный цвет дерева в RGB (листья)
         //fill(foliageColor);
         //ellipse(x - (l/2)*cos(rad) ,  y - (l/2)*sin(rad), 5, 2);
         //ellipse(x - (l/2)*cos(rad-radianLeft-radianRight),  y - (l/2)*sin(rad-radianLeft-radianRight), 5, 2);
         //ellipse(x - (l/4)*cos(rad),  y - (l/4)*sin(rad), 5, 2);
         //ellipse(x - (l/4)*cos(rad-radianLeft-radianRight),  y - (l/4)*sin(rad-radianLeft-radianRight), 5, 2);
       }

  strokeWeight(weightLine);
//------------------
  //Отрисовка линий
  line (x, y, x1, y1);
  line (x, y, x2, y2);
//------------------  
  //Рекурсия для отрисовки всех линий
  if (l>longExit)
  {
    tree( x1,  y1,  l*changeLongLine,  rad+radianLeft,   weightLine*changeWidthLine);
    tree( x2,  y2,  l*changeLongLine,  rad-radianRight,  weightLine*changeWidthLine);
  }
//------------------
};


//================================================================================================================================================
void setup()
{
//------------------
 //Размер экрана size(x,y); начало координат от левого верхнего угла окна, соотвецтвенно x и y  положительный. Числовая еденица пиксели.
 //fullScreen();
 size(700,700); 
//------------------
};


//================================================================================================================================================
void draw()
{ 
//------------------
  //создает джвижение дерева
  background(0); //<>//
  radianLeft= (PI)/width * float(mouseX);
  radianRight= (PI)/height * float(mouseY);
//------------------
  //Отрисовка ствола дерева 
  strokeWeight(beginWidthLine);
  stroke(stickColor);//Цвет ствола дерева
  line (width/2, height, width/2, height-beginLongLine);
//------------------
  //пишет в градусах на сколько повернута левая ветка 
  text("left", 0, 20);
  text(degrees((PI)/width * float(mouseX)), 30, 20); //<>//
  
 str= "left " + degrees((PI)/width * float(mouseX));
 text (str, 300, 20);
//------------------
   //пишет в градусах на сколько повернута левая ветка 
  text("right", 0, 35);
  text(degrees((PI)/height * float(mouseY)), 30, 35); //<>//
//------------------
  //выводит на экран высоу начальной палки
  text("long tree", 0, 50);
  text(beginLongLine, 55,50);
//------------------
  //выводит на экран ширину палки
  text("width tree", 0, 65);
  text(beginWidthLine, 60, 65);
  
//------------------
//ScrollBar

//float x=100;
//float widthTreeY=80;
//float w=15;
//float h=15;
  rect(x, widthTreeY, w, h);
  
  
//------------------
  //Рисует дерево
  tree(width/2,  height-beginLongLine,  beginLongLine*changeLongLine,  PI/2+radianLeft,  beginWidthLine);
//------------------
  //выводит в терминал кол-во веток
  text("Count", 200, 50);
  text(count, 250, 50);
  println(count);
//------------------
  //обнуляем счетчик веток
  count=0;
//------------------


};


void mousePressed()
{
  if ((mouseX > x) && (mouseX < x+w) && (mouseY > widthTreeY) && (mouseY < widthTreeY+h))
  {
  yN = true;
  }
};
void mouseDragged()
{
 
  if (yN)
  {
    x=mouseX;
    beginLongLine=mouseX/(width/200);
  }
};


void mouseClicked()
{
yN= false;
};


void keyPressed()
{
//------------------изменяет пропорционально высоту дерева 's'вниз   'w'вверх
 if ((beginLongLine > 1) && (key == 's'))
   {beginLongLine-=1;}
 else if (key == 'w')
        {beginLongLine+=1;}
//------------------изменяет пропорционально ширину дерева 'd' шире    'a' уже
if ((beginWidthLine > 1) && (key == 'a'))
   {beginWidthLine-=1;}
 else if (key == 'd')
        {beginWidthLine+=1;}

};