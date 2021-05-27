void func3(){

  TF1 *f3 = new TF1("f3","gaus", -5, 5);
  f3->SetParameters(1., 0., 1.);
  f3->Draw();

}
