void func4(){

  TF1 *f4 = new TF1("f4","gaus", 0, 10);
  f4->SetParameters(1., 2., 2., 1., -0.1);
  f4->Draw();

}
