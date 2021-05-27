double myFunc(double *x, double *par) { return sin(x[0]*par[0])*par[1]; }

void func6(){

  TF1 *f6 = new TF1("f6", myFunc, 0, 10, 2);
  f6->SetParameters(2., 5.);
  f6->Draw();

}
