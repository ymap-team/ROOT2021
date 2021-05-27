void func2(){

  TF1 *f2 = new TF1("f2","sin(x*[0])*[1]", 0, 10);

  f2->SetParameters(2.,5.);
  //func2->SetParameter(0, 2.);
  //func2->SetParameter(1, 5.);
  
  f2->Draw();

}
