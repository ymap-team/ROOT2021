double myFunc(double x) { return x+sin(x); }

void func5(){

  TF1 *f5 = new TF1("f5", "myFunc(x)", -3, 5);
  f5->Draw();

}
