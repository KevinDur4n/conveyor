class Led
{
  private:
  int _pin;
  public:
   
  Led(int pin): _pin(pin) {}
  void twoBlink();
  void fourBlink();
  void on();
  void off();
  void init();
};
