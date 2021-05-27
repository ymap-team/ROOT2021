void func1(){

  TF1 *f1 = new TF1("f1","sin(x)/x", 0, 10);
  f1->Draw();
  
}
