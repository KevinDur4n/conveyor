
class Motor_DC            //Declaramos la clase Motor_DC
{
  private:
  int _A;
  int _B;
 
  public:
  Motor_DC(int a,int b): _A(a), _B(b){}//Constructor
  void Inicializar_Motor();
  void Adelante();
  void Atras();
  void Stop();
};
